#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    
    LinkedListNode<T>* current = root;
    //while there still exists nodes, store next node as temp, delete next node, update
    while (current != nullptr){
        LinkedListNode<T>* temp = current->next;
        delete current; 
        current = temp;
    }
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    
    LinkedListNode<T>* insert = new LinkedListNode<T>(value);
    insert->next = root;
    root = insert;
    return insert;

}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
    LinkedListNode<T>* result = root;
    //while the search node exists and the result isn't found, keep searching.
    while(result != nullptr && result->value != value){
        result = result->next;
    }
    return result;

}

template<class T>
LinkedListNode<T>* LinkedList<T>::getRoot() {
    return this->root;
}



template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    
    LinkedListNode<T>* p = root;
    LinkedListNode<T>* q = nullptr;
    while (p != nullptr) {
        if (p->value == value) {
            std::cout << "Removing node with value: " << value << "\n";
            if (q == nullptr) {  
                root = p->next;
            } else {
                q->next = p->next;
            }
            delete p;
            return root;
        } else {
            q = p;
            p = p->next;
        }
    }
    return root; 
}


template<class T>
int LinkedList<T>::size() {

    int count = 0;  
    LinkedListNode<T>* current = root;  
    while (current != nullptr) {  
        count++;  
        current = current->next;
    }
    return count; 
}

template class LinkedListNode<int>;
template class LinkedList<int>;

