#include<bits/stdc++.h>
using namespace std;
/*
void print(int n) {
	if (n == 0) {
		cout << n << " ";
	}
	else {
		print(n - 1);
		cout << n << " ";
		
	}

}
int main() {
	int n = 5;
	//cout << "input :";
	//cin >> n;
	cout << n << "  |   ";
	print(n);
}*/
/*
int sume(int n){
	if(n==0){
		return 0;
	}
	else if(n%2==0){
		return n+sume(n-1);
	}
	return sume(n-1);
}
int sumo(int n){
	if(n==0){
		return 0;
	}
	else if(n%2!=0){
		return n+sumo(n-1);
	}
	return sumo(n-1);
}

void diffOddAndEven(int n){
	cout<<sume(n)-sumo(n);
}
int main() {
	int n=5;
	//cout << "input :";
	//cin >> n;
  
	//print(n);
	//cout<<sume(n);
	//cout<<sumo(n);
	diffOddAndEven(n);
}

*/
/*
int main() {
	int n = 10;
	int* arr = new int[n]  { 10,20,30,40,50,60,70,80,90,100 };
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	n = 20;
	arr = new int[n] { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
}
*/
/*
int main() { 
int* arr = new int[4]{ 1,2,3,4 }; 
int* p;
p = arr;
for (int i = 0; i < 4; ++i) {
	
	cout << *p << endl; 
	p++;
	
} 
delete[] arr; 
}*/
int main() {
	int* arr = new int[4]{ 1,2,2,4 };
	//int* p;
	//p = arr;
	cout << &arr[0] << endl;
	cout << &arr[1] << endl;
	cout << &arr[2] << endl;
	cout << &arr[3] << endl;
	cout << endl;
	for (int i = 0; i < 4; ++i) {

		//cout << *p << endl;
		//p++;
		//cout << arr << endl;
		cout << *arr << endl;
		arr = arr + 1;
		cout << arr << endl;

	}	cout << endl;
	for (int i = 0; i < 3; ++i) {

		//cout << *p << endl;
		//p++;
		//cout << arr << endl;
		//cout << *arr << endl;
		cout << arr << " ";
		arr = arr - 1;
		cout << arr << endl;

	}


	
	delete[] arr;
}

/*
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
void getConsecutiveOdd(ListNode*& a) {
	int count = 0;
	if (a == nullptr) {
		count = 0;
		cout<<count;
		return;
	}
	while (a->next != nullptr) {
		if (a->data % 2 != 0 & a->next -> data % 2 != 0) {
			count++;
		}
		a = a->next;
	}
	cout << count;

}
void print(ListNode* a) {
	while (a != nullptr) {
		cout << a->data << " ";
		a = a->next;
	}
}
int main() {
	ListNode* a = nullptr;
	add(a, 1);
	//add(a, 2);
	add(a, 3);
	//add(a, 4);
	add(a, 5);
	
	getConsecutiveOdd(a);
}
*/

/*
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

void  repeat(ListNode*& x,int n,int z) {
	if (x == 0) {
		return;
	}
	else {
		ListNode* current = x;
		while (current != nullptr) {

			if (current->data == n) {
				for (int i = 1; i < z; i++) {
					ListNode* a = new ListNode;
					a->data = n;
					a->next = current->next;
					current->next = a;
					current = current->next;
				}
			}

			current = current->next;


		}

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
	int n = 2;
	int z = 3;
	ListNode* a = nullptr;
	add(a, 2);
	add(a, 1);
	add(a, 3);
	add(a, 2);
	add(a, 4);

	repeat(a,n,z);

	print(a);

}
*/
/*
int main(){
	string str="input.txt";
	ifstream file(str);
	int n=0;
	int sum=0;
	int sumA=0;
	int i=0;
	int j=0;
	string temp=" ";
	string s=" ";
	if(file.is_open()){

		//cout<<"file is open ";
		while(file>>s>>n){
			
				if(s=="iPhone10"||s=="iPhone6"||s=="iPhone11"){
						i++;
						sum+=n;
				}
				else{
					j++;
					sumA+=n;
				}


			
		}

	}
	else
		cout<<"file not open";
	cout<<"total iphone sold "<<sum<<endl;
	cout<<"total Android phone sold "<<	sumA<<endl;

	cout<<"number of iphone "<<i<<endl;
	cout<<"avg value of iphone "<<sum/i<<endl;

	cout<<"number of Android phone "<<j<<endl;
	cout<<"avg value of Android phone "<<sumA/j<<endl;
}*/