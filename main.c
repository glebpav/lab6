#include <stdio.h>
#include "listHelper.h"
#include "stringHelper.h"
#include "stdio.h"

int main() {
    List list = createList();

    char buf = (char) getchar();
    while (buf != '\n') {
        pushElementToList(&list, buf);
        buf = (char) getchar();
    }

    clearSpaces(&list);
    printf("after clear\n");
    printList(list);
    printf("\nafter modify\n");
    modifyList(&list);
    printList(list);

    return 0;
}
