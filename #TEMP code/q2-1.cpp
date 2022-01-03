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
/*
ListNode* removeAll(ListNode*& a) {
	ListNode* trash = nullptr;
	if (a == nullptr || a->next == nullptr) {
		return a;
	}
	int d = a->data;
	if (a->next->data!=d) {
		a->next = removeAll(a->next);
			return a;
	}

	while (a != nullptr && d == a->data) {
		a = a->next;
	}
	return removeAll(a);
}
*/
void removeData(ListNode*a){
  if(a == nullptr){
    return ;
  }
  while(a->data == a->next->data){
    ListNode*j = a;
    a = a->next;
    delete j;
    if(a==nullptr)return;
  }
  
    ListNode* current = a;
    while(current->next!=nullptr){
      if(current->data == current->next->data){
        ListNode* j = current->next;
        current->next = current->next->next;
        delete j;
      }
      else{
        current =current->next;
      }
    }
}
void removeAll (ListNode* a) {
	
	while(a->next!=nullptr){
		if(a->data==a->next->data){
			//removeData(a,a->data);
			a=a->next;
		}
		else
			a=a->next;
	}
		
}

void print(ListNode* x) {
	while (x != nullptr) {
		cout << x->data << " ";
		x = x->next;
	}
	cout << endl;
}
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
	//print(a);
	
removeData(a);
	//removeAll(a);
	print(a);

}