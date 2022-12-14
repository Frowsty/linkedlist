/**
 * @file main.c
 * @author Frosty
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    struct node* next;
};

/**
 * @brief Populates the list with n amount
 * @param[in] list Linked-list of type **node
 * @param[in] amount Amount to populate the linked-list with
 * */
void populateList(struct node** list, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->id = i;
        newNode->next = *list;
        *list = newNode;
    }
}

/**
 * @brief Append node to start of linked list
 * @param[in] list Linked-list of type **node
 * */
void appendStart(struct node** list)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // if the list is empty to begin with we will set the list to our new node
    if (*list == NULL)
    {
        newNode->id = 0;
        newNode->next = NULL;
        *list = newNode;
        return;
    }


    newNode->id = (*list)->id + 1;
    newNode->next = *list;

    *list = newNode;
}

/**
 * @brief Append node to end of linked list
 * @param[in] list Linked-list of type **node
 * */
void appendEnd(struct node** list)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->id = 0;
    newNode->next = NULL;

    // if the list is empty to begin with we will set the list to our new node
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    struct node* temp = *list;

    // increment all node IDs since there will now be a "new" index 0
    while (temp->next != NULL)
    {
        temp->id += 1;
        temp = temp->next;
    }

    temp->id += 1;
    temp->next = newNode;
}

/**
 * @brief Remove node at index
 * @param[in] list Linked-list of type **node
 * @param[in] index Index of node to be removed
 * */
void removeNode(struct node** list, int index)
{
    struct node* temp = *list;
    struct node* prev = *list;

    // check if the first node is our target to be removed
    if (temp != NULL && temp->id == index)
    {
        *list = temp->next;
        free(temp);
        return;
    }
    // if first node is not our target we will continue searching
    while (temp != NULL && temp->id != index)
    {
        prev = temp;
        temp = temp->next;
    }

    // if temp is null we have hit the end of the linked list and should return to exit the function
    if (temp == NULL)
        return;

    // remove the node from our list
    prev->next = temp->next;
    // free the memory that said node was using
    free(temp);
}

/**
 * @brief Print the linked list
 * @param[in] list Linked-list of type *node
 * */
void printList(struct node* list)
{
    while (list != NULL)
    {
        printf("node [%p], id: %d\n", list,list->id);
        list = list->next;
    }
}

int main(int argc, char** argv)
{
    struct node* myList = NULL;

    populateList(&myList, 5);
    appendEnd(&myList);
    printList(myList);
    return 0;
}