#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
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
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr ->data = 64;
    ptr->link = NULL;

    head->link = ptr;

    int data = 3;

    add_end(head,data);
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }


}

