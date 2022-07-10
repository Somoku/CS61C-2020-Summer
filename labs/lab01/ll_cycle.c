#include "ll_cycle.h"
#include <stddef.h>

int ll_has_cycle(node *head) {
    /* your code here */
    if (!head)
        return 0;
    node *hare = head, *tortoise = head;
    do {
        for (int i = 0; i < 2; i++) {
            if (hare->next != NULL)
                hare = hare->next;
            else
                return 0;
        }
        tortoise = tortoise->next;
    } while (hare != tortoise);
    return 1;
}