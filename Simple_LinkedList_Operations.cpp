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
void insertEl(void);
void deleteEl(void);
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
    printf("\n=========================\n1. Reverse Elements\n2. Search an Element\n3. Count an Element \n4. Insert Element \n5. Delete Element \n6. Display Elements \n7. Exit\nEnter Your choice here -> ");
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
        insertEl();
        break;
    case 5:
        deleteEl();
        break;
    case 6:
        displayList();
        break;
    case 7:
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

void insertEl()
{
  int choice,pos;
  int i=0;

  struct node *temp,*prevNode,*nextNode;
  struct node *NewNode = (struct node *)malloc(sizeof(struct node *));
  
  printf("-----------------------------------------\n\t0. Insert at Beginnig \n\t1. Insert at End \n\t2. Insert at given position \n\t3. Back To Menu\nChoose where to insert -> ");
  scanf("%d", &choice);
  
  printf("\nEnter Your Element->");
  scanf("%d",&NewNode->data);
  
  switch (choice)
  {
    do
    {
    case 0: NewNode->next = head;
            head = NewNode;
            printf("\nNode inserted in front\n");
    break;
    case 1:
            if (head==NULL)
            {
              head=NewNode;
              NewNode->next=NULL;
              printf("%d Inagurated your linked list ",NewNode->data);
            }
            else{
                  temp=head;
                  while (temp->next != NULL)
                  {
                    temp = temp->next;
                  }
                  temp->next=NewNode;
                  NewNode->next=NULL;
                  printf("\nNode inserted at last\n");
                }
    break;
    case 2:printf("\nEnter the position ->");
           scanf("%d",&pos);
            if (head==NULL && pos==1)
            {
              head=NewNode;
              NewNode->next=NULL;
              printf("%d Inagurated your linked list ",NewNode->data);
            }
            else if (head==NULL)
            {
              printf("Invalid Position !");
            }
            else if(pos>1)
            {     
              i=1;//we are at pos 2
                  temp=head;
                  while (temp->next != NULL)
                  {
                    if(pos==i)
                    {
                     prevNode->next=NewNode;
                     NewNode->next=temp;
                     break;   
                    }
                    else
                    {
                      prevNode=temp;
                      temp = temp->next;
                      i++;
                    }
                  }
                  if(i==pos && temp->next == NULL)
                  {
                      temp->next=NewNode;
                      NewNode->next=NULL;
                      printf("\n%d inserted at %d\n",NewNode->data,pos);
                  }
                  else
                  {
                     printf("Position out of range");
                  }
                  
            }
    break;
    case 3:printf("\nGoing Back To Menu..........");break;
    
    default:printf("\nEnter valid choice!");
    } while (choice != 3);
  }

} 
void deleteEl()
{
    int choice, element;
    struct node *temp;
    struct node *prevNode;
    printf("--------------------------------\n\t0. Delete at Beginnig \n\t1. Delete at End \n\t2. Delete any element \n\t3. Back To Menu\nChoose where to delete -> ");
    scanf("%d", &choice);
  switch (choice)
  {
      do
      {
          case 0:
                temp = head;
                if(temp==NULL)
                {
                  printf("UNDERFLOW.... Oops list already empty!");
                }
                else
                {
                  head = head->next;
                  printf("\nFirst Elment %d deleted succefully",temp->data);
                  free(temp);
                }
                break;
          case 1:
                
                temp = head;
                while (temp->next != NULL)
                {
                  prevNode = temp;
                  temp = temp->next;
                }
                prevNode->next = NULL;
                printf("\nLast Element %d deleted successfully",temp->data);
                free(temp);
                break;
          case 2:
                printf("\nEnter Your Element->");
                scanf("%d",&element);  
                temp = head;
                printf("\nEnter Element to delete ->");
                scanf("%d", &element);
                while (temp->next == NULL)
                {
                  printf("h");
                }
                break;
          case 3:
                printf("Delete any");
                break;
          
          default:printf("Enter valid choice!");
      }while (choice != 3);
  }
}