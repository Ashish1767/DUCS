#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
//#include "MST_graph.h"
//#include "MinHeap.h"
using namespace std;

class Edge
{
	public:
		int src;
		int des;
		int weight;
};

class subset
{
	public:
	int parent;
	int rank;
};
// Structure for the Graph and MSTList
struct MSTListNode 
{
	int dest;
	int weight;
	struct MSTListNode* next;
};


struct MSTList 
{
	struct MSTListNode* head; 
};


struct Graph {
	int V;
	struct MSTList* array;
};


//Structure for Min-Heap

struct MinHeapNode 
{
	
	int v;
	int key;
	
	
};


struct MinHeap 
{
	
	int size; // Number of heap nodes present currently
	int capacity; // Capacity of min heap
	int* pos; // This is needed for decreaseKey()
	struct MinHeapNode** array;
	
	
};
class MST
{
	int V;
	int E;
	Graph *g;
//	MST q1;
	Edge* edge;
	MST* G;					
	MST* A;	
	//MST a1;
	public:
		
 		//Krushkal's Algo
		void getdata1();
		void sorting();
	 	void swap(Edge&,Edge&);
		MST* createMST(int,int);
		int display(MST*);
		int find(subset*,int);
		void Union(subset *A,int x,int y);
		void Kruskal();
		
		//Prim's Algo
		void getdata2();
		void prims();
		
			//Create Graph
		Graph* createGraph(int);
		MSTListNode* newNode(int,int);
		void addEdge(Graph*,int,int,int);
		void displayGraph(Graph*);
		int findweight(Graph*,int,int); 
	
		//MinHeap functions
		MinHeapNode* newHeapNode(int,int);
		MinHeap* createMinHeap(int);
		void swap(MinHeapNode**,MinHeapNode**);
		void MinHeapify(MinHeap*,int);
		MinHeapNode* extractMin(MinHeap*);
		void decreaseKey(MinHeap*,int,int);
		bool isInMinHeap(MinHeap*,int);
		
		
		
};
//Krishkal's Algo

MST* MST::createMST(int v,int e)
{
	MST *temp=new MST;
	temp->V=v;
	temp->E=e;
	
	temp->edge=new Edge[E];	
	return temp;
}

void MST::getdata1()
{
	
	cout<<"\nNo.of vertices:-";
	cin>>V;
	cout<<"\nNo of edges:-";
	cin>>E;
	G=createMST(V,E);
	
	int s,d,w;
	
	for(int i=0;i<E;++i)
		{
			cout<<"\n\nDetails for Edge "<<i<<": ";
			cout<<"\nSource:-";
			cin>>s;
			cout<<"\nDestination:-";
			cin>>d;
			cout<<"\nWeight:-";
			cin>>w;
			G->edge[i].src=s;
			G->edge[i].des=d;
			G->edge[i].weight=w;
			
		}
		
		//Display the graph
		cout<<"\n\nTotal cost of the graph:-"<<display(G);
}

void MST::sorting()
{
		for (int i = 0,j,least; i < E-1; i++)
		 {
					for (j = i+1, least = i; j < E; j++)
							if (G->edge[j].weight < G->edge[least].weight)
							least = j;
							
			        		swap(G->edge[least],G->edge[i]);
			}
}

void MST::swap(Edge& a,Edge& b)
{
	Edge temp=a;
	a=b;
	b=temp;
}

int MST::display(MST* a)
{
	int cost=0;
	cout<<"Source\t\tDestination\tWeight\n";
	for(int i=0;i<a->E;++i)
	{
		cout<<a->edge[i].src<<"\t\t"<<a->edge[i].des<<"\t\t"<<a->edge[i].weight<<"\n";
		cost+=a->edge[i].weight;
	}
	
		return cost;
}

int MST::find(subset *A,int i)
{
	if(A[i].parent!=i)							
		A[i].parent=find(A,A[i].parent);
		
	return A[i].parent;
}

void MST::Union(subset *A,int x,int y)
{
	int xroot=find(A,x);
	int yroot=find(A,y);
	
	if(A[xroot].rank<A[yroot].rank)
		A[xroot].parent=yroot;	
	
	else if(A[xroot].rank>A[yroot].rank)
		A[yroot].parent=xroot;
		
	else
	{
		A[yroot].parent=xroot;
		A[xroot].rank++;
	}
}

