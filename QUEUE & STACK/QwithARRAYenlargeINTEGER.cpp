#include <iostream>
using namespace std;
struct myQueue {
  int szArr = 1;
  int *arr = new int[szArr];
  int head = 0;
  int numElem = 0;
};
void enlarge(myQueue*&q, int sz) {
  int *arr2 = new int[sz];
  for (int i = 0; i < sz / 2; ++i) {
    arr2[i] = q->arr[i];
  }
  int *s = q->arr;
  q->arr = arr2;
  delete[] s;//str -> 0xABC
  q->head = 0;
  q->tail = q->numElem;
}
void enqueue(myQueue*&q, int str) {
  q->arr[q->tail % q->szArr] = str;
  q->tail = q->tail + 1;
  q->numElem = q->tail - q->head;
  if (q->numElem == q->szArr) {
    q->szArr = q->szArr * 2;
    enlarge(q, q->szArr);
  }
}

int dequeue(myQueue*&q) {
  int st = q->arr[q->head % q->szArr];
  q->head = q->head + 1;
  return st;
}

int main() {
  myQueue* q = new myQueue;
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 2);
  enqueue(q, 5);
  enqueue(q, 0);

  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;
  cout << dequeue(q) << endl;

delete q;


  return 0;
}