#include "lists.h"
#include <stdlib.h>

/**

* delete_dnodeint_at_index - deletes the node at index index of a dlistint_t
* @head: pointer to head of the list
* @index: index of the node to delete
*
* Return: 1 if it succeeded, -1 if it failed
  */
  int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
  {
  dlistint_t *current;
  unsigned int i = 0;

  if (head == NULL || *head == NULL)
  return (-1);

  current = *head;

  /* Cas 1 : suppression du head */
  if (index == 0)
  {
  *head = current->next;
  if (*head != NULL)
  (*head)->prev = NULL;
  free(current);
  return (1);
  }

  /* Parcourir jusqu'à l'index */
  while (current != NULL && i < index)
  {
  current = current->next;
  i++;
  }

  if (current == NULL)
  return (-1);

  /* Reconnecter les noeuds */
  if (current->prev != NULL)
  current->prev->next = current->next;

  if (current->next != NULL)
  current->next->prev = current->prev;

  free(current);
  return (1);
  }
