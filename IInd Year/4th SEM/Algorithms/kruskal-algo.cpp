#include <bits/stdc++.h>
using namespace std;


class DSU {
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}
	
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class edge{
    public:
    int src,dest,weight;

};

class graph{
    public:
    int v,e;
    edge* E;
    void kruskals_mst()
	{

        for(int i=0;i<this->e;i++) {
            for(int j=0;j<(this->e)-i-1;j++) {
                if(this->E[j].weight>this->E[j+1].weight)
                    swap(this->E[j],this->E[j+1]);
            }
        }

		DSU s(this->v);
		int ans = 0;
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl;
		for (int i=0;i<this->e;i++) {
			int w = this->E[i].weight;
			int x = this->E[i].src;
			int y = this->E[i].dest;

			
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w
					<< endl;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans;
	}
    

};

graph* creategraph(){
    graph* g = new graph();

    cout<<endl<<"Enter number of vertices: ";
    cin>>g->v;
    cout<<endl<<"Enter number of edges: ";
    cin>>g->e;
     g->E = new edge[g->e * sizeof(edge)];

     return g;

}

int main(){

      graph* g = creategraph();

 for(int i=0;i<g->e;i++) {
     cout<<"\nEnter source for edge "<<i+1<<": ";
     cin>>g->E[i].src;
     cout<<"\nEnter destination for edge "<<i+1<<": ";
     cin>>g->E[i].dest;
      cout<<"\nEnter weight for edge "<<i+1<<": ";
     cin>>g->E[i].weight;
     
 }
 g->kruskals_mst();

    return 0;

}
