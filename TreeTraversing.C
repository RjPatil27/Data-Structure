/*
This is code for Tree traversing which gives output of INORDER,PREORDER,POSTORDER traversing of given 5 Node tree.
You can modify it by taking nodes from user also.
This code is for basic understanding of Traversing of Tree.
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
  Node(int data)
  {
    this->data  = data;
    left = right = NULL;
  }
};

void Inorder(struct Node *node)
{
  if(node == NULL)
     return;
  Inorder(node->left);
  cout<<node->data<<" ";
  Inorder(node->right);
}

void Preorder(struct Node* node)
{
  if(node == NULL)
    return;
  cout<<node->data<<" ";
  Preorder(node->left);
  Preorder(node->right);

}

void Postorder(struct Node* node)
{
  if(node == NULL)
     return ;

   Postorder(node->left);
   Postorder(node->right);
   cout<<node->data<<" ";
}


int main()
{
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout<<"\nInorder Traversal is  : \n";
  Inorder(root);
  cout<<"\nPreorder Traversal is : \n";
  Preorder(root);
  cout<<"\nPostorder Traversal is : \n";
  Postorder(root);
 return 0;
}
