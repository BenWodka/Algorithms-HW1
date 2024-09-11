#include <iostream>
#include <vector>
#include <linked_list.hpp>
#include <stack.hpp>
#include <graph.hpp> 
#include <string>
#include <map>
#include <fstream>

#ifdef OPENCV
#include <opencv2/opencv.hpp>
#endif

bool testLinkedList() {
    LinkedList<int> linkedList;
    linkedList.insert(10);
    linkedList.insert(100);

    if (linkedList.find(10))
        std::cout << "10 is in the linked list\n";
    else
        return false;

    if (linkedList.find(20))
        return false;
    else
        std::cout << "20 is not in the linked list\n";
    

    if (linkedList.find(100))
        std::cout << "100 is in the linked list\n";
    else
        return false;

    if (linkedList.size() == 2)
        std::cout << "The linked list has 2 nodes\n";
    else
        return false;

    linkedList.remove(100);
    
    if (linkedList.find(100))
        return false;
    else
        std::cout << "100 is not in the linked list\n";

    if (linkedList.size() == 1)
        std::cout << "The linked list has 1 node\n";
    else
        return false;

    return true;
}

bool testStack() {
    Stack<int> stack;

    for (int i = 0; i < 5; ++i) {
        stack.push(i);
        std::cout << "Insert " << i  << " into stack\n";  
    }

    if (stack.empty())
        return false;
    else
        std::cout << "Stack is not empty\n";

    for (int i = 4; i >= 0; --i) {
        if (stack.pop() == i)
            std::cout << "Remove tail node (" << i << ") in stack successfully\n";
        else
            return false; 
    }
   
    if (stack.empty())
        std::cout << "Stack is empty\n";
    else
        return false;
    
    return true;
}

int main() {
    if (testLinkedList()) {
        std::cout << "Your linked list implementation is correct\n";
    } else {
        std::cout << "Your linked list implementation is incorrect\n";
        return -1;
    }
    
    std::cout << "\n\n";
    
    if (testStack()) {
        std::cout << "Your stack mplementation is correct\n";
    } else {
        std::cout << "Your stack implementation is incorrect\n";
        return -1;
    }
    
    
}
