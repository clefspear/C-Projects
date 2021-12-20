/*
 Created by Peter Azmy 5 April 2018
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR_LEN 80

struct link_node
{
    char node_word[MAX_STR_LEN];
    struct link_node *next;
};


struct link_node *add_node (struct link_node *list, struct link_node *node)
{
    if (list == '\0')
    {
        return node;
    }
    struct link_node *placeholder= list;
    if (compare_node (node , placeholder) == -1)
    {
        node->next = placeholder;
        return node;
    }
    while (placeholder->next != '\0')
    {
        if (compare_node (node, placeholder->next) == -1)
        {
            node -> next = placeholder-> next;
            placeholder-> next = node;
            return list;
        }
        else
        {
            placeholder= placeholder-> next;
        }
    }
    placeholder-> next = node;
    return list;
}



int compare_node (struct link_node *node1, struct link_node *node2)
{
    int i = 0;
    for (i = 0; node1->node_word[i] != '\n' || node2->node_word[i] != '\n'; i++)
    {
        if (node1->node_word[i] < node2->node_word[i])
        {
            return -1;
        }
        else if (node1->node_word[i] > node2->node_word[i])
        {
            return 1;
        }
    }
    if (node1->node_word[i] != '\n')
    {
        return 1;
    }
    else if (node2->node_word[i] != '\n')
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


void
display_list (struct link_node *head)
{
    while (head != '\0')
    {
        printf ("%s\n", head->node_word);
        head = head->next;
    }
}

int
main ()
{
    printf ("Please enter String.Press enter twice when done.\n");
    struct link_node *head = '\0';
    struct link_node *placeholder;
    while (1)
    {
        char word[MAX_STR_LEN];
        fgets (word, MAX_STR_LEN, stdin);
        if (word[0] == '\n')
        {
            break;
        }
        placeholder= malloc (sizeof (struct link_node));
        int i;
        for (i = 0; word[i] != '\n'; i++)
        {
            placeholder->node_word[i] = word[i];
            placeholder->next = '\0';
        }
        head = add_node (head, placeholder);
    }
    display_list (head);
    free (placeholder);
    return 0;
}

