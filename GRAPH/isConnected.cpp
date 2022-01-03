#include<bits/stdc++.h>
using namespace std;

string str[9]={"A","B","C","D","E","F","G","H","I"};

struct node{
	string a=" ";
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
void addedge(graph* g ,int source,string data){
	node* n=new node;
	n->a=data;
	n->next=g->adj[source];
	g->adj[source]=n;
}

void printgraph(graph* g){
	for (int i=0;i<g->numVer;i++){
		node* n=g->adj[i];
		cout<<left<<setw(3)<<str[i]<<" : ";
		while(n!=nullptr){
			cout<<setw(2)<<n->a<<"," ;
			n=n->next;
		}
		cout << "\b" << "  ";
		cout<<endl;
	}

}

void printqs(queue<string> q) 
{ 
	cout<<"{";
	while(!q.empty()){
		cout<<q.front()<<",";
		q.pop();
	}cout<<"\b}"<<endl;
}

bool isConnectedHelper(graph* g ,string src,string dest){
	if(dest==src)
		return true;
	node* n=nullptr;
	queue<string> q;
	q.push(src);
	bool *visited=new bool [g->numVer];
	for(int i=0;i<g->numVer;i++){
		visited[i]=false;
	}
	for(int i=0;i<g->numVer;i++){
		if(str[i]==src){
			visited[i]=true;
		}
	}
	while(!q.empty()){
		string p=q.front();
		q.pop();
		for(int i=0;i<g->numVer;i++){
			if(str[i]==p){
				n=g->adj[i];
			}
		}
		while(n!=nullptr){
			for(int i=0;i<g->numVer;i++){
				if(n->a==dest)
					return true;
				if(str[i]==n->a){
					if(visited[i]==false){
						visited[i]=true;
						q.push(n->a);
					}
				}
			}
			n=n->next;
		}
	}
	return false;
}
bool isConnected (graph*& g){
	bool flag=true;
	for(int i=0;i<g->numVer;i++){
		for(int j=0;j<g->numVer;j++){
			if(isConnectedHelper(g,str[i],str[j])==false){
				flag=false;
				break;
			}

		}
	}
	return flag;
}

int main(){
	graph* g=new graph(9);
	//node index-> 0-A,1-B,2-C,3-D,4-E,5-F,6-G,7-H,8-I
	addedge(g, 0, "B");
	addedge(g, 0, "D");
	addedge(g, 0, "E");
	addedge(g, 1, "C");
	addedge(g, 1, "F");
	addedge(g, 2, "F");
	addedge(g, 3, "G");
	addedge(g, 4, "G");
	addedge(g, 4, "F");
	addedge(g, 4, "H");
	addedge(g, 5, "I");
	addedge(g, 6, "H");
	addedge(g, 7, "I");
	//addedge(g, 8, "A");
	//printgraph(g);cout<<endl;
	
	cout<<"is the graph connected ? ";
	isConnected (g) ? cout<<"true":cout<<"false";

}

