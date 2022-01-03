#include<bits/stdc++.h>
using namespace std;
struct Node* creatLinkList(int arr[], int size);
int searchLinkList(struct Node *head, int value);
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    int a[] = { 5, 10, 15, 20, 30, 100 };
    struct Node* head;
  
    head = creatLinkList(a, 6);

    while (head != NULL)
    {
        cout<< head->data<<" -> ";
        head = head->next;
    }
    cout <<"NULL"<<endl; 
    Node* h=creatLinkList(a,6);
     cout<<"Searching value index is: "<<searchLinkList(h, 20)<<endl;
    return 0;
}
struct Node *creatLinkList(int arr[], int size)
{
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    for (int i = 0; i<size; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current-> next = temp;
            current = current-> next;
        }
    }
    return head;
}
int searchLinkList(struct Node *head, int value)
{
    int index = 1;
    while(head != NULL)
    {
        if(head -> data == value)
        {
            return index;
        }
         index++;
         head = head -> next;
    }
    return -1;
}