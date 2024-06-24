#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int searcing(struct node *head,int item)
{
    int LOC=0;
     if(head == NULL)printf("linked list is empty");
    struct node *ptr = NULL;
    ptr = head;

    do
    {
        if(ptr->data == item) return LOC;
        ptr = ptr->next;
        LOC++;
    }while(ptr!=NULL);
    return -1;

}

void traverse(struct node *head)
{

    if(head == NULL)printf("linked list is empty");
    struct node *ptr = NULL;
    ptr = head;

    while(ptr!=NULL)
    {

        ptr= ptr->next;
        printf("%d\n",ptr->data);

    }

}
int main()
{
    int item;
struct node *head, *first,*second, *third, *newnode;
    head = (struct node*) malloc(sizeof(struct node));
    first = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->next = first;
    first->data = 78;
    first->next = second;
    second ->data = 987;
    second->next = third;
    third->data = 9798;
    third->next = NULL;

    printf("Write finding item\n");
    scanf("%d",&item);
   int LOC=  searcing(head,item);
    printf("%d\n",LOC);
   //traverse(head);
}

