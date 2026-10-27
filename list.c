#include "DS.h"

void l_push_back(List *p, int x)
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

void l_push_front(List *p, int x)
{
        Elm *new_node = (Elm *)malloc(sizeof(Elm));
        if (new_node == NULL) return;
        new_node->x = x;
        new_node->next = p->head;
        p->head = new_node;

        if (p->tail == NULL) {
                p->tail = new_node;
        }
        p->len++;
}

void l_insert(List *p, int x, int pos)
{
        if (pos <= 0 || p->head == NULL) {
                l_push_front(p, x);
                return;
        }
        if (pos >= p->len) {
                l_push_back(p, x);
                return;
        }

        Elm *new_node = (Elm *)malloc(sizeof(Elm));
        if (new_node == NULL) return;
        new_node->x = x;

        Elm *curr = p->head;
        for (int i = 0; i < pos - 1; i++) {
                curr = curr->next;
        }

        new_node->next = curr->next;
        curr->next = new_node;
        p->len++;
}

void l_pop_front(List *p)
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

void l_pop_back(List *p)
{
        if (p == NULL || p->head == NULL) return;
        if (p->head == p->tail) {
                free(p->head);
                p->head = p->tail = NULL;
                p->len = 0;
                return;
        }

        Elm *curr = p->head;
        while (curr->next != p->tail) {
                curr = curr->next;
        }

        free(p->tail);
        p->tail = curr;
        p->tail->next = NULL;
        p->len--;
}

void l_erase(List *p, int pos)
{
        if (p == NULL || pos < 0 || pos >= p->len) return;
        if (pos == 0) {
                l_pop_front(p);
                return;
        }
        if (pos == p->len - 1) {
                l_pop_back(p);
                return;
        }

        Elm *curr = p->head;
        for (int i = 0; i < pos - 1; i++) {
                curr = curr->next;
        }

        Elm *temp = curr->next;
        curr->next = temp->next;
        free(temp);
        p->len--;
}

void l_print(List *p)
{
        if (p == NULL) return;
        Elm *curr = p->head;
        while (curr != NULL) {
                printf("%d\n", curr->x);
                curr = curr->next;
        }
}

Elm *l_search(List *p, int x)
{
        if (p == NULL) return NULL;
        Elm *curr = p->head;
        while (curr != NULL) {
                if (curr->x == x) {
                        return curr;
                }
                curr = curr->next;
        }
        return NULL;
}