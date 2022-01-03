#include <iostream>
using namespace std;
struct node {
    int data = 0;
    node* prev = nullptr;
    node* next = nullptr;
};
void addValue(node*& a, int value) {
    if (a == nullptr) {
        node* x = new node;
        x->data = value;
        x->next = a;
        x->prev = nullptr;
        a = x;
    }
    else {
        node* current = a;
        while (current->next != nullptr) {
            current = current->next;
        }
        node* x = new node;
        x->data = value;
        x->next = current->next;
        x->prev = current;//extra line
        current->next = x;
    }
}

void addIndex(node*& a, int index, int value) {
    if (index == 0) {
        node* x = new node;
        x->data = value;
        x->next = a;//a can be eith either empty or it can be nonempty
        x->prev = nullptr;
        if (a != nullptr) {
            a->prev = x;
        }
        a = x;
    }
    else {
        node* current = a;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        node* x = new node;
        x->data = value;
        x->next = current->next;
        x->prev = current;
        if (current->next != nullptr) {
            current->next->prev = x;
        }
        current->next = x;
    }

}
void removeData(node*& a, int value) {
    if (a == nullptr) {
        return;
    }
    while (a->data == value) {
        node* j = a;
        a = a->next;
        if (a != nullptr) {
            a->prev = nullptr;
        }
        delete j;
        if (a == nullptr)return;
    }

    node* current = a;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            node* j = current->next;
            current->next = current->next->next;
            if (current->next != nullptr) {
                current->next->prev = current;
            }
            delete j;
        }
        else {
            current = current->next;
        }
    }
}
void removeIndex(node*& a, int index) {
    if (index == 0) {
        node* j = a;
        a = a->next;
        if (a != nullptr) {
            a->prev = nullptr;
        }
        delete j;
    }
    else {
        node* current = a;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        node* j = current->next;
        current->next = current->next->next;
        if (current->next != nullptr) {
            current->next->prev = current;
        }
        delete j;
    }
}
void printData(node* a) {
    cout<<"from front to end: ";
    while (a->next != nullptr) {
        cout << a->data << " ";
        a = a->next;
    }
    cout <<a->data<< endl;
    cout<<"from end to front: ";
    while (a->prev != nullptr) {
        cout << a->data << " ";
        a = a->prev;
    }
    cout << a->data << endl;
}
int main() {
    node* n = nullptr;
    addValue(n, 2);//0
    addValue(n, 3);//1
    addValue(n, 4);//2
    addValue(n, 2);//3
    addValue(n, 6);//4
    //printData(n);
    addIndex(n, 1, 100);
   // printData(n);
    removeIndex(n,2);
   // printData(n);
    removeData(n, 2);
    printData(n);
    return 0;
}