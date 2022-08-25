#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // deconstructor

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for " << value << endl;
    }
};
// insert at head
void InsertAtHead(Node *&head, int data)
{

    // create new node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
// print
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

// insert at tail
void InsertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// insertionin middle

void InsertAtPosition(Node *&head, Node *&tail, int postion, int data)
{
    if (postion == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    Node *newNode = new Node(data);
    while (cnt < postion - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// delete node
void deleteNode(Node *&head, Node *&tail, int position)
{
    // first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        // memory free
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            prev->next = NULL;
            tail = prev;
            delete curr;
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // cout<<"Hello WOrld";
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 0);
    print(head);
    InsertAtTail(tail, 2);
    print(head);
    InsertAtPosition(head, tail, 4, 3);
    // cout << node1->data;
    print(head);
    deleteNode(head, tail, 4);
    print(head);
    cout << tail->data << endl;

    // print(tail);
    return 0;
}