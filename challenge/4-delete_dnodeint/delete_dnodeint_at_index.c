#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a list
 *
 * @head: A pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL) /* Vérification des entrées */
        return (-1);

    current = *head;

    /* Parcourir la liste pour atteindre le nœud à l'index donné */
    for (i = 0; i < index; i++)
    {
        if (current == NULL) /* Si l'index dépasse la taille de la liste */
            return (-1);
        current = current->next;
    }

    /* Si le nœud à supprimer est le premier */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL) /* Mise à jour du pointeur précédent du nouveau head */
            (*head)->prev = NULL;
    }
    else
    {
        /* Mise à jour des liens pour le nœud précédent et suivant */
        if (current->prev != NULL)
            current->prev->next = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current); /* Libérer la mémoire du nœud supprimé */
    return (1);
}

