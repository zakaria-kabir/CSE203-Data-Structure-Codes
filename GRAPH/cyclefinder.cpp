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
void printq(queue<int> q) 
{ 
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	cout<<endl;
} 

void dfsHelper(graph* g, int x,int start,int end, bool*& visited,int *arr, int index,int &count,bool &flag,queue<int>&q,queue<int>&q1) {
	visited[start] = true;
	visited[x] = false;
	flag=false;
	//cout << start << " ";
	arr[index] = start; 
	index = index + 1;
	if (start == end&&index>1) {
		q1.push(index);
		for(int i=0;i<index;i++){
			q.push(arr[i]);
		}
		count++;
		flag=true;
		
	}
	else if(start==end&&index<=1){
		flag=false;
	}


	node* n = g->adj[start];

	while (n != nullptr) {
		if (!visited[n->a]) {
			dfsHelper(g,x, n->a, end, visited, arr, index,count,flag,q,q1);
		}

		n = n->next;
	}
	visited[start] = false;
}

void dfs(graph* g) {
	bool flag=false;
	queue<int>q,q1;
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0;
	int count=0;
	for (int i = 0; i < g->numVertex; ++i) {
		int x=i;
		dfsHelper(g, x,i,i , visited, arr, index,count,flag,q,q1);

	}
	cout<<"total cycle :"<<count<<endl;
	for(int j=0;j<count;j++){
		for(int i=0;i<q1.front();i++){
			cout<<q.front()<<" ";
			q.pop();
			
		}
		cout<<endl;
		q1.pop();
	}
}
int main() {
	graph* g = new graph(9);
	addEdge(g, 0, 1);
	addEdge(g, 0, 7);
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
	dfs(g);
}


/*



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


void dfsHelper(graph* g, int x,int start,int end, bool*& visited,int *arr, int index,int &count,bool &flag) {
	visited[start] = true;
	visited[x] = false;
	flag=false;
	//cout << start << " ";
	arr[index] = start; 
	index = index + 1;
	if (start == end&&index>1) {
		count++;
		flag=true;
			cout<<flag<<endl;
		//printArray(arr, index);
	}
	else if(start==end&&index<=1){
		flag=false;
			cout<<flag<<endl;
	}


	node* n = g->adj[start];

	while (n != nullptr) {
		if (!visited[n->a]) {
			dfsHelper(g,x, n->a, end, visited, arr, index,count,flag);
		}

		n = n->next;
	}
	visited[start] = false;
}

void dfs(graph* g) {
	bool flag=false;
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0;
	int count=0;
	for (int i = 0; i < g->numVertex; ++i) {
		int x=i;
	dfsHelper(g, x,i,i , visited, arr, index,count,flag);

	}
	cout<<"total cycle :"<<count<<endl;

}
int main() {
	graph* g = new graph(9);
	addEdge(g, 0, 1);
	addEdge(g, 0, 7);
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
	dfs(g);
}

*/