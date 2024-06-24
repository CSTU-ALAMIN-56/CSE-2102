#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
    void print(struct node *p)
    {
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
    }
    void insert(struct node *ptr1, struct node *ptr2)
    {
        ptr2->next = ptr1;
        ptr1 = ptr2;
    }
int main()
{
    struct node *head, *first,*second, *third, *newnode;
    head = (struct node*) malloc(sizeof(struct node));
    first = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    newnode = (struct node*) malloc(sizeof(struct node));

    head->next = first;
    first->data = 78;
    first->next = second;
    second ->data = 987;
    second->next = third;
    third->data = 9798;
    third->next = NULL;
    newnode->data = 88;
    insert(head,newnode);
    print(newnode);

}
