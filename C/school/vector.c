#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int Stack[SIZE], choice, top;

void push(int x)
{
  if (top + 1 >= 100)
  {
    printf("메모리 초과");
    return;
  }

  Stack[top + 1] = x;
  top++;
  return;
}

int pop()
{
  if (top < 0 || top >= 100)
  {
    return -1;
  }
  int result = Stack[top];
  Stack[top] = 0;
  top--;
  return result;
}

void display()
{
  for (int i = top; i >= 0; i--)
  {
    printf("%d\n", Stack[i]);
  }
}

int main()
{
  top = -1;

  push(1);

  push(2);

  push(3);

  push(4);

  push(5);

  display();

  pop();

  pop();

  display();

  return 0;
}