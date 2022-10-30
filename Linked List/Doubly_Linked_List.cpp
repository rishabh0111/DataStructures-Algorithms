#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Dll{
    public:
    Node* head;
    Node* tail;

    void print();
    int size();
    void push_front(int d);
    void push_back(int d);
    void insert(int position, int d);
    void erase(int position);

    Dll() {
        head = NULL;
        tail = NULL;
    }
};

//Printing List:
void Dll::print() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp ->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Number of elements in list:
int Dll::size() {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

//Inserting at start:
void Dll::push_front(int d) {
    if (head == NULL) { //empty list
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//Inserting at end:
void Dll::push_back(int d) {
    if (head == NULL) { //empty list
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

//Inserting at given position:
void Dll::insert(int position, int d) {
    //Inserting at start
    if(position == 1) {
        push_front(d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    //Inserting at last
    if(temp -> next == NULL) {
        push_back(d);
        return;
    }

    //Inserting in middle
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Delete element in list:
void Dll::erase(int position) {
  if(head == NULL) {
    return;
  }
  // Deleting Start Node
  if(position == 1) {
    Node* to_delete = head;
    to_delete->next->prev = NULL;
    head = to_delete->next;
    to_delete->next = NULL;
    delete to_delete;
  } // Deleting any Middle or Last node
  else { 
    Node* to_delete = head;
    Node* prev = NULL;

    int cnt = 1;
    while (cnt < position)
    {
        prev = to_delete;
        to_delete = to_delete->next;
        cnt++;
    }
    to_delete -> prev = NULL;
    prev -> next = to_delete -> next;
    to_delete -> next = NULL;
    
    delete to_delete;
  }
}

int main()
{
    Dll D;
    Node *node1 = new Node(10);
    D.head = node1;
    D.tail = node1;

    D.print();
    cout << "Length of list is: " << D.size() << endl;

    D.push_front(11);
    D.print();
    D.push_front(13);
    D.print();
    D.push_front(8);
    D.print();

    D.push_back(25);
    D.print();

    D.insert(2,100);
    D.print();

    D.insert(1,101);
    D.print();

    D.insert(8,102);
    D.print();

    D.erase(4);
    D.print();
    cout << "head: " << D.head->data << endl;
    cout << "tail: " << D.tail->data << endl;

    return 0;
}