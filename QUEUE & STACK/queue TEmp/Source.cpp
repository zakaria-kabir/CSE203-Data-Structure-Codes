#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the queue
#define SIZE 10

#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the stack
#define SIZE 10

// Class for stack
class stack
{
	int* arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);		// constructor
	~stack();					// destructor

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize stack
stack::stack(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

// Destructor to free memory allocated to the stack
stack::~stack()
{
	delete[] arr;
}

// Utility function to add an element x in the stack
void stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << x << endl;
	arr[++top] = x;
}

// Utility function to pop top element from the stack
int stack::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

// Utility function to return top element in a stack
int stack::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int stack::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}


// Class for queue
class queue
{
	int* arr;		// array to store queue elements
	int capacity;	// maximum capacity of the queue
	int front;		// front points to front element in the queue (if any)
	int rear;		// rear points to last element in the queue
	int count;		// current size of the queue

public:
	queue(int size = SIZE);		// constructor
	~queue();					// destructor

	int dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize queue
queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
	delete[] arr;
}

// Utility function to remove front element from the queue
int queue::dequeue()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << arr[front] << '\n';

	front = (front + 1) % capacity;
	count--;
	return arr[front];
}

// Utility function to add an item to the queue
void queue::enqueue(int item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to return front element in the queue
int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
	return (size() == capacity);
}
void print(queue q) {
	while (!q.isEmpty()) {
		cout << q.dequeue() << " ";
		
	}
	cout << endl;
}
void mirror(queue& q) {
	stack s(10);
	int x = 0;
	int size = q.size();
	for (int i = 0; i < size; i++) {
		x = q.dequeue();
		s.push(x);
		q.enqueue(x);
	}
	while (!s.isEmpty()) {
		q.enqueue(s.pop());
	}
}
int main() {
	queue que(3);
	que.enqueue(1);
	que.enqueue(2);
	que.enqueue(3);
	mirror(que);
	//print(que);
}