#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a doubly linked list
 *
 * @head: A double pointer to the first element of the list
 * @n: The integer to store in the new node
 *
 * Return: A pointer to the new node, or NULL if it fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;
    dlistint_t *l;

    if (head == NULL)  /* Vérification de la validité de head */
        return (NULL);

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)  /* Si la liste est vide */
    {
        new->prev = NULL;
        *head = new;
        return (new);
    }

    l = *head;
    while (l->next != NULL)  /* Parcourt jusqu'à la fin de la liste */
        l = l->next;

    l->next = new;
    new->prev = l;

    return (new);
}

