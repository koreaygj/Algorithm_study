#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;

struct node *rear = NULL;

void enqueue(int x)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = NULL;
  if (front == NULL && rear == NULL)
  {
    front = rear = newNode;
    return;
  }
  rear->next = newNode;
  rear = newNode;
}

int dequeue()
{
  struct node *temp = front;
  if (front == NULL)
  {
    printf("Queue is Empty");
    return -1;
  }
  if (front == rear)
  {
    front = rear = NULL;
  }
  else
  {
    front = front->next;
  }
  return temp->data;
}

void display()
{
  struct node *temp = front;
  while (temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main()
{

  enqueue(1);

  enqueue(2);

  enqueue(3);

  enqueue(4);

  enqueue(5);

  display();

  dequeue();

  dequeue();

  display();

  return 0;
}