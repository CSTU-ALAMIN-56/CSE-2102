#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
{
    int count = 0;
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

   traverse(head);
}
