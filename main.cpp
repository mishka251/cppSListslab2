#include <iostream>

struct List {  //
    int value;
    List *next;
    List *prev; // указатель на предыдущ элемент
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
            newItem->prev = last; // предыдущ элемент для нового это последний
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


void addToList(List *item, int toBegin, int toLast) { // получает указатель на элемент списка и два значения которые надо вставить в начало и конец
    List *newFirst = new List(); // создаём новый первый элемент
    newFirst->value = toBegin; //записываем то что надо  вставить в начало

    List *newLast = new List(); // создаем новый последний элемент
    newLast->value = toLast; // записываем

    List *lastItem = item; // создаем указатель на последн элемент списка
    while (lastItem->next != nullptr) { // пока у последнего элемента следующий не равен указателю на пустоту
        lastItem = lastItem->next; // последний элемент равен следующему за последним
    }
    lastItem->next = newLast; // следующий за последним элементом это новый последний
    newLast->prev = lastItem; // элемент перед новым последним это последний

    List *firstItem = item; // созд указ на первый элемент списка
    while (firstItem->prev != nullptr) // пока у первого элемента предшествующий  не рввен...
        firstItem = firstItem->prev; // первый элемент равен предшествующему
    }
    firstItem->prev = newFirst; // элемент перед первым это новый первый
    newFirst->next = firstItem; // элем следующ за новым первым это первый

    first = newFirst; // в первый новый первый
}

void addToList() { //
    int toFirst, toLast;
    std::cout << "to first=";
    std::cin >> toFirst;
    std::cout << "to last=";
    std::cin >> toLast;

    int elementIndex;// вводим индекс элемента который будет отправляться в функцию
    std::cout << "start index=";
    std::cin >> elementIndex;
    List *item = first; // созаем указ на элемент с заданным индексом
    for (int i = 0; i < elementIndex; ++i) {
        item = item->next; // находим этот э6лемент с заданным индексом
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
