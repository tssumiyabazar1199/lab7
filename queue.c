#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        Elm *new_node = (Elm *)malloc(sizeof(Elm));
        if (new_node == NULL) return;
        new_node->x = x;
        new_node->next = NULL;

        if (p->tail == NULL) {
                p->head = p->tail = new_node;
        } else {
                p->tail->next = new_node;
                p->tail = new_node;
        }
        p->len++;
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
        if (p == NULL || p->head == NULL) return;
        Elm *temp = p->head;
        p->head = p->head->next;
        if (p->head == NULL) {
                p->tail = NULL;
        }
        free(temp);
        p->len--;
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
        if (p == NULL) return;
        Elm *curr = p->head;
        while (curr != NULL) {
                printf("%d\n", curr->x);
                curr = curr->next;
        }
}