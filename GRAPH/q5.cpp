#include <bits/stdc++.h>
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

void addEdge(graph* g, int src, int dest) {
	//Directed graphs
	node* n = new node;
	n->a = dest;
	n->next = g->adj[src];//src is anything between 0-5
	g->adj[src] = n;
}
void printgraph(graph* g){
	for (int i=0;i<g->numVertex;i++){
		node* n=g->adj[i];
		cout<<i<<" : ";
		while(n!=nullptr){
			cout<<n->a<<"-";
			n=n->next;
		}
		cout<<"\b"<<" "<<endl;
	}

}
void printq(queue<int> q) 
{ 
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}cout<<endl;
} 



void dfsHelper(graph* g, int start,int end, bool*& visited,int *arr, int index,queue<int>& q) {
	visited[start] = true;
	arr[index] = start; 
	index = index + 1;
	if (start == end) {
		q.push(index-1);
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			dfsHelper(g, n->a, end, visited, arr, index,q);
		}
		n = n->next;
	}
	visited[start] = false;
}

float avgDistDFS(graph* g, int start, int end) {
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0;
	queue<int>q;
	float avg=0;
	float sum=0;
	dfsHelper(g, start,end , visited, arr, index,q);
	printq(q);
	int sz=q.size();
	while(!q.empty()){
		sum+=q.front();
		q.pop();
	}
	avg=sum/sz;
	return avg;

}
int main() {
	graph* g = new graph(8);
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 0, 3);
	addEdge(g, 0, 4);
	addEdge(g, 1, 2);
	addEdge(g, 3, 6);
	addEdge(g, 5, 0);
	addEdge(g, 5, 2);
	addEdge(g, 5, 3);
	addEdge(g, 6, 4);
	addEdge(g, 6, 7);
	addEdge(g, 7, 2);
	addEdge(g, 7, 4);
	addEdge(g, 7, 5);
	cout<<avgDistDFS(g, 5,4);
}

/*
#include <bits/stdc++.h>
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

void addEdge(graph* g, int src, int dest) {
	//Directed graphs
	node* n = new node;
	n->a = dest;
	n->next = g->adj[src];//src is anything between 0-5
	g->adj[src] = n;
}
void printgraph(graph* g){
	for (int i=0;i<g->numVertex;i++){
		node* n=g->adj[i];
		cout<<i<<" : ";
		while(n!=nullptr){
			cout<<n->a<<"-";
			n=n->next;
		}
		cout<<"\b"<<" "<<endl;
	}

}


void avgDistDFShelp(graph* g, int start,int end, bool*& visited,int *arr, int index,int*& ar,int &i) {
	visited[start] = true;
	arr[index] = start; 
	index = index + 1;
	if (start == end) {
		ar[i]=index-1;
		//cout<<ar[i]<<endl;
		i++;
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			avgDistDFShelp(g, n->a, end, visited, arr, index,ar,i);
		}
		n = n->next;
	}
	visited[start] = false;
}

float avgDistDFS(graph* g, int start, int end) {
	float avg=0;
	float sum=0;
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0;
	int *ar=new int[g->numVertex];
	int i=0;
	
	avgDistDFShelp(g, start,end , visited, arr, index,ar,i);
	for(int j=0;j<i;j++){
		sum=sum+ar[j];
	}
	avg=sum/i;
	return avg;

}
int main() {
	graph* g = new graph(8);
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 0, 3);
	addEdge(g, 0, 4);
	addEdge(g, 1, 2);
	addEdge(g, 3, 6);
	addEdge(g, 5, 0);
	addEdge(g, 5, 2);
	addEdge(g, 5, 3);
	addEdge(g, 6, 4);
	addEdge(g, 6, 7);
	addEdge(g, 7, 2);
	addEdge(g, 7, 4);
	addEdge(g, 7, 5);

	cout<<avgDistDFS(g, 0,4);
}
*/