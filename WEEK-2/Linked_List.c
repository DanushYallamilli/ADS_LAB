#include <stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node *next;
};
struct node* head = NULL, *temp;

void insert()
{
  int sch, pos = 0, x;
  printf("\n1.Insert at Begining\n2.Insert at End\n3.Insert at a position\n");
  scanf("%d", &sch);
  printf("Enter the data :\n");
  scanf("%d", &x);

  if (sch == 3)
  {
    printf("Enter the position:\n");
    scanf("%d", &pos);
  }
  if(pos< 0)
  {
    printf("Out of bounds\n");
    return;
  }

  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;

  if (sch == 1 || (sch == 3 && pos == 1) || head == NULL )
  {
    temp->next = head;
    head = temp;
    return;
  }

  if(sch == 2)
  {
    struct node* t = head;
    while(t->next != NULL)
    {
      t = t->next;
    }
    t->next = temp;
    return; 
  }

  if(sch == 3)
  {
    struct node* t = head;
    int c = 1;
    while(c < pos - 1 && t->next != NULL)
    {
      t = t->next;
      c++;
    }
    if(t == NULL)
    {
      printf("Out of bounds\n");
      free(temp);
    }
    else
    {
      temp->next = t->next;
      t->next = temp;
    }
  }
}


void delete()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  int sch, pos = 0;
  printf("\n1.Delete at Begining\n2.Delete at End\n3.Delete at a position\n");
  scanf("%d", &sch);
  if(sch == 3)
  {
    printf("Enter position:\n");
    scanf("%d",&pos);
  }

  struct node* t = head;

  if(sch == 1 || (sch == 1 && pos ==1) || head->next == NULL)
  {
    head = t->next;
    printf("Deleted node: %d\n",t->data);
    free(t);
  }


  if (sch == 2) 
  {
    while (t->next->next)
    {
      t = t->next;
    }
    free(t->next);
    t->next = NULL;
    printf("Node deleted successfully.\n");
    return;
  }


  if(sch == 3)
  {
    int c =1;
    struct node* temp;

    while(c < pos-1 && t->next != NULL)
    {
      t = t->next;
      c++;
    }

    if(t == NULL || t->next == NULL)
    {
      printf("Out of bounds\n");
    }
    else
    {
      temp = t->next;
      t->next = temp->next;
      printf("Deleted node: %d\n",temp->data);
      free(temp);
    }
  }
}

int search(int key)
{
  temp = head;
  int pos = 1;
  while (temp != NULL) 
  {
    if (temp->data == key)
    {
      return pos;
    }
    temp = temp->next;
    pos++;
  }
  return -1;
}

void display()
{

  temp = head;

  if(temp == NULL)
  {
    printf("List is empty\n");
  }
  

  printf("LIST:\n");
  while(temp != NULL)
  {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// //Function to display alternate elements
// void alt_display()
// {
//   printf("LIST:\n");
//   int c = 2;
//   while(temp != NULL)
//   {
//     if(c%2 == 0)
//     {
//       printf("%d -> ", temp->data);
//       temp = temp->next;
//     }
//   }
//   printf("NULL\n");
// }

int main()
{
  while(1)
  {
    int ch;
    printf("\nMENU:\n");
    printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      {
        insert();
        break;
      }
      case 2:
      {
        delete();
        break;
      }
      case 3:
      {
        int k;
        printf("Enter the element to search:\n");
        scanf("%d",&k);
        if(search(k)!= (-1))
        {
          printf("Element %d is found at %d position",k,search(k));
        }
        else
        {
          printf("Element is not found in the list.\n");
        }
        break;
      }
      case 4:
      {
        display();
        break;
      }
      case 5:
      {
        printf("Exitting...\n");
        return 0;
      }
      default:
      {
        printf("Invalid input.\n");
        break;
      }
      
    }
  }

}