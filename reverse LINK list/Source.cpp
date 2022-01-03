#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int data;
	ListNode* next;
};
void add(ListNode*& linklist, int value) {
	if (linklist == nullptr) {
		ListNode* n = new ListNode;
		n->data = value;
		n->next = linklist;
		linklist = n;

	}
	else {
		ListNode* current = linklist;
		while (current->next != nullptr) {
			current = current->next;
		}
		ListNode* a = new ListNode;
		a->data = value;
		a->next = current->next;
		current->next = a;
	}
}
void reverse(ListNode* a) {
	if (a == nullptr) {
		return;
	}
	else{
		reverse(a->next);
		cout << a->data << " ";
	}
}

/*void reverse (){
	ListNode *p;
	ListNode *c;
	ListNode *n;
	p=nullptr;
	c=head;
	while(c!=nullptr){
		n=c->next;
		c->next = p;
		p=c;
		c=n;
	}
	head=p;
}*/
/*void print() {
	ListNode* a = head;
	while (a != nullptr) {
		cout << a->data << " ";
		a = a->next;
	}
}
*/
int main() {
	ListNode* a = nullptr;
	int n;
	int num;
	cout << "how many :";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "enter number :";
		cin >> num;
		add(a, num);
	}
	ListNode* x = a;
	while (x != nullptr) {
		x = x->next;
	}
	reverse(a);
	//print(a);

}