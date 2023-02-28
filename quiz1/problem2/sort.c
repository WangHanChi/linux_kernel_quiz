#include <stdint.h>
#include "list.h"

static inline int cmpint(element_t *p1, element_t *p2)
{
    return strcmp(p1->value,p2->value);
}
#define MAX_DEPTH 512
/* Sort elements of queue in ascending order */
void q_sort(struct list_head *head)
{
    // if (!head || list_empty(head))
    //     return;
    // // cut off the link
    // head->prev->next = NULL;
    // head->next = merge_divide(head->next);

    // struct list_head *before = head, *after = head->next;
    // for (; after != NULL; after = after->next) {
    //     after->prev = before;
    //     before = after;
    // }
    // before->next = head;
    // head->prev = before;
    if (list_empty(head) || list_is_singular(head))
        return;

    struct list_head stack[MAX_DEPTH];
    for (int i = 0; i < MAX_DEPTH; i++)
        INIT_LIST_HEAD(&stack[i]);
    int top = -1;
    list_splice_init(head, &stack[++top]);

    struct list_head partition;
    INIT_LIST_HEAD(&partition);

    while (top >= 0) {
        INIT_LIST_HEAD(&partition);
        list_splice_init(&stack[top--], &partition);
        if (!list_empty(&partition) && !list_is_singular(&partition)) {
            struct list_head list_less, list_greater;
            INIT_LIST_HEAD(&list_less);
            INIT_LIST_HEAD(&list_greater);
            element_t *pivot =
                list_first_entry(&partition, element_t, list);
            list_del(&pivot->list);
            INIT_LIST_HEAD(&pivot->list);

            element_t *itm = NULL, *is = NULL;
            list_for_each_entry_safe (itm, is, &partition, list) {
                list_del(&itm->list);
                if (cmpint(itm, pivot) < 0)
                    list_move(&itm->list, &list_less);
                else
                    list_move(&itm->list, &list_greater);
            }

            list_move_tail (&pivot->list, &list_less);
            if (!list_empty(&list_greater))
                list_splice_tail(&list_greater, &stack[++top]);
            if (!list_empty(&list_less))
                list_splice_tail(&list_less, &stack[++top]);
        } else {
            top++;
            list_splice_tail(&partition, &stack[top]);
            while (top >= 0 && list_is_singular(&stack[top])) {
                element_t *tmp =
                    list_first_entry(&stack[top], element_t, list);
                list_del(&tmp->list);
                INIT_LIST_HEAD(&stack[top--]);
                list_add_tail(&tmp->list, head);
            }
        }
    }
}
