#include "listHelper.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

List createList() {
    List list;
    list.head = NULL;
    return list;
}

void printList(List list) {
    Item *nextItem = list.head;
    printf("\"");
    while (nextItem != NULL) {
        printf("%c", nextItem->sign);
        nextItem = nextItem->next;
    }
    printf("\"");
}

Item *createItem(char sign) {
    struct Item *item = malloc(sizeof(Item));
    item->sign = sign;
    item->next = NULL;
    return item;
}

void pushElementToList(List *list, char sign) {

    if (sign == '\t') sign = ' ';
    Item *item = createItem(sign);

    if (list->head == NULL) {
        list->head = item;
    } else {
        Item *nextItem = list->head;
        while (nextItem->next != NULL) {
            nextItem = nextItem->next;
        }
        nextItem->next = item;
    }
}

void clearList(List *list) {
    Item *item = list->head;
    if (item == NULL) return;
    while (item->next != NULL) {
        Item *buf = item->next;
        free(item);
        item = buf;
    }
    free(item);
}

void modifyList(List *list) {
    Item *item = list->head;
    Item *prev = NULL;
    bool isCharSelected = false;
    char firsChar;
    while (item != NULL) {
        if (isCharSelected) {
            if (item->sign == ' ') {
                isCharSelected = false;
                prev = item;
                item = item->next;
            } else if (item->sign == firsChar) {
                Item *buf = item->next;
                free(item);
                prev->next = buf;
                item = buf;
            } else {
                prev = item;
                item = item->next;
            }

        } else {
            firsChar = item->sign;
            isCharSelected = true;
            prev = item;
            item = item->next;
        }
    }
}