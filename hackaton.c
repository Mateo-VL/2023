https : // www.hackerrank.com/test/dbdc65ic984/questions/8b1qtk7n0g2

        void
        remove_node(list_t *list, node_t *node) {
  if (list == NULL)
    return;
  if (node == NULL)
    return;
  if (list->size <= 0)
    return;
  if (list->head == NULL)
    ;
  node_t *aux = list->head;
  if (node == aux) {
    list->head = node->next;
    list->size = list->size - 1;
    free(aux);
  } else {
    for (size_t i = 0; i < list->size; i++) {
      if (aux->next != node) {
        aux = aux->next;
      } else {
        aux->next = node->next;
        free(node);
      }

      list->size -= 1;
    }
  }

  return;
}