#include <stack.hpp>

template<class T>
StackNode<T>::StackNode(T value, StackNode<T> *next, StackNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
StackNode<T>::~StackNode() {
    this->next = nullptr;
    this->prev = nullptr;

}

template<class T>
Stack<T>::Stack() {
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
Stack<T>::~Stack() {

    StackNode<T>* p = this->head;
    StackNode<T>* q = nullptr;
    while(p != nullptr){
        q = p->next;
        delete p;
        p = q;
    }
    this->head = nullptr;
    this->tail = nullptr;

}

template<class T>
bool Stack<T>::empty() {
    return this->head == nullptr && this->tail == nullptr;
}

template<class T>
T Stack<T>::pop() {
   T value = tail->value;
   StackNode<T>* p = tail;
   tail = p->prev;
   delete p;
   if (this->tail == nullptr){
    head = nullptr;
   }
   else{
    tail->next = nullptr;
   }
   return value;
}

template<class T>
void Stack<T>::push(T value) {

    StackNode<T>* p = new StackNode<T>(value, nullptr, tail);
    if (empty()) {
        head = tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

template class Stack<int>;
