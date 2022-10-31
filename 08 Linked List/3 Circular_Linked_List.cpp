#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    // Constructor
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
};

class Cll {
    public:
    Node* tail; 
    
    void insert(int element, int d);
    void print();
    void erase(int val);

    Cll() {
        tail = NULL;
    }
};

void Cll::insert(int element, int d) {
    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list
        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element's node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

void Cll::print() {
    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void Cll::erase(int val) {
    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    } else{ //non-empty
        //assuming that "val" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != val) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1-node linked List
        if(curr == prev) {
            tail = NULL;
        }
        //>=2-node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }
}

int main()
{
    Cll C;
    C.tail = NULL;

    C.insert(5, 3);
    C.print();

    C.insert(3, 5);
    C.print();

    C.insert(5, 7);
    C.print();

    C.insert(7, 9);
    C.print();

    C.insert(5, 6);
    C.print();

    C.insert(9, 10);
    C.print();

    C.insert(3, 4);
    C.print();

    C.erase(6);
    C.print();
    return 0;
}