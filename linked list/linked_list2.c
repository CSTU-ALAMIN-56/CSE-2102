#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;

void traverse_nodes(node *p)
{
    if(p == NULL)
    {
        printf("Linked list is empty");
    }
    node *ptr = NULL;
    ptr = p;
    while(ptr!=NULL)
    {
        printf("%d\n",&ptr->data);
        ptr = ptr->link;
    }
    //printf("Number of nodes = %d",&count);
}
void count_of_nodes(node *p)
{
    int count = 0;
    if(p == NULL)
    {
        printf("Linked list is empty");
    }
    node *ptr = NULL;
    ptr = p;
    while(ptr!=NULL)
    {
        count++;
        printf("%d\n",&ptr->data);
        ptr = ptr->link;
    }
    printf("Number of nodes = %d",&count);
}
void insert_first(node *p,int data)
{
    node *ptr;
    node *temp = malloc (sizeof(node));
    ptr = p;
    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

int main()
{
    node *head = malloc(sizeof(struct node));
    head->data = 678;
    head->link = NULL;

    node *current = malloc(sizeof(node));
    current->data = 87;
    head->link = current;

    current = malloc (sizeof (node));
    current->data = 989;
    current->link = NULL;
    head->link->link = current ;

    count_of_nodes(head);
    insert_first(head,44);
    traverse_nodes(head);
}

