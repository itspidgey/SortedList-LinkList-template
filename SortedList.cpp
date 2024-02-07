
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    head = nullptr;
    iterNode = nullptr;
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;

    while (head != nullptr){
        NodeT* oldHead = head;
        head = head->next;
        delete oldHead;
    }
}

template<class T>
bool SortedList<T>::IsFull() const {
    try {
        NodeT* node = new NodeT;
        delete node;
        return true;
    }
    catch(std::bad_alloc error){
        return false;
    }
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {

    NodeT *currN = head;

    while (currN != nullptr){

        if(currN->info == someItem){
            return true; // found someItem
        }
        else if (currN->info > someItem){
            break; // passed where someItem should be, exit.
        }
        currN = currN->next;
    }
    return false;
}

template<class T>
void SortedList<T>::AddItem(T item) {

    NodeT* node = new NodeT;
    node->info = item;
    node->next = nullptr;

    if (head == nullptr){
        head = node;
        length++;
        return;
    }
    NodeT *currN = head;
    NodeT *prevN = nullptr;
    while (currN != nullptr){

        if(currN->info > item){
            node->next = currN;
            if (prevN != nullptr){
                prevN->next = node;
            }
            else{
                head = node;
            }
            length++;
            break;
        }
        prevN = currN;
        currN = currN->next;
    }

    // Add to end of list
    prevN->next = node;
    length++;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    NodeT* currN = head;
    NodeT* prevN = nullptr;

    while (currN != nullptr){

        if (currN->value == item){

            if (currN != head){
                prevN->next = currN->next;
            }
            else{
                head = currN->next;
            }
            delete currN;
            length--;
            return; //found the value and deleted, now leave the function.
        }
            prevN = currN;
            currN = currN->next; //moves currN to the next Node
        }
}

template<class T>
void SortedList<T>::ResetIterator() {
    iterNode = head;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (iterNode >= length) {
        throw "Out of bounds";
    }

    T nextItem = iterNode->value;
    iterNode = iterNode->next;
    return nextItem;
}

