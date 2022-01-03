//q6
/*
#include<bits/stdc++.h>
using namespace std;

char str[8]={'A','B','C','D','E','F','G','H'};

struct node{
	char a=' ';
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
void addedge(graph* g ,int source,char data){
	node* n=new node;
	n->a=data;
	n->next=g->adj[source];
	g->adj[source]=n;
}

void printqs(queue<char> q) 
{ 
	cout<<"{ ";
	while(!q.empty()){
		cout<<q.front()<<",";
		q.pop();
	}cout<<"\b }"<<endl;
}

int distance(graph* g ,char start,char end){
	if(start==end)
		return 0;
	queue<char> q;
	node* n=nullptr;
	queue<char>q1;
	queue<char>q2;
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
		char p=q.front();
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
void firstLevelFriendList (graph* g ,char start){
	queue<char>q1;
	int x=0;

	for(int i=0;i<g->numVer;i++){
		x=distance(g,start,str[i]);
		if(x==1){
			q1.push(str[i]);

		}
	}
	printqs(q1);
}

int main(){
	graph* g=new graph(8);
	
	addedge(g, 0, 'B');
	addedge(g, 0, 'C');
	addedge(g, 0, 'D');
	addedge(g, 0, 'E');
	addedge(g, 1, 'C');
	addedge(g, 3, 'G');
	addedge(g, 5, 'A');
	addedge(g, 5, 'C');
	addedge(g, 5, 'D');
	addedge(g, 6, 'E');
	addedge(g, 6, 'H');
	addedge(g, 7, 'C');
	addedge(g, 7, 'E');
	addedge(g, 7, 'F');
	//node index-> 0-A,1-B,2-C,3-D,4-E,5-F,6-G,7-H
	char source='A';
	cout<<source<<"\'s "<<"1st level of friend : ";
	firstLevelFriendList (g,source);
}

*/
//Q2
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	string str="input.txt";
	stringstream ss;
	
	ifstream file(str);
	float n=0;
	float sum=0;
	float avg=0;
	int count=0;

	if(file.is_open()){

		while(ss<<str){
			ss>>n;
			cout<<n<<" ";
		}

	}
	else
		cout<<"file not open";
	
}
*/
//q3
/*
#include<bits/stdc++.h>
using namespace std;
int largestDigithelper(int n,int &max){
    if(n == 0)
      return 0;
    else{
    int m=0;
    m = n%10;
    
    if(m>max){
    	max=m;
    }
    int a = 0;
    a=n/10;
        largestDigithelper(a,max);
   return max;
    }
         
}

int largestDigit(int n){
	int max=INT_MIN;
	int m=0;
	if(n<0){
		n=-1*n;
	}
		 return largestDigithelper(n,max);
	
}

int main()
{
    cout<<largestDigit(52649);
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	ListNode* next;
};
void add(ListNode *& linklist,int value){
	if(linklist==nullptr){
		ListNode* n=new ListNode;
		n->data=value;
		n->next=linklist;
		linklist=n;

	}
	else{
		ListNode*current =linklist;
		while(current->next!=nullptr){
			current =current->next;
		}
		ListNode *a=new ListNode;
		a->data=value;
		a->next=current->next;
		current->next=a;
	}
}

void print(ListNode* a){
	while(a!=nullptr){
		cout<<a->data<<" ";
		a=a->next;
	}
}
void removeData(ListNode*& a) {
    if (a == nullptr) {
        return;
    }
  ListNode* temp;
    while(a!=nullptr){
    	 temp=a;
    	a=a->next;
    	delete(temp);
    }
}
void transferFromhelper(ListNode*& a,ListNode*& b){
	while(a->next!=nullptr)
	{
		a=a->next;
	}
	while(b!=nullptr){
		a->next=b;
		b=b->next;
		a=a->next;
	}

}
void transferFrom(ListNode* a,ListNode*& b){
	transferFromhelper(a,b);
			removeData(b);
}
int main(){
	ListNode* a=nullptr;

	add(a,8);
	add(a,17);
	add(a,2);
	add(a,4);

	ListNode* b=nullptr;

	add(b,1);
	add(b,2);
	add(b,3);

	transferFrom(a,b);
	cout<<"list 1: ";
	print(a);cout<<endl;

	cout<<"list 2: ";
	print(b);

}


/*
#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode {
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void insert(BinaryTreeNode*& bst, int n) {
	if (bst == nullptr) {
		bst = new BinaryTreeNode;
		bst->data = n;
		bst->right = nullptr;
		bst->left = nullptr;
	}
	else if (n > bst->data) {
		insert(bst->right, n);
	}
	else if (n < bst->data) {
		insert(bst->left, n);
	}
}
void printqs(queue<int> q) 
{ 
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}cout<<endl;
}
void printbst(BinaryTreeNode* bst) {
	if (bst == nullptr)
		return;
	printbst(bst->left);
	cout << bst->data << " ";
	printbst(bst->right);

}
int maxnumber(BinaryTreeNode* bst){
	if(bst==nullptr)
		return 0;
	while(bst->right!=nullptr){
		bst=bst->right;
	}
	return(bst->data);
}
/*int bstGetMax(BinaryTreeNode* node) {
	if(node==nullptr)
		throw "empty";
	if (node->right == nullptr) 
        return node->data; 
     return bstGetMax(node->right);
}
*/
//remove a data from the tree
/*
void removeData(BinaryTreeNode*& bst,int n){
	if(bst==nullptr)
		return;
	else if(n>bst->data){
		removeData(bst->right,n);
	}
	else if(n<bst->data){
		removeData(bst->left,n);
	}
	else if(n==bst->data){
		//node with 0 child
		if(bst->left==nullptr && bst->right==nullptr){
			bst=nullptr;
		}
		//node with one child
		else if(bst->right==nullptr){
			bst=bst->left;
		}
		else if(bst->left==nullptr){
			bst=bst->right;
		}
		//node with two child
		else{
			int max=maxnumber(bst->left);
			bst->data=max;
			removeData(bst->left,max);
		}
		/*
		else{
			int min=minnumber(bst->right);
			bst->data=min;
			removeData(bst->right,min);
		}
		
	}
}*/
/*
void printPathsUtil(BinaryTreeNode* a, int sum, int sum_so_far, queue<int>& q,queue<int>& q1) 
{ 
    if (a == NULL) 
        return; 
 	
    sum_so_far += a->data;  
      q.push(a->data);

    	
    if (sum_so_far <= sum ) 
    { 	q1.push(a->data);
    	

    	q.pop();
      
    } 

  
    if (a->left != NULL) 
        printPathsUtil(a->left, sum, sum_so_far,q,q1); 

    if (a->right != NULL) 
        printPathsUtil(a->right, sum, sum_so_far,q,q1); 
} 

void printPaths(BinaryTreeNode *a, int sum) 
{ 

    queue<int>q;
    queue<int>q1;
    
    printPathsUtil(a, sum, 0,q,q1); 
    cout<<endl;
   	int sz=q.size();
   	int s=q1.size();
   	for(int i=0;i<s;i++){
   		int x=q1.front();
   		q1.pop();
   		for(int j=0;j<sz;j++){
   			int y=q.front();
   			if(x==y){
   				q.pop();
   			}
   			else{
   				q.pop();
   				q.push(y);
   			}
   		}
   	}
 while(!q.empty()){
 	removeData(a,q.front());
 	q.pop();
 }
   	


} 
int main() {
	BinaryTreeNode* a = nullptr;
	int count = 0;
	insert(a, 29);
	insert(a, 17);
	insert(a, 115);
	insert(a, 11);
	insert(a, 18);
	insert(a, 44);
	insert(a, 214);
	insert(a, -8);
	insert(a, 12);
	insert(a, 26);
	insert(a, 200);
	insert(a, 219);
	printbst(a);
	printPaths(a,50);
cout<<endl;
printbst(a);
}
*/

#include <bits/stdc++.h> 
using namespace std; 

float findSumOfIntegers(string str) 
{ 
	ifstream f;  
	f.open(str); 
	
	float sum = 0, num = 0,n=0; 
 
	string text=" "; 
	while (f >> text) { 

		if(isdigit(text[0])){
			
stringstream ss;  
  ss << text;  
  ss >> num; 
  n++;
  sum+=num;
		} 
		
	}
	return sum; 

} 

int main() 
{ string str="input.txt";
 cout<<findSumOfIntegers(str); 
	return 0; 
} 
