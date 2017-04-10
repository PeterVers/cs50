/* Program to make a linked list capable of searching through the list for a particular value, insertion, deletion of the linked list, and 
deletion of a single element within the list. */

#include <stdio.h>
#include <cs50.h>

// Define a structure called node to contain the elements for a linked list.

typedef struct llist
    {
        int value;
        struct llist *next;
    }
    node;

node *head = NULL;
int var_count = 1;
// Make a function that creates a linked list containing a single element and a pointer to NULL.
node* create(int val)
{
    // n is here because I don't give a shit right now. 
    node *n = malloc(sizeof(node));
    if(n == NULL)
    {
        fprintf(stderr, "Not enough memory available.\n");
        return 0;
    }
    n->value = val;
    n->next = NULL;
    return n;
}

// Make a function that searches the linked list and returns true if it finds the chosen value.
bool find(node *head, int val_seek)
{
    while(head != (node *) 0)
    {
        if(head->value == val_seek)
        {
            printf("The value is in the list.\n");
            return true;
        }
        else
        {
            printf("Not yet...\n");
            printf("%i\n", head->value);
            head = head->next;
        }
    }
    printf("The value is not in the list.\n");
    return false;
}

node *insert(node **head, int val_insert)
{
    node *temp = malloc(sizeof(node));
    if(temp == NULL)
    {
        fprintf(stderr, "Not enough memory available.\n");
        return 0;
    }
    temp->value = val_insert;
    temp->next = *head;
    *head = temp;
    return temp;
}

int main(void)
{
    //Establish a linked list that holds no current value.
    node *n1, *n2, *n3;
    n1 = create(6);
    head = n1;
    n2 = insert(&head, 12);
    n3 = insert(&head, 42);
    printf("%i\n", head->value);
    find(head, 6);
    free(n1);
    free(n2);
    return 0;
}
