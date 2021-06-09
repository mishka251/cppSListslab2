#include <iostream>

struct List {
    int value;
    List *next;
    List *prev;
};


List *first;

void initList() {
    int n;
    std::cout << "elements count" << std::endl;
    std::cin >> n;
    int a;
    first = new List();
    List *last = first;
    for (int i = 0; i < n; ++i) {
        std::cout << "item " << i << " = ";
        std::cin >> a;
        last->value = a;
        if (i < n - 1) {
            List *newItem = new List();
            newItem->prev = last;
            last->next = newItem;
            last = last->next;
        }
    }
}

void printList() {
    List *last = first;
    while (last != nullptr) {
        std::cout << last->value << "  ";
        last = last->next;
    }
    std::cout << std::endl;
}


void addToList(List *item, int toBegin, int toLast) {
    List *newFirst = new List();
    newFirst->value = toBegin;

    List *newLast = new List();
    newLast->value = toLast;

    List *lastItem = item;
    while (lastItem->next != nullptr) {
        lastItem = lastItem->next;
    }
    lastItem->next = newLast;
    newLast->prev = lastItem;

    List *firstItem = item;
    while (firstItem->prev != nullptr) {
        firstItem = firstItem->prev;
    }
    firstItem->prev = newFirst;
    newFirst->next = firstItem;

    first = newFirst;
}

void addToList() {
    int toFirst, toLast;
    std::cout << "to first=";
    std::cin >> toFirst;
    std::cout << "to last=";
    std::cin >> toLast;

    int elementIndex;
    std::cout << "start index";
    std::cin >> elementIndex;
    List *item = first;
    for (int i = 0; i < elementIndex; ++i) {
        item = item->next;
    }

    addToList(item, toFirst, toLast);
}

int main() {
    initList();
    printList();


    addToList();
    printList();
    return 0;
}
