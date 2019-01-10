//Code for Linked list stack example

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
 char *str;
 struct node *next;
} STACKNODE;

void push(char *key, STACKNODE **stack);
char *pop(STACKNODE **stack);
int isempty(STACKNODE *stack);
char top(STACKNODE *stack);

int main() {
 char line[1024];
 char *key;
 STACKNODE *stack;

 stack = NULL;
 while((fgets(line, 1024, stdin)) != NULL)
  key = line, push(key, &stack);
 
 while(!isempty(stack))
  printf("%s", pop(&stack));

 return 0;
}

char top(STACKNODE *stack) {
 return *stack->str;
}

void push(char *line, STACKNODE **stack) {
 STACKNODE *newnode;

 newnode = (STACKNODE *)malloc(sizeof(STACKNODE));
 newnode->str = strdup(line);
 newnode->next = (*stack);
 (*stack) = newnode;
}

char *pop(STACKNODE **stack) {
 STACKNODE *oldnode;
 char *key;
 char *retval;

 oldnode = (*stack);
 key = (*stack)->str;
 (*stack) = (*stack)->next;
 free(oldnode);

 retval = calloc(strlen(key)+1, sizeof(char));
 strcpy(retval, key);
 return retval;
 free(retval);
}

int isempty(STACKNODE *stack) {
 return stack == NULL;
}
