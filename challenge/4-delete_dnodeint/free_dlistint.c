#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Free a doubly linked list
 *
 * @head: A pointer to the first element of the list
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *node;

    while (head)
    {
        node = head;         /* Sauvegarde du pointeur actuel */
        head = head->next;   /* Avance au nœud suivant */
        free(node);          /* Libération de la mémoire du nœud actuel */
    }
}
