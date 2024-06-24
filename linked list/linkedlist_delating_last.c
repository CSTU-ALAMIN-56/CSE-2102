//Deleting last node in linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* del_first(struct node *head)
{
    if(head == NULL) printf("list is already empty!");
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp= head;
        struct node *temp2 = head;
        while(temp->link !=NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
};
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

   head = del_first(head);
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }


}

