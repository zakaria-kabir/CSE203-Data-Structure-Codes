#include<bits/stdc++.h>
using namespace std;

string str[9]={"gulshan","lalbagh","motijheel","gabtoli","nilkhet","azimpur","mirpur","DOHS","jatrabari"};

struct node{
	string a=" ";
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
void addedge(graph* g ,int source,string data){
	node* n=new node;
	n->a=data;
	n->next=g->adj[source];
	g->adj[source]=n;
}

void printAdjacencyList(graph* g){
	for (int i=0;i<g->numVer;i++){
		node* n=g->adj[i];
		cout<<left<<setw(10)<<str[i]<<" : ";
		while(n!=nullptr){
			cout<<setw(10)<<n->a<<"," ;
			n=n->next;
		}
		cout << "\b" << "  ";
		cout<<endl;
	}

}
void printq(queue<int> q) 
{ 
	while(!q.empty()){
		cout<<q.front()<<"->";
		q.pop();
	}
} 
void printqs(queue<string> q) 
{ 
	while(!q.empty()){
		cout<<q.front()<<"->";
		q.pop();
	}
} 
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
void printShortestPath(graph* g ,string start,string end){
	if(distance(g,start,end)<=0){
		cout<<"no valid path ."<<endl;
		return;
	}
	queue<string> q;
	node* n=nullptr;
	queue<string>q1;
	queue<string> q2;
	
	q.push(start);
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
		//cout<<p<<" , ";
		q1.push(p);
		numNodeseachLevel-=1;
		for(int i=0;i<g->numVer;i++){
			if(str[i]==p){
				n=g->adj[i];
			}
		}
		
		while(n!=nullptr){
			if(n->a==end)
				goto j;
			for(int i=0;i<g->numVer;i++){
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
			numNodeseachLevel = q.size();
		}
	}
	j:
	string x=" ";
	string m=" ";
	queue<int>q3;
	queue<int> q4;
	int s=0,d=0;
	int frst=distance(g,q1.front(),end);
	while(!q1.empty()){
		x=q1.front();
		int f=distance(g,x,end);
		q1.pop();
		if(f>0&&f<=frst){
		q3.push(f);
		q2.push(x);
	}

	}
	int size=q3.size();
	while(!q3.empty()){
		int f=q3.front();
		string ff=q2.front();
		q3.pop();	
		q2.pop();
		q4.push(f);
		q1.push(ff);
		int sz=q3.size();
		
		for(int i=0;i<sz;i++){
			int s=q3.front();
			string ss=q2.front();
			q3.pop();
			q2.pop();
			if(f!=s){
				q3.push(s);
				q2.push(ss);
			}
			
			
		}

	}
	q1.push(end);
	cout<<"shortest path from \""<<start<<"\" to \""<<end<< "\" : ";
	printqs(q1);

}
int main(){
	graph* g=new graph(9);
	addedge(g, 0, "lalbagh");
	addedge(g, 1, "motijheel");
	addedge(g, 1, "gabtoli");
	addedge(g, 2, "gabtoli");
	addedge(g, 3, "azimpur");
	addedge(g, 3, "jatrabari");
	addedge(g, 3, "nilkhet");
	addedge(g, 4, "motijheel");
	addedge(g, 5, "jatrabari");
	addedge(g, 6, "gulshan");
	addedge(g, 6, "lalbagh");
	addedge(g, 6, "azimpur");
	addedge(g, 6, "DOHS");	
	addedge(g, 7, "");
	addedge(g, 8, "DOHS");
	addedge(g, 8, "mirpur");

	//printAdjacencyList(g);cout<<endl;
	printShortestPath(g,"azimpur","nilkhet");


}