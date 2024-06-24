#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void add_at_pos(struct node* head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos!=1)
    {
        ptr= ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
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

    int data = 56, position =3;
    add_at_pos(head,data,position);

    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }


}

