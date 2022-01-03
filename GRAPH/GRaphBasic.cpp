#include <iostream>
#include <queue>
#include <stack>
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
void printGraph(graph* g) {
	for (int i = 0; i < g->numVertex; ++i) {
		node* n = g->adj[i];
		cout << i << " ";
		while (n != nullptr) {
			cout << n->a << " ";
			n = n->next;
		}
		cout << endl;
	}
}
void bfs(graph* g, int start) {
	queue<int> q;
	q.push(start);
	int numNodesEachLevel = 1;
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	visited[start] = true;


	while (!q.empty()) {
		int p = q.front();
		q.pop();
		numNodesEachLevel -= 1;
		cout << p << " ";

		node* n = g->adj[p];
		while (n != nullptr) {
			if (visited[n->a] == false) {
				visited[n->a] = true;
				q.push(n->a);
			}
			n = n->next;
		}
		if (numNodesEachLevel == 0) {
			numNodesEachLevel = q.size();
			cout << endl;
		}
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

		cout << p << " ";

		node* n = g->adj[p];
		while (n != nullptr) {
			if (visited[n->a] == false) {
				visited[n->a] = true;
				st.push(n->a);
			}
			n = n->next;
		}

	}
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void dfsHelper(graph* g, int start,int end, bool*& visited,int *arr, int index) {
	visited[start] = true;
	//cout << start << " ";
	arr[index] = start; 
	index = index + 1;
	if (start == end) {
		printArray(arr, index);
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			dfsHelper(g, n->a, end, visited, arr, index);
		}
		n = n->next;
	}
	visited[start] = false;
}

void dfs(graph* g, int start, int end) {
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0;
	dfsHelper(g, start,end , visited, arr, index);
}
int main() {
	graph* g = new graph(9);
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

	//printGraph(g);
	//bfs(g, 0);
	//dfs_1(g,0);
	dfs(g, 5,4);
}