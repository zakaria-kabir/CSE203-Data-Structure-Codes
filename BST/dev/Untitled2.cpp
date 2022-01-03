#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct node {
	int a = 0;
	node* next = NULL;
};
struct graph {
	int numVertex = 0;
	node** adj = NULL;
	graph(int numV) {
		numVertex = numV;
		adj = new node * [numVertex];
		for (int i = 0; i < numVertex; ++i) {
			adj[i] = NULL;
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
void printGraph(graph* g) {
	for (int i = 0; i < g->numVertex; ++i) {
		node* n = g->adj[i];
		cout << i << " ";
		while (n != NULL) {
			cout << n->a << " ";
			n = n->next;
		}
		cout << endl;
	}
}
void dfs_1(graph* g, int start) {
	stack<int> st;
	st.push(start);

	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	visited[start] = true;


	while (!st.empty()) {
		int p = st.top();
		st.pop();
		cout<<p<<" ";
		node* n = g->adj[p];
		while (n != NULL) {
			if (visited[n->a] == false) {
				visited[n->a] = true;
				st.push(n->a);
			}
			n = n->next;
		}
	cout<<endl;
	}

}

int main() {
	graph* g = new graph(9);
		addEdge(g, 0, 7);
	addEdge(g, 0, 1);
	addEdge(g, 0, 8);
	addEdge(g, 1, 8);
	addEdge(g, 2, 8);
	addEdge(g, 2, 4);
	addEdge(g, 3, 2);
	addEdge(g, 5, 8);
	addEdge(g, 5, 3);
	addEdge(g, 5, 4);
	addEdge(g, 6, 5);
	addEdge(g, 7, 6);
	addEdge(g, 7, 5);
	addEdge(g, 8, 3);

	//printGraph(g);
	//bfs(g, 0);
	dfs_1(g,0);
	//dfs(g, 0,8);
}
