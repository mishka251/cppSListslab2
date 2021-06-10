#include <stdio.h>
#include <malloc.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *PNode;

PNode first;

void initList() {
    int n;
    printf("elements count\n");
    scanf("%d", &n);
    int a;
    first = (PNode) malloc(sizeof(struct Node));
    PNode last = first;
    last->prev = NULL;
    last->next = NULL;
    for (int i = 0; i < n; ++i) {
        printf("item %d = ", i);
        scanf("%d", &a);
        last->value = a;
        if (i < n - 1) {
            PNode newItem = (PNode) malloc(sizeof(struct Node));
            newItem->next = NULL;
            newItem->prev = last;
            last->next = newItem;
            last = last->next;
        }
    }
}

void printList() {
    PNode last = first;
    while (last != NULL) {
        printf("%d  ", last->value);
        last = last->next;
    }
    printf("\n");
}


void addToList(PNode item, int toBegin, int toLast) {
   PNode newFirst = (PNode) malloc(sizeof(struct Node));
    newFirst->value = toBegin;
    newFirst->next=NULL;
    newFirst->prev=NULL;

    PNode newLast = (PNode) malloc(sizeof(struct Node));
    newLast->value = toLast;
    newLast->next=NULL;
    newLast->prev=NULL;

    PNode lastItem = item;
    while (lastItem->next != NULL) {
        lastItem = lastItem->next;
    }
    lastItem->next = newLast;
    newLast->prev = lastItem;

    PNode firstItem = item;
    while (firstItem->prev != NULL) {
        firstItem = firstItem->prev;
    }
    firstItem->prev = newFirst;
    newFirst->next = firstItem;

    first = newFirst;
}

void addToListMain() {
    int toFirst, toLast;
    printf( "to first=");
    scanf("%d", &toFirst);
    printf( "to last=");
    scanf("%d", &toLast);

    int elementIndex;
    printf("start index");
    scanf("%d", &elementIndex);
    PNode item = first;
    for (int i = 0; i < elementIndex; ++i) {
        item = item->next;
    }

    addToList(item, toFirst, toLast);
}


void removeNegative(){
    //remove first

    while(first != NULL && first->value<0){
        first = first->next;
    }

    PNode item = first;

    while (item != NULL){
        if(item->next != NULL && item->next->value<0){
            item->next =item->next->next;
        }else{
            item = item->next;
        }
    }
}

int main() {
    initList();
    printList();
    removeNegative();
    printList();
    return 0;
}
