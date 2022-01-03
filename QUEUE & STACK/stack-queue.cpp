#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the stack
#define SIZE 10

// Class for stack
class stack
{
	int *arr;
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
	int *arr;		// array to store queue elements
	int capacity;	// maximum capacity of the queue
	int front;		// front points to front element in the queue (if any)
	int rear;		// rear points to last element in the queue
	int count;		// current size of the queue

public:
	queue(int size = SIZE);		// constructor
	~queue();					// destructor

	void dequeue();
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
void queue::dequeue()
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


int main()
{
	stack pt(3);

	//pt.push(1);
	pt.push(2);

	pt.pop();
	pt.pop();

	pt.push(3);

	cout << "Top element is: " << pt.peek() << endl;

	cout << "Stack size is " << pt.size() << endl;

	pt.pop();

	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	cout<<endl;

	// create a queue of capacity 5
	queue q(5);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	
	cout << "Front element is: " << q.peek() << endl;
	q.dequeue();
	
	q.enqueue(4);

	cout << "Queue size is " << q.size() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
}