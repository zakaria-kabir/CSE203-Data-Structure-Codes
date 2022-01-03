void print(node* x){
	while(x!=nullptr){
		cout<<x->data<<endl;
		x=x->next;
	}
}
