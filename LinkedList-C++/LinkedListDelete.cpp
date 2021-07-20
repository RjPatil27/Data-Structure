/*
A program for deletion of node in linked list.
To delete a node from a linked list, we have to understand only 
3 steps,
1) Find the previous node of the node to be deleted
2) Change the next of the previous node
3) Free memory for the node to be deleted
*/

#include<iostream>
using namespace std;

// Create a structure of Node
struct Node{
    int data;
    Node* next;
};

// Push() function to push data in linked list
void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

// DeleteNode() function to delete a node from linked list.
void DeleteNode(Node** head_ref, int deletekey){
    Node* temp = *head_ref;
    Node* prev = NULL;

    if(temp!=NULL && temp->data==deletekey){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else{
        while (temp!=NULL && temp->data!=deletekey)
        {
            prev=temp;
            temp = temp->next;
        }
        
        if(temp==NULL){
            return;
        }
        prev->next = temp->next;

        delete temp;
    }
}

// Function to print entire linked list
void printlist(Node* node){
    while (node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }    
}

int main(){
    Node* head = NULL;
    push(&head,8);
    push(&head,3);
    push(&head,5);
    DeleteNode(&head,3);
    push(&head,11);
    push(&head,13);
    DeleteNode(&head,5);
    printlist(head);

    return 0;
}
