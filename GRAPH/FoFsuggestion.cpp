#include<bits/stdc++.h>
using namespace std;

string str[9]={"N","X","U","A","B","C","P","K","M"};

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
	cout<<"{ ";
	while(!q.empty()){
		cout<<q.front()<<",";
		q.pop();
	}cout<<"\b }"<<endl;
}
/*
bool islink(graph* g ,string src,string dest){
	
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
void makelink(graph*& g){
	for(int i=0;i<g->numVer-1;i++){
		if(islink(g,str[i],str[i+1])&&islink(g,str[i+1],str[i])){
			if(islink(g,str[i],str[i+1])){
				addedge(g,i,str[i+1]);
			}

		}
	}
}
*/
int distance(graph* g ,string start,string end){
	if(start==end)
		return 0;
	queue<string> q;
	node* n=nullptr;
	queue<string>q1;
	queue<string>q2;
	q.push(start);
	int count=1;
	int numNodeseachLevel=1;
	bool *visited=new bool [g->numVer];
	for(int i=0;i<g->numVer;i++){
		visited[i]=false;
	}

	for(int i=0;i<g->numVer;i++){
		if(str[i]==start){
			visited[i]=true;
		}
	}
	
	while(!q.empty()){
		string p=q.front();
		q.pop();
		numNodeseachLevel-=1;
		for(int i=0;i<g->numVer;i++){
			if(str[i]==p){
				n=g->adj[i];
			}
		}
		
		while(n!=nullptr){
			for(int i=0;i<g->numVer;i++){
				if(n->a==end)
					return count;
				if(str[i]==n->a){
					if(visited[i]==false){
						visited[i]=true;
						q.push(n->a);
					}
				}
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
void FoF (graph* g ,string start){
	//makelink(g);
	queue<string>q1;
	int x=0;
	for(int i=0;i<g->numVer;i++){
		x=distance(g,start,str[i]);
		if(x>0&&x==2){
			q1.push(str[i]);

		}
	}
	printqs(q1);
}

int main(){
	graph* g=new graph(9);
	//node index-> 0-N,1-X,2-U,3-A,4-B,5-C,6-P,7-K,8-M
	addedge(g, 0, "M");
	addedge(g, 0, "K");
	addedge(g, 0, "P");
	addedge(g, 0, "U");
	addedge(g, 0, "X");
	addedge(g, 0, "C");

	addedge(g, 1, "N");
	addedge(g, 1, "A");
	addedge(g, 1, "B");
	addedge(g, 1, "C");

	addedge(g, 2, "A");
	addedge(g, 2, "B");
	addedge(g, 2, "N");

	addedge(g, 3, "P");
	addedge(g, 3, "U");
	addedge(g, 3, "X");

	addedge(g, 4, "U");
	addedge(g, 4, "X");

	addedge(g, 5, "M");
	addedge(g, 5, "N");
	addedge(g, 5, "X");

	addedge(g, 6, "K");
	addedge(g, 6, "N");
	addedge(g, 6, "A");

	addedge(g, 7, "P");
	addedge(g, 7, "N");
	addedge(g, 7, "M");
	
	addedge(g, 8, "C");
	addedge(g, 8, "N");
	addedge(g, 8, "K");

	string source="U";
	FoF (g,source);

}

