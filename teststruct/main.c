#include <stdio.h>
#include <stdlib.h>


typedef struct tag_obj {
    int data;
    struct tag_obj* next;
}OBJ;

OBJ* push(OBJ* top, int data)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if (top == NULL)
        return top;
    printf("del: %d\n", top->data);
    OBJ* ptr_next = top->next;
    free(top);

    return ptr_next;
}

void show(const OBJ* top)
{
    const OBJ* cur = top;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}

int main()
{
    OBJ* top = NULL;
    top = push(top, 1);
    top = push(top, 3);
    top = push(top, 14);

    show(top);
    while (top)
       top = pop(top);
    return 0;
}
