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
void addedgeMatrix(graph *g,int x,int z){
	g->verArr[x][z]=1;

}
void printAdjacencyMatrix(graph* g){
	cout<<setw(10)<<" ";
	for(int i=0;i<g->numVer;i++){
		cout<<left<<setw(10)<<str[i];
	}cout<<endl;
	for(int i=0;i<g->numVer;i++){
		cout<<left<<setw(10) <<str[i]<<" : ";
		for(int j=0;j<g->numVer;j++){
			cout<<setw(10)<< g->verArr[i][j];
		}
		cout<<endl;
	}

}

int main(){
	graph* g=new graph(9);
	//node index-> 0-gulshan,1-lalbagh,2-motijheel,3-gabtoli,4-nilkhet,5-azimpur,6-mirpur,7-DOHS,8-jatrabari
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
	addedge(g, 7, " ");
	addedge(g, 8, "DOHS");
	addedge(g, 8, "mirpur");

	printAdjacencyList(g);
	cout<<"______________________________________________________________________________________________________"<<endl;

	addedgeMatrix(g,0,1);
	addedgeMatrix(g,1,2);
	addedgeMatrix(g,1,3);
	addedgeMatrix(g,2,3);
	addedgeMatrix(g,3,4);
	addedgeMatrix(g,3,5);
	addedgeMatrix(g,3,8);
	addedgeMatrix(g,4,2);
	addedgeMatrix(g,5,8);
	addedgeMatrix(g,6,0);
	addedgeMatrix(g,6,1);
	addedgeMatrix(g,6,5);
	addedgeMatrix(g,6,7);
	addedgeMatrix(g,7,-1);
	addedgeMatrix(g,8,6);
	addedgeMatrix(g,8,7);

	printAdjacencyMatrix(g);

}