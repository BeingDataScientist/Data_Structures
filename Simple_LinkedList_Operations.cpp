/*
Simple Linked list
Create
reverse
search
count
*/

#include <stdio.h>
#include <stdlib.h>

void createList(void);
void reverse(void);
void search(int);
void count(int);
void displayList(void);

struct node
{
  int data;
  struct node *next;
};

struct node *head;

int main()
{
  int choice, element;
  createList();
  do
  {
    printf("\n=========================\n1. Reverse Elements\n2. Search an Element\n3. Count an Element\n4. Display Elements \n5. Exit\nEnter Your choice here -> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      reverse();
      break;
    case 2:
      printf("Enter Element u want to search ->");
      scanf("%d", &element);
      search(element);
      break;
    case 3:
      printf("Enter Element u want to count ->");
      scanf("%d", &element);
      count(element);
      break;
    case 4:
      displayList();
      break;
    case 5:
      printf("\nSayonara..!");
      break;
    default:
      printf("\nPlease Enter Valid Choice");
    }

  } while (choice != 5);
  return 0;
}

void createList()
{
  int size;

  printf("How many element u want now ? ->");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    struct node *NewNode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter numeber %d element ->", i + 1);
    scanf("%d", &NewNode->data);
    NewNode->next = head;
    head = NewNode;
  }
}

void search(int element)
{
  int i = 1;
  struct node *temp;
  temp = head;
  if(temp == NULL)
  {
    printf("\n NO LIST EXIST!!");
  }
  else
  {
    if (element == temp->data)
    {
      printf("\n%d found at first position ", temp->data);
    }
    else
    {

      while (temp->next != NULL)
      {
        if (element == temp->data)
        {
          printf("\n%d found at position %d", temp->data, i);
          break;
        }
        else
        {
          temp = temp->next;
          i++;
        }
      }
    }
    if (element == temp->data && temp->next == NULL) //if culprit is at last node
    {
      printf("\n%d found at last postion", temp->data);
    }
    else if (temp->next == NULL)
    {
      printf("Sorry element is not in list");
    }
  }
}
void displayList()
{
  struct node *temp;
  temp = head;
  if (temp == NULL)
  {
    printf("oops list is empty!");
  }
  else
  {
    while (temp != NULL)
    {
      printf("| %d ->", temp->data);
      temp = temp->next;
    }
    printf("Null");
  }
}

void count(int element)
{
    int i = 0;
    struct node *temp;
    temp = head;
    if(temp == NULL)
    {
      printf("\n NO LIST EXIST!!");
    }
    else
    {
      while (temp->next != NULL)
      {
        if (element == temp->data)
          {
            i++;
          }
          temp = temp->next;
      }
      if (element == temp->data && temp->next == NULL) //if culprit is at last node
      {
        i++;
      }
      
      if (i)
      {
        printf("\ncount of %d is %d", element, i);
      }
      else
      {
        printf("\nSorry element is not in list");
      }
    }
}

void reverse()
{
  printf("\nReverse logic not yet ready try other");
}