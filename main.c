#include <stdio.h>
#include <stdbool.h>
#include "listHelper.h"
#include "stringHelper.h"
#include "stdio.h"

int main() {
    List list = createList();
    bool finishProgram;

    while (1) {
        finishProgram = true;
        int buf;
        printf("input string: ");
        clearList(&list);
        list = createList();

        while ((buf = getchar()) != EOF) {
            if (buf == '\n'){
                finishProgram = false;
                break;
            }
            pushElementToList(&list, (char) buf);
        }

        if (finishProgram) break;

        clearSpaces(&list);
        printf("after  clear: ");
        printList(list);
        printf("\n after modify:");
        modifyList(&list);
        printList(list);
        printf("\n\n");


    }

    clearList(&list);
    printf("\nGoodbye!");
    return 0;
}
