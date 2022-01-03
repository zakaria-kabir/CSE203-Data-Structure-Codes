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
	cout<<"{ ";
	while(!q.empty()){
		cout<<q.front()<<",";
		q.pop();
	}cout<<"\b }"<<endl;
}

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
			//if(islink(g,str[i],str[i+1])){
				addedge(g,i,str[i+1]);
			//}

		}
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
void kthLevelFriends (graph* g ,string start,int k){
	makelink(g);
	queue<string>q1;
	int x=0;
	if(k==0){
		q1.push(start);
		goto j;
	}
	for(int i=0;i<g->numVer;i++){
		x=distance(g,start,str[i]);
		if(x>0&&x==k){
			q1.push(str[i]);

		}
	}
	j:
	printqs(q1);
}

int main(){
	graph* g=new graph(9);
	//node index-> 0-A,1-B,2-C,3-D,4-E,5-F,6-G,7-H,8-I
	addedge(g, 0, "B");
	addedge(g, 0, "D");
	addedge(g, 1, "E");
	addedge(g, 1, "B");
	addedge(g, 2, "B");
	addedge(g, 3, "G");
	addedge(g, 4, "D");
	addedge(g, 4, "F");
	addedge(g, 5, "C");
	addedge(g, 6, "");
	addedge(g, 7, "E");
	addedge(g, 7, "G");
	addedge(g, 8, "F");
	addedge(g, 8, "H");
	int k=1;
	string source="A";
	cout<<source<<"\'s "<<k<<" level of friend : ";
	kthLevelFriends (g,source,k);


}

