#include<iostream>
#include "xyz.cpp"
using namespace std;

class Prims{
	
	int graph[10][10];
	bool *visited;
	int *parent;
	int v;
	
	Heap H;
	
	public:
		Prims(int v){
			this->v = v;
		}
		
		void input();
		void prims_algo();	
};

void Prims :: input()
{
	int weight, source;
	
	H.init(v);
	
	parent = new int[v+1];
	visited = new bool[v+1];
	
	cout<<"\n Enter the weight between edges, enter 0 if there is no linking \n";
	
	for(int i=1;i<=v;i++){
		
		visited[i]=false;
		
		for(int j=1;j<=v;j++){
			
			if(i<j){
				
				cout<<" Weight between ("<<i<<"---"<<j<<") : ";
				cin>>weight;
				
				if(weight){
					
					graph[i][j]=weight;
					graph[j][i]=weight;
				}
				
				else{
					
					graph[i][j]=0;
					graph[j][i]=0;
				}
			}
			
			if(i==j)
				graph[i][j]=0;
		}
	}
	
	prims_algo();
}

void Prims :: prims_algo(){
	
	int ctr = 0;
	H.max_heap_insert(S[1].key,1);
	
	parent[S[1].vertex]=-1;
	
	while(!H.isEmpty()){
		
		int x = H.heap_extract_max();
		
		if(ctr>0 && visited[x]==false){
			
			cout<<parent[x]<<"---"<<x<<" : "<<graph[parent[x]][x]<<endl;
		}
		
		ctr++;
		visited[x] = true;
		
		for(int j=1;j<=v;j++){
			
			if(graph[x][j] && visited[j]==false && S[j].key>graph[x][j]){
				
				S[j].key=graph[x][j];
				
				H.max_heap_insert(S[j].key,j);
				
				parent[j]=x;
			}
		}
	}
}

int main()
{
	int v;
	
	cout<<"\nEnter the number of vertices: ";
	cin>>v;
	
	Prims ob(v);
	
	ob.input();
	
	return 0;
}
