#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node *next;

    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
};

class LinkedList {
  public:
    Node* head;

    void push_front(Node* &head, int d);
    void push_back(Node* &tail, int d);
    Node* back();
    Node* search(int x);
    Node* erase(int x);
    void print(Node* &head);
    bool empty();

    LinkedList() { head = NULL; }
};

// Insert element at Front
void LinkedList::push_front(Node* &head, int d) {
  Node* temp = new Node(d);
  temp -> next = head;
  head = temp;
}

// Insert element at Back
void LinkedList::push_back(Node* &tail, int d) {
  Node* temp = new Node(d);
  tail -> next = temp;
  tail = temp;
}

// Returns last element
Node *LinkedList::back() {
  Node* ptr = head;
  while(ptr->next != NULL) {
    ptr = ptr->next;
  }
  return ptr;
}

// Search for element
Node* LinkedList::search(int x) {
  Node* ptr = head;
  while(ptr->next != NULL && ptr->data != x) {
    ptr = ptr->next;
  }
  return ptr;
}

// Delete an element
Node* LinkedList::erase(int x) {
  Node* n = search(x);
  Node* ptr = head;
  if (ptr == n) {
    ptr->next = n->next;
    return n;
  } else {
    while(ptr->next != n) {
      ptr = ptr->next;
    }
    n->next = ptr->next;
    return n;
  }
}

// Print List
void LinkedList::print(Node* &head) {
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

  Node* head = node1;
  Node* tail = node1;

  L.print(head);
  L.push_front(head,12);
  L.push_front(head,15);
  L.print(head);

  L.push_back(tail,21);
  L.push_back(tail,24);
  L.print(head);

  // L.search(21);

  return 0;
}
