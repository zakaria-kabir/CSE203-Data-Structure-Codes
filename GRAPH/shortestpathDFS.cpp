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
void printarr(int* arr,int n,int x){
	for(int i=n;i<n+x;i++){
		cout<<arr[i]<<" ";
	}

}
void minimum(queue<int> &q, queue<int>&qu)
{
	if (!q.empty()) {

		int min = INT_MAX;
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			int a = q.front();
			q.pop();
			if (a <= min )
			{

				min = a;

			}
			q.push(a);
		}
		for (int i = 0; i < sz; i++) {
			int x = q.front();
			if (x == min) {
				qu.push(x);
				q.pop();
			}
			else {
				q.pop();
				q.push(x);
			}

		} minimum(q, qu);
	}

}
void sortQ(queue<int> &q) {
	queue<int>qu;

	minimum(q, qu);
	while (!qu.empty()) {
		q.push(qu.front());
		qu.pop();
	}

}
void dfsHelper(graph* g, int start,int end, bool*& visited, int index,int& min,queue<int> q,int *&arr,int& count,int &i,queue<int>&q1) {
	visited[start] = true;
	q.push(start);
	index = index + 1;
	if (start == end) {
	//	printq(q);
		q1.push(index);
		count++;
		while(!q.empty()){
			arr[i]=q.front();
			q.pop();
			i++;
		}
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			dfsHelper(g, n->a, end, visited, index,min,q,arr,count,i,q1);
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
	queue<int>q;	
int* arr=new int[100];
int count=0;
	int index = 0;
	int i=0;
	queue<int>q1;
	queue<int>q2;
	int min=INT_MAX;
	dfsHelper(g, start,end , visited, index,min,q,arr,count,i,q1);
	//printarr(arr,i);
	q2=q1;
	int c=0;
	sortQ(q1);
	
	int sum=0;
	while(!q2.empty()){
		c++;
		if(q1.front()==q2.front()){
			break;
		}
		else{
			sum=sum+q2.front();
			q2.pop();
		}
	}
	printarr(arr,sum,q1.front());
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
	dfs(g, 7,2);
}