#include<bits/stdc++.h>
using namespace std;


string str[8]={"A","B","C","D","E","F","G","H"};

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
	cout << "\b\b" << "  ";
	cout<<endl;
} 
int distance(graph* g ,int start,int end){
	if(start==end)
		return 0;
	queue<int> q;
	node* n=nullptr;
	q.push(start);
	int count=1;
	int numNodeseachLevel=1;
	bool *visited=new bool [g->numVer];
	for(int i=0;i<g->numVer;i++){
		visited[i]=false;
	}

	for(int i=0;i<g->numVer;i++){
		if(i==start){
			visited[i]=true;
		}
	}
	
	while(!q.empty()){
		int p=q.front();
		//cout<<p<<"->";
		q.pop();
		numNodeseachLevel-=1;
		for(int i=0;i<g->numVer;i++){
			if(i==p){
				n=g->adj[i];
			}
		}
		
		while(n!=nullptr){
			for(int i=0;i<g->numVer;i++){
				if(n->a==str[end])
					return count;
				if(str[i]==n->a){
					if(visited[i]==false){
						visited[i]=true;
						q.push(i);
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

void printShortestPath(graph* g ,int start,int end){
	if(distance(g,start,end)<=0){
		cout<<"no valid path ."<<endl;
		return;
	}
	queue<int> q;
	node* n=nullptr;
	queue<int>q1;
	
	q.push(start);
	int numNodeseachLevel=1;
	bool *visited=new bool [g->numVer];
	for(int i=0;i<g->numVer;i++){
		visited[i]=false;
	}


	for(int i=0;i<g->numVer;i++){
		if(i==start){
			visited[i]=true;
		}
	}
	
	while(!q.empty()){
		int p=q.front();
		q.pop();
		cout<<p<<" , ";
		q1.push(p);
		numNodeseachLevel-=1;
		for(int i=0;i<g->numVer;i++){
			if(i==p){
				n=g->adj[i];
			}
		}
		
		while(n!=nullptr){
			if(n->a==str[end])
				goto j;
			for(int i=0;i<g->numVer;i++){
				if(str[i]==n->a){

					if(visited[i]==false){
						visited[i]=true;
						q.push(i);

						
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
	int x=0;
	queue<int>q2;
	queue<int>q3;
	queue<int>q4;
	int frst=distance(g,q1.front(),end);
	while(!q1.empty()){
		x=q1.front();
		int f=distance(g,x,end);
		q1.pop();
		if(f>0&&f<=frst){
			q2.push(f);
			q4.push(x);
		}
	}
	int sz=q2.size();
	while(!q2.empty()){
		int f=q2.front();
		int ff=q4.front();
		q4.pop();
		q2.pop();
		q3.push(f);
		q1.push(ff);
		int size=q2.size();
		for(int i=0;i<size;i++){
			int s=q2.front();
			int ss=q4.front();
			q4.pop();
			q2.pop();
			if(f!=s){
				q2.push(s);
				q4.push(ss);
			}
		}
	}
	q1.push(end);
	cout<<"shortest path from \""<<start<<"\" to \""<<end<< "\" : ";
	printq(q1);
	cout<<"by node name : "<<endl;
	cout<<"shortest path from \""<<str[start]<<"\" to \""<<str[end]<< "\" : ";
	while(!q1.empty()){
		int w=q1.front();
		q1.pop();
		for(int i=0;i<g->numVer;i++){
			if(i==w){
				cout<<str[i]<<"->";
			}
		}
	}
	cout << "\b\b" << "  ";
}

int main(){
	graph* g=new graph(8);
	//node index-> 0-gulshan,1-lalbagh,2-motijheel,3-gabtoli,4-nilkhet,5-azimpur,6-mirpur,7-DOHS,8-jatrabari
	addedge(g, 0, "B");
	addedge(g, 0, "C");
	addedge(g, 0, "D");
	addedge(g, 0, "E");
	addedge(g, 1, "C");
	addedge(g, 3, "G");
	addedge(g, 5, "A");
	addedge(g, 5, "C");
	addedge(g, 5, "D");
	addedge(g, 6, "E");
	addedge(g, 6, "H");
	addedge(g, 7, "C");
	addedge(g, 7, "E");	
	addedge(g, 7, "F");
	
	//printAdjacencyList(g);cout<<endl;
	printShortestPath(g,3,2);
}
//SESH HOY NAI