#include<bits/stdc++.h>
using namespace std;
struct node{
	int data=0;
	node* right=nullptr;
	node* left=nullptr;
};
//add a number in tree
void insert(node*& bst,int n){
	if(bst==nullptr){
		bst=new node;
		bst->data=n;
		bst->right=nullptr;
		bst->left=nullptr;
	}
	else if(n>bst->data){
		insert(bst->right,n);
	}
	else if(n<bst->data){
		insert(bst->left,n);
	}
}
//find a number in tree
bool find(node*bst,int n){
	bool flag=false;
	if(bst==nullptr)
		return false;
	else if(bst->data==n)
		return true;
	else if(n>bst->data)
		find(bst->right,n);
	else if(n<bst->data)
		find(bst->left,n);
	
}
bool bstContains(node* n, int value) {
	if(n==nullptr)
		return false;
	if(n->data==value)
		return true;
	bool flag=bstContains(n->right,value);
	if(flag==true)
		return true;
	bool flag1=  bstContains(n->left,value);
	return flag1;
}
//find minimum number of the tree
int minnumber(node* bst){
	if(bst==nullptr)
		return 0;
	/*
	else if(bst->left==nullptr)
		return bst->data;
	else
		return(minnumber(bst->left));
	*/
	while(bst->left!=nullptr){
		bst=bst->left;
	}
	return (bst->data);
}
//find maximum number of tree
int maxnumber(node* bst){
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
void removeData(node*& bst,int n){
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
		*/
	}
}
//number of total leaves of the tree
int numberofleaves(node* bst){
	if(bst==nullptr)
		return 0;
	else if(bst->left==nullptr && bst->right==nullptr){
		return 1;
	}
	return(numberofleaves(bst->right)+numberofleaves(bst->left));
}
//number of total nodes of the tree
int numberofNodes(node* bst){
	if(bst==nullptr){
		return 0;
	}
	return 1+numberofNodes(bst->left)+numberofNodes(bst->right);
}
//find the position of a number in the tree
void findPOsition(node* bst,int n,int& count){
	if(bst==nullptr)
		return;
	count=count+1;
	if(bst->data==n){
		return;
	}
	findPOsition(bst->left,n,count);
	findPOsition(bst->right,n,count);
}
int depthHelper(node* bst,int n){
	if(bst==nullptr)
		return INT_MIN;
	else if(bst->data==n){
		return 0;
	}
	else if(n>bst->data){
		return depthHelper(bst->right,n)+1;
	}
	else if(n<bst->data){
		return depthHelper(bst->left,n)+1;
	}
}
int depth(node*bst,int n){
	if(depthHelper(bst,n)<0){
		return -1;
	}
	else{
		return(depthHelper(bst,n));
	}
}

void printbst(node* bst){
	if(bst==nullptr)
		return;
	//ascending order
	printbst(bst->left);
	cout<<bst->data<<" ";
	printbst(bst->right);
	//descending order
	/*
	printbst(bst->right);
	cout<<bst->data<<" ";
	printbst(bst->left);
	*/
	//same as input order
	/*
	cout<<bst->data<<" ";
	printbst(bst->left);
	printbst(bst->right);
	*/
}
void hightHelper(node* bst,int d,int &h){
	if(bst==nullptr){
		if(d>h){
			h=d;
		}
		return;
	}
	d=d+1;
	hightHelper(bst->right,d,h);
	hightHelper(bst->left,d,h);
}
int hight(node* bst){
	int d=-1;
	int h=-1;
	hightHelper(bst,d,h);
	return h;
}

bool isBSTHelper(node* bst, node*& prev) {
	if (bst!=nullptr){
		if (!isBSTHelper(bst->left, prev)) 
			return false; 
		if (prev != nullptr && bst->data <= prev->data) 
			return false; 
		prev = bst;    
		return isBSTHelper(bst->right, prev); 
	}  
	return true; 
} 
bool isBST(node *bst) {
	node *prev = nullptr; 
	return isBSTHelper(bst, prev); 
} 

int main(){
	node* a=nullptr;
	int count=0;
	insert(a,8);
	insert(a,4);
	insert(a,2);
	insert(a,7);
	insert(a,9);
	

	printbst(a);
	cout<<endl;
	cout<<"min number is :"<<minnumber(a)<<endl;
	cout<<"max number is :"<<maxnumber(a)<<endl;
	cout<<"number is found or not :"<<find(a,7)<<endl;
	cout<<"number is found or not :"<<bstContains(a,7)<<endl;
	removeData(a,11);
	removeData(a,101);
	printbst(a);
	cout<<endl;
	cout<<"number of leaves :"<<numberofleaves(a)<<endl;
	cout<<"number of Nodes :"<<numberofNodes(a)<<endl;
	findPOsition(a,90,count);
	cout<<"number found in :"<<count<<" place"<<endl;
	cout<<"depth of node :"<<depth(a,20)<<endl;
	cout<<"hight of longest node :"<<hight(a)<<endl;
	cout<<"IS BST? "<<isBST(a)<<endl;
}

