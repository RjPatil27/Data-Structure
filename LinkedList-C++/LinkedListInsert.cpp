/* A program to insert a new node in linked list.
A node can be added in three ways
1) At the front of the linked list
2) After a given node
3) At the end of the linked list
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    //1. Allocate node
    Node* new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    //3. Make next of the new node as head
    new_node->next = (*head_ref);

    //4. move the head to point to the new node
    (*head_ref) = new_node;
}

void append(Node** head_ref, int new_data){
    //1. allocate node
    Node* new_node = new Node();

    Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

void insertAfter(Node* prev_node, int new_data){
    //1. Check if the given previous node is NULL
    if(prev_node == NULL){
        cout<<"Previous Node can not be null";
    }

    // 2. allocate new node
    Node* new_node = new Node();

    // 3. Put in the data
    new_node->data=new_data;

    // 4. Make next of new node as next of previous Node
    new_node->next = prev_node->next;

    // 5. Move the next of previous node as new_node
    prev_node->next = new_node;
}

void printlist(Node* n){
    while(n != NULL){
        cout<<" "<<n->data;
        n = n->next;
    }
}

int main(){
    // start with the empty list
    Node* head = NULL;

    append(&head,7);
    push(&head,10);
    insertAfter(head,2);
    append(&head,4);
    printlist(head);
}
