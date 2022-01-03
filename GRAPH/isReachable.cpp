#include<bits/stdc++.h>
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
			cout<<n->a<<" -> ";
			n=n->next;
		}
		cout<<endl;
	}

}
bool isReachable(graph* g ,int src,int dest){
	if(dest==src)
		return true;
	queue<int> q;
	q.push(src);
	bool *visited=new bool [g->numVer];
	for(int i=0;i<g->numVer;i++){
		visited[i]=false;
	}
	visited[src]=true;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		node* n=g->adj[p];
		while(n!=nullptr){
			if(n->a==dest)
				return true;
			if(visited[n->a]==false){
				visited[n->a]=true;
				q.push(n->a);
			}
			n=n->next;
		}
	}
	return false;
}
int main(){
	graph* g=new graph(10);
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
	//printgraph(g);cout<<endl;
	int source=7;
	int destintion=2;
	cout<<source<<" to "<<destintion<<" isReachable ? ";
	isReachable(g,source,destintion)? cout<<"true":cout<<"false";
}