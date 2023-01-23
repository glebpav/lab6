#ifndef LAB6_LISTHELPER_H
#define LAB6_LISTHELPER_H

typedef struct Item {
    char sign;
    struct Item *next;
}Item;

typedef struct List {
    Item *head;
}List;

List createList();
Item *createItem(char sign);
void pushElementToList(List *list, char buf);
void printList(List list);
void modifyList(List *list);
void clearList(List *list);

#endif //LAB6_LISTHELPER_H
