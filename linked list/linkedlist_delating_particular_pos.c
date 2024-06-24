
//Deleting last node in linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void del_pos(struct node **head , int pos)
{
    struct node *current = *head;
    struct node *pre = *head;
    if(*head == NULL) printf("List is already empty!");
    else if(pos==1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos!=1)
        {
            pre = current;
            current = current->link;
            pos--;
        }
        pre->link = current->link;
        free(current);
        current = NULL;
    }
}

void add_end(struct node *head ,int d)
  {
      struct node *ptr, *temp;
      ptr = head;
      temp = (struct node*)malloc(sizeof(struct node));

      temp->data = d;
      temp->link = NULL;

      while(ptr->link!= NULL)
      {
          ptr = ptr->link;
      }
      ptr->link = temp;
  }
int main()
{
    struct node *head,*ptr;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_end(head,90);
    add_end(head,32);

   //head = del_first(head);
   int pos = 2;
   del_pos(&head, pos);
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }


}

