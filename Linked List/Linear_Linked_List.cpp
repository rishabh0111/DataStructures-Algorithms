#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;

    // Constructor
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
};

class LinkedList {
  public:
    Node* head;
    Node* tail;

    void push_front(int d);
    void push_back(int d);
    void insert(int position, int d);
    bool search(int x);
    void erase(int val);
    void print();
    bool empty();

    LinkedList() { head = NULL; }
};

// Insert element at Front
void LinkedList::push_front(int d) {
  Node* temp = new Node(d);
  temp -> next = head;
  head = temp;
}

// Insert element at Back
void LinkedList::push_back(int d) {
  Node* temp = new Node(d);
  tail-> next = temp;
  tail = temp;
}

// Insert element at required position
void LinkedList::insert(int position, int d) {
  //Inserting at start
  if(position == 1) {
    push_front(d);
    return;
  }

  Node *temp = head;
  int cnt = 1;
  while (cnt < position - 1)
  {
    temp = temp -> next;
    cnt++;
  }

  //Inserting at last
  if(temp -> next == NULL) {
    push_back(d);
    return;
  }

  Node *nodeToInsert = new Node(d);
  nodeToInsert -> next = temp -> next;
  temp -> next = nodeToInsert;
}

// Search for element //Iterative Approach:
bool LinkedList::search(int x) {
  Node* current = head;
  while(current != NULL) {
    if(current->data == x)
      return true;
    current = current->next;
  }
  return false;
}

// Search for element // Recursive Approach:
// After uncommenting change function definition accordingly
// bool LinkedList::search(Node* &head,int x) {
//   if(head == NULL)
//     return false;
//   if(head->data == x)
//     return true;
//   return search(head->next,x);
// }

// Delete element in list:
void LinkedList::erase(int val) {

  if(head == NULL) {
    return;
  }
  // Deleting Start Node
  if(head->data == val) {
    Node* to_delete = head;
    head = head->next;
    delete to_delete;
    return;
  }
  
  // Deleting any Middle or Last node
  Node* temp = head;
  while(temp->next->data != val) {
    temp = temp->next;
  }

  Node* to_delete = temp->next;
  temp->next = temp->next->next;

  delete to_delete;
}

// Print List
void LinkedList::print() {
  Node* temp = head;

  while(temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

// List empty or not
bool LinkedList::empty() {
  if(head == NULL)
    return 1;
  else
    return 0;
}


int main() {
  LinkedList L;
  Node* node1 = new Node(10);

  L.head = node1;
  L.tail = node1;

  L.print();
  L.push_front(12);
  L.push_front(15);
  L.print();

  L.push_back(21);
  L.push_back(24);
  L.print();

  L.insert(6,44);
  L.print();

  cout << "head: " << L.head->data << endl;
  cout << "tail: " << L.tail->data << endl;
  
  L.search(21) ? cout << "Yes": cout << "No";
  cout << endl;
  L.search(33) ? cout << "Yes": cout << "No";
  cout << endl;

  L.empty() ? cout << "List is empty": cout << "List is not empty";
  cout << endl;

  L.erase(15); // deleting first node
  L.erase(21); // deleting middle node
  L.erase(44); // deleting last node
  L.print();

  return 0;
}
