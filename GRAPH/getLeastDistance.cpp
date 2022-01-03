
/*#include<bits/stdc++.h>
using namespace std;

struct node{
	int a=0;
	node* next=nullptr;
};
struct graph{
	int numVer=0;
	node** adj=nullptr;
	graph(int nVer){
		numVer=nVer;
		adj=new node*[numVer];
		for(int i=0;i<numVer;i++){
			adj[i]=nullptr;
		}
	}
};
void addedge(graph* g ,int source,int destintion){
	node* n=new node;
	n->a=destintion;
	n->next=g->adj[source];
	g->adj[source]=n;
}
void printgraph(graph* g){
	for (int i=0;i<g->numVer;i++){
		node* n=g->adj[i];
		cout<<i<<" : ";
		while(n!=nullptr){
			cout<<n->a<<"-";
			n=n->next;
		}
		cout<<"\b"<<" "<<endl;
	}

}
int getLeastDistance(graph* g ,int start,int end){
	if(start==end)
		return 0;
	queue<int> q;
	q.push(start);
	int count=1;
	int numNodeseachLevel=1;
	bool *visited=new bool [g->numVer];
	for(int i=0;i<g->numVer;i++){
		visited[i]=false;
	}
	visited[start]=true;

	while(!q.empty()){
		int p=q.front();
		q.pop();
		numNodeseachLevel-=1;
		node* n=g->adj[p];
		
		while(n!=nullptr){
			if(n->a==end)
				return count;
			if(visited[n->a]==false){
				visited[n->a]=true;
				q.push(n->a);
			}
			n=n->next;
		}
		if (numNodeseachLevel == 0) {
			count++;
			numNodeseachLevel = q.size();
		}
	}
	return -1;
}
int main(){
	graph* g=new graph(9);
	addedge(g, 0, 1);
	addedge(g, 0, 7);
	addedge(g, 0, 8);
	addedge(g, 1, 8);
	addedge(g, 2, 8);
	addedge(g, 2, 4);
	addedge(g, 3, 2);
	addedge(g, 5, 8);
	addedge(g, 5, 3);
	addedge(g, 5, 4);
	addedge(g, 6, 5);
	addedge(g, 7, 6);
	addedge(g, 7, 5);
	addedge(g, 8, 3);
	//printgraph(g);
	int source=0;
	int destintion=4;
	int x=getLeastDistance(g,source,destintion);
	if(x!=-1)
		cout<<"distance between "<<source<<" to "<<destintion<<" is : "<<x;
	else
		cout<<"node invalid ";
}

*/
#include<iostream>
#include<queue>
using namespace std;

struct node {
	int a = 0;
	node* next = nullptr;
};
struct graph {
	int numVertex = 0;
	node** adj = nullptr;
	graph(int numV) {
		numVertex = numV;
		adj = new node * [numVertex];
		for (int i = 0; i < numVertex; ++i) {
			adj[i] = nullptr;
		}
	}
};
void addedge(graph* g ,int source,int destintion){
	node* n=new node;
	n->a=destintion;
	n->next=g->adj[source];
	g->adj[source]=n;
}

int dis[100];
int getLeastDistance(graph* g ,int start,int end){
	dis[start]=0;
	queue<int> q;
	q.push(start);
	
	int numNodeseachLevel=1;
	bool *visited=new bool [g->numVertex];
	for(int i=0;i<g->numVertex;i++){
		visited[i]=false;
	}
	visited[start]=true;

	while(!q.empty()){
		int p=q.front();
		q.pop();
		numNodeseachLevel-=1;
		node* n=g->adj[p];
		
		while(n!=nullptr){
				
			if(visited[n->a]==false){
				visited[n->a]=true;
				if(start==end)
					goto j;
				dis[n->a]=dis[p]+1;
				q.push(n->a);
			}

			n=n->next;
		}
		
	}
	
	j:
		return dis[end];

}
int main(){
	graph* g=new graph(9);
	addedge(g, 0, 1);
	addedge(g, 0, 7);
	addedge(g, 0, 8);
	addedge(g, 1, 8);
	addedge(g, 2, 8);
	addedge(g, 2, 4);
	addedge(g, 3, 2);
	addedge(g, 5, 8);
	addedge(g, 5, 3);
	addedge(g, 5, 4);
	addedge(g, 6, 5);
	addedge(g, 7, 6);
	addedge(g, 7, 5);
	addedge(g, 8, 3);
	cout<<getLeastDistance(g,3,4);
	
}
