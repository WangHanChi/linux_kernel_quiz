#include <stdint.h>
#include "list.h"

static inline int cmpint(element_t *p1, element_t *p2)
{
    return strcmp(p1->value,p2->value);
}

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

    struct list_head list_less, list_greater;
    INIT_LIST_HEAD(&list_less);
    INIT_LIST_HEAD(&list_greater);

    element_t *pivot = list_first_entry(head, element_t, list);
    list_del(&pivot->list);

    element_t *itm = NULL, *is = NULL;
    list_for_each_entry_safe (itm, is, head, list) {
        if (cmpint(itm, pivot) < 0)
            list_move_tail (&itm->list, &list_less);
        else
            list_move_tail (&itm->list, &list_greater);
    }

    q_sort(&list_less);
    q_sort(&list_greater);

    list_add(&pivot->list, head);
    list_splice(&list_less, head);
    list_splice_tail(&list_greater, head);
}
