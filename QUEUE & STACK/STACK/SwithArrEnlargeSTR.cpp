#include <iostream>
using namespace std;
struct myQueue {
  int szArr = 2;
  string *arr = new string[szArr];
  int head = 0;
  int numElem = 0;
};
void enlarge(myQueue*&q, int sz) {
  string *arr2 = new string[sz];
  for (int i = 0; i < sz / 2; ++i) {
    arr2[i] = q->arr[i];
  }
  string *s = q->arr;
  q->arr = arr2;
  delete[] s;
}
void enqueue(myQueue*&q, string str) {

  if (q->arr[q->head % q->szArr] != "") {
    return;
  }
  q->arr[q->head % q->szArr] = str;

  q->head = q->head + 1;
    q->numElem = q->head;
  if (q->numElem == q->szArr) {
    q->szArr = q->szArr * 2;
    enlarge(q, q->szArr);
  }
}

string dequeue(myQueue*&q) {
   q->head--;
   if(q->head<0){
    return " ";
   }
  string st = q->arr[q->head % q->szArr];
  q->arr[q->head % q->szArr] = "";
  if (st == "") {
    return st;
  }
 
  return st;
}

int main() {
  myQueue* q = new myQueue;
  enqueue(q, "A");
  enqueue(q, "B");
  enqueue(q, "C");
  enqueue(q, "D");
  enqueue(q, "E");
  enqueue(q, "zakaria");

  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  delete q;
  return 0;
}