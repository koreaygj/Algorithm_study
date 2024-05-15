#include <stdio.h>

#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} stack;

stack *top = NULL;

void push(int x)
{
  stack *newNode = malloc(sizeof(stack));
  newNode->data = x;
  newNode->next = top;
  top = newNode;
  return;
}

int pop()
{
  stack *temp = top;
  top = top->next;
  free(temp);
  return temp->data;
}

void print_s()
{
  stack *current = top;
  while (current != NULL)
  {
    printf("%d\n", current->data);
    current = current->next;
  }
}

int main()
{
  push(1);

  push(2);

  push(3);

  push(4);

  push(5);

  print_s();

  pop();

  pop();

  print_s();
}