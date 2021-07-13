// A Simple C++ program for traversal of a linked list

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

// this function prints the content of linked list
// starting from a given node
void printlist(Node* n){
    while(n != NULL){
        cout<< n->data <<" ";
        n = n->next;
    }
}

int main(){
    // allocate 3 pointers
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third =  new Node();

    // assign values to the nodes and link nodes to each other 
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printlist(head);

    return 0;

}