void MST::Kruskal()
{
	int v=G->V;
	
	A=createMST(v,v-1);				//MST consist V vertices and V-1 edges
	int e=0;
	int i=0;

	
	subset *s=new subset[(v* sizeof(subset))];
	
	//Sorting the edges acc. to their weight
	sorting();
	
	for(int j=0;j<v;++j)
	{
		s[j].parent=j;
		s[j].rank=0;
	}
	
	while(e<v-1 && G->E)
	{
		
		Edge next_edge=G->edge[i++];
		int x=find(s,next_edge.src);
		int y=find(s,next_edge.des);
		
		if(x!=y)					
		{
			A->edge[e++]=next_edge;
		
			Union(s,x,y);
		}
		
	}
	cout << "\n\n\nFollowing are the edges in the constructed MST\n\n";
            cout<<"\n\nTotal cost of MST:-"<<display(A);
}


Graph* MST::createGraph(int v)
{
	Graph *temp=new Graph;
	temp->V=v;
	temp->array=new MSTList[v];
	
	for(int i=0;i<v;++i)
		temp->array[i].head=NULL;
		
	return temp;
		
}


MSTListNode* MST::newNode(int d,int w)
{
	MSTListNode *temp=new MSTListNode;
	temp->dest=d;
	temp->weight=w;
	temp->next=NULL;
	
	return temp;
}

void MST::addEdge(Graph *g,int s,int d,int w)
{
	MSTListNode* n=new MSTListNode;
	n=newNode(d,w);
	
	MSTListNode *temp=new MSTListNode;
	
	if(g->array[s].head!=NULL)
	{
		temp=g->array[s].head;
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=n;
	}
	
	else
		g->array[s].head=n;

}

void MST::displayGraph(Graph* g)
{
		
	 MSTListNode* temp = new MSTListNode;
 	cout<<"\n\nSource\tDestination(Weight)\n";
	for(int i=0; i<g->V;i++)
	{
		
		 
 		cout<<"\n "<<i;
		temp = g->array[i].head;
		while (temp != NULL)
		{
			cout<<"->\t"<<temp->dest<<"("<<temp->weight<<")";
			temp = temp->next;
			
		}
	}
	
}

int MST::findweight(Graph *g,int s,int d)
{
	MSTListNode *temp=g->array[s].head;
	
	while(temp->dest!=d)
		temp=temp->next;
		
	return temp->weight;
}

//Min heap functions

MinHeapNode* MST::newHeapNode(int v,int k)
{
	MinHeapNode* temp=new MinHeapNode;
	temp->v=v;
	temp->key=k;
	
	return temp;
}

MinHeap* MST::createMinHeap(int cap)
{
	MinHeap* temp=new MinHeap;
	temp->size=0;
	temp->capacity=cap;
	temp->pos=new int[cap];
	temp->array = (struct MinHeapNode**)malloc(cap * sizeof(struct MinHeapNode*));
}

void MST::swap(MinHeapNode** a,MinHeapNode** b)
{
	MinHeapNode *t=*a;
	*a=*b;
	*b=t;
}

void MST::MinHeapify(struct MinHeap* m, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < m->size && m->array[left]->key < m->array[smallest]->key)
		smallest = left;

	if (right < m->size && m->array[right]->key < m->array[smallest]->key)
		smallest = right;

	if (smallest != idx) {
		// The nodes to be swapped in min heap
		MinHeapNode* smallestNode = m->array[smallest];
		MinHeapNode* idxNode = m->array[idx];

		// Swap positions
		m->pos[smallestNode->v] = idx;
		m->pos[idxNode->v] = smallest;

		// Swap nodes
		swap(&m->array[smallest], &m->array[idx]);

		MinHeapify(m, smallest);
	}
}

 MinHeapNode* MST::extractMin(MinHeap* m)
{
	if (m->size==0)
		return NULL;

	// Store the root node
	struct MinHeapNode* root = m->array[0];

	// Replace root node with last node
	struct MinHeapNode* lastNode = m->array[m->size - 1];
	m->array[0] = lastNode;

	// Update position of last node
	m->pos[root->v] = m->size - 1;
	m->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--m->size;
	MinHeapify(m, 0);

	return root;
}

// Function to decrease key value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void MST::decreaseKey(struct MinHeap* m, int v, int key)
{
	// Get the index of v in heap array
	int i = m->pos[v];

	// Get the node and update its key value
	m->array[i]->key = key;

	// Travel up while the complete tree is not hepified.
	// This is a O(Logn) loop
	while (i && m->array[i]->key < m->array[(i - 1) / 2]->key) {
		// Swap this node with its parent
		m->pos[m->array[i]->v] = (i - 1) / 2;
		m->pos[m->array[(i - 1) / 2]->v] = i;
		swap(&m->array[i], &m->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool MST::isInMinHeap(struct MinHeap* m, int v)
{
	if (m->pos[v] < m->size)
		return true;
	return false;
}

//Prim's Algo
void MST::getdata2()
{
	int cost=0;
	cout<<"\nNo of Vertices:-";
	cin>>V;
	cout<<"\nNo of Edges:-";
	cin>>E;
	g=new Graph;
	g=createGraph(V);
	
	int s,d,w;
	for(int i=0;i<E;++i)
	{
		cout<<"\nDetails for Edge "<<i<<": ";
			cout<<"\nSource: ";
			cin>>s;
			cout<<"\nDestination: ";
			cin>>d;
			cout<<"\nWeight: ";
			cin>>w;
			cost+=w;
			addEdge(g,s,d,w);
			addEdge(g,d,s,w);
	}
	
	//Display the graph
	displayGraph(g);
	cout<<"\n\nTotal cost:-"<<cost;
}

void MST::prims()
{
	int V = g->V; // Get the number of vertices in graph
	int parent[V]; // Array to store constructed MST
	int key[V]; // Key values used to pick minimum weight edge in cut
	int w[V];
	int e=1;
	int cost=0;
	// minHeap represents set E
	struct MinHeap* m = createMinHeap(V);

	// Initialize min heap with all vertices. Key value of
	// all vertices (except 0th vertex) is initially infinite
	for (int i = 1; i < V; ++i) 
	{
		parent[i] = -1;
		key[i] = INT_MAX;
		m->array[i] = newHeapNode(i, key[i]);
		m->pos[i] = i;
	}

	// Make key value of 0th vertex as 0 so that it
	// is extracted first
	key[0] = 0;
	m->array[0] = newHeapNode(0, key[0]);
	m->pos[0] = 0;

	// Initially size of min heap is equal to V
	m->size = V;

	// In the following loop, min heap contains all nodes
	// not yet added to MST.
	while (m->size!=0) {
		// Extract the vertex with minimum key value
		struct MinHeapNode* minHeapNode = extractMin(m);
		int u = minHeapNode->v; // Store the extracted vertex number

		// Traverse through all MSTacent vertices of u (the extracted
		// vertex) and update their key values
		struct MSTListNode* pCrawl = g->array[u].head;
		while (pCrawl != NULL) {
			int v = pCrawl->dest;

			// If v is not yet included in MST and weight of u-v is
			// less than key value of v, then update key value and
			// parent of v
			if (isInMinHeap(m, v) && pCrawl->weight < key[v]) {
				key[v] = pCrawl->weight;
				parent[v] = u;
				decreaseKey(m, v, key[v]);
			}
			pCrawl = pCrawl->next;
		}
	}
	cout << "\n\n\nFollowing are the edges in the constructed MST\n\n";
	for (int i = 1; i < V; ++i)
	{
		w[e++]=findweight(g,parent[i],i);
		cout<<parent[i]<<" -- "<<i<<" = "<<w[i]<<"\n";
		cost+=w[i];
	}
	
	cout<<"\n\nTotal cost of MST:-"<<cost;
}



int main()
{
		int choice;
		MST m1;
		cout<<"\nMinimum Spanning Tree:-";
		cout<<"\n\n1.Kruskal's Algorithm";
		cout<<"\n2.Prim's Algorithm";
		cout<<"\n\nEnter your choice:-";
		cin>>choice;
		if(choice==1)
		{
			m1.getdata1();
			m1.Kruskal();
		}
		else
		{
			m1.getdata2();
			m1.prims();
		}
		
	getch();
	return 0;
}
