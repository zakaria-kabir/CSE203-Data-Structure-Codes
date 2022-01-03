/*
#include<bits/stdc++.h>
using namespace std;

struct node{
	int a=0;
	node* next=nullptr;
};
struct graph{
	int numVer=0;
	node** adj=nullptr;	
	int verArr[100][100];
	graph(int nVer){
		numVer=nVer;
		adj=new node*[numVer];
		for(int i=0;i<numVer;i++){
			adj[i]=nullptr;
		}
	}
	
};
void addedge(graph* g ,int source,int data){
	node* n=new node;
	n->a=data;
	n->next=g->adj[source];
	g->adj[source]=n;
}

void printAdjacencyList(graph* g){
	for (int i=0;i<g->numVer;i++){
		node* n=g->adj[i];
		cout<<i<<" :  ";
		while(n!=nullptr){
			cout<<n->a<<"->";
			n=n->next;
		}
		cout<<"\b\b"<<"  "<<endl;
	}

}
void addedgeMatrix(graph *g,int x,int z){
	g->verArr[x][z]=1;

}
void printAdjacencyMatrix(graph* g){
	cout<<setw(6);
	for(int i=0;i<g->numVer;i++){
		cout<<i<<"  ";
	}cout<<"\n\n";
	for(int i=0;i<g->numVer;i++){	
		cout<<i<<" :  ";
		for(int j=0;j<g->numVer;j++){
			cout<<g->verArr[i][j]<<"  ";
		}
		cout<<endl;
	}

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
	cout<<"Adjacency List :\n\n";
	printAdjacencyList(g);
	cout<<"\nAdjacency Matrix :\n";
	

		addedgeMatrix(g, 0, 1);
	addedgeMatrix(g, 0, 7);
	addedgeMatrix(g, 0, 8);
	addedgeMatrix(g, 1, 8);
	addedgeMatrix(g, 2, 8);
	addedgeMatrix(g, 2, 4);
	addedgeMatrix(g, 3, 2);
	addedgeMatrix(g, 5, 8);
	addedgeMatrix(g, 5, 3);
	addedgeMatrix(g, 5, 4);
	addedgeMatrix(g, 6, 5);
	addedgeMatrix(g, 7, 6);
	addedgeMatrix(g, 7, 5);
	addedgeMatrix(g, 8, 3);

	printAdjacencyMatrix(g);

}
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
	int a=0;
	node* next=nullptr;
};
struct graph{
	int numVer=0;
	node** adj=nullptr;	
	int **verArr=new int*[numVer];
	graph(int nVer){
		numVer=nVer;
		adj=new node*[numVer];
		for(int i=0;i<numVer;i++){
			adj[i]=nullptr;
			verArr[i]=new int[numVer];		
		}
		for(int i=0;i<numVer;i++){
			for(int j=0;j<numVer;j++){
				verArr[i][j]=0;
			}
		}

	}
	
};
void addedge(graph* g ,int source,int data){
	node* n=new node;
	n->a=data;
	n->next=g->adj[source];
	g->adj[source]=n;
}

void printAdjacencyList(graph* g){
	for (int i=0;i<g->numVer;i++){
		node* n=g->adj[i];
		cout<<i<<" :  ";
		while(n!=nullptr){
			cout<<n->a<<"->";
			n=n->next;
		}
		cout<<"\b\b"<<"  "<<endl;
	}

}
void addedgeMatrix(graph *g,int x,int z){
	g->verArr[x][z]=1;

}
void printAdjacencyMatrix(graph* g){
	cout<<setw(6);
	for(int i=0;i<g->numVer;i++){
		cout<<i<<"  ";
	}cout<<"\n\n";
	for(int i=0;i<g->numVer;i++){	
		cout<<i<<" :  ";
		for(int j=0;j<g->numVer;j++){
			cout<<g->verArr[i][j]<<"  ";
		}
		cout<<endl;
	}
	//deleteing array
	for(int i=0;i<g->numVer;i++){
		delete g->verArr[i];
	}
	delete g->verArr;

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
	cout<<"Adjacency List :\n\n";
	printAdjacencyList(g);
	cout<<"\nAdjacency Matrix :\n";
	

	addedgeMatrix(g, 0, 1);
	addedgeMatrix(g, 0, 7);
	addedgeMatrix(g, 0, 8);
	addedgeMatrix(g, 1, 8);
	addedgeMatrix(g, 2, 8);
	addedgeMatrix(g, 2, 4);
	addedgeMatrix(g, 3, 2);
	addedgeMatrix(g, 5, 8);
	addedgeMatrix(g, 5, 3);
	addedgeMatrix(g, 5, 4);
	addedgeMatrix(g, 6, 5);
	addedgeMatrix(g, 7, 6);
	addedgeMatrix(g, 7, 5);
	addedgeMatrix(g, 8, 3);

	printAdjacencyMatrix(g);

}