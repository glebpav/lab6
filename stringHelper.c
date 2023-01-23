#include "stringHelper.h"
#include "stdlib.h"
#include "stdio.h"

void clearSpaces(List *list){
    Item *item = list->head;
    Item *prev = NULL;
    if(item == NULL) return;
    while (item->next != NULL) {
        if ((item->sign == ' ') && (item->next->sign == ' ')) {
            Item *buf = item->next->next;
            free(item->next);
            item->next = buf;
        } else {
            prev = item;
            item = item->next;
        }
    }

    if (list->head->sign == ' ') {
        Item *buf = list->head->next;
        free(list->head);
        list->head = buf;
    }
    if (item->sign == ' ') {
        free(item);
        prev->next = NULL;
    }
}