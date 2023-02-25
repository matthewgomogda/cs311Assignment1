//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

// ====================================================
//Your name: Matthew Gomogda
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
    Node* ptr; 
    for (ptr = front; front; ptr = front) {
        front = front->next;
        delete ptr;
    }
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    if (front == NULL) {
        return true;
    }
    else
    {
        return false;
    }

    return count == 0;
}

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const {
    //TODO: Add code here
    Node* temp = front;
    int num = count;
    while (temp->next != nullptr) {
        temp = temp->next; 
        num++; 
    }
    return num;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node* ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

//@brief Adds node to rear of the linked list.
void LinkedList::addRear(T val) {
    if (isEmpty()) {
        addFront(val);
    }
    else
    {
        Node* newNode = new Node(); 
        newNode->val = val; 
        newNode->next = NULL;
        if (front == NULL) {
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
        count++;
    }   // consider the two cases of whether the list was empty
}
    //@brief Adds node to the front of the linked list.
void LinkedList::addFront(T val) {
    Node* temp = new Node;
    if (isEmpty()) {
        front = new Node(val);
        rear = front->next;
        count++;
    }
    else
    {
        temp->val = val;
        temp->next = front;

        front = temp;
        rear = temp->next;
        count++; 
    }// consider the two cases of whether the list was empty
}
    //@brief deletes front node from the linked list. 
    //@return int the value removed from the list. 
bool LinkedList::deleteFront(T& OldNum) {
    Node* temp = front; 
    OldNum = temp->val; 
    front = front->next; 
    delete temp;
    return OldNum;
    // consider if the list was empty and return false if the list is empty 
    // consider the special case of deleting the only node in the list
}

    //@brief deletes rear node value from the linked list.
bool LinkedList::deleteRear(T& OldNum) {
    if (front != NULL) {
        if (front->next == NULL) {
            OldNum = front->val;
            front = NULL;
        }
        else {
            Node* temp = front;
            while (temp->next->next != NULL)
                temp = temp->next;

            Node* lastNode = temp->next;
            OldNum = lastNode->val;
            temp->next = NULL;
            free(lastNode);
          
        }
    }
    return OldNum;
    // consider if the list was empty and return false if the list is empty. 
} // consider the special case of deleting the only node in the list.

/* --- harder ones for test 2 and 3 -- */

/**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
bool LinkedList::deleteAt(int pos, T& val) {
    if (pos < count + 1 || pos > count + 1) {
        return false;
    }
    else 
        if (pos == 1 && front != NULL) {
        Node* nodeToDelete = front;
        front = front->next;
        free(nodeToDelete);
        return true;
    } else {
        Node* temp = front;
        for (int i = 1; i < pos - 1; i++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }
        
        if (temp != NULL && temp->next != NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            return true;
        }
        else {
            return false; 
        }
    }
}
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of deleting the first node and the last node
    // Do not forget to set value.


/**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
     * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
     * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
bool LinkedList::insertAt(int pos, T val) {
    if (pos > count + 1 || pos < 1) {
        return false;
    }
    else
        return true; 
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of inserting the first node and the last node
}
/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList& other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
    // for each node in the other list. The new node should have the same value as the other node.
    Node* ptr = other.front;
    while (ptr != nullptr) {
        addRear(ptr->val);
        ptr = ptr->next;
    }
} // for each node in the other list. The new node should have the same value as the other node.

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) { // check if the same object
        // Delete all nodes in this list
        Node *temp = front;
        while (temp != nullptr) {
            Node* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        front = nullptr;
        rear = nullptr;
        count = 0;
     
        Node* ptr = other.front;
        while (ptr != nullptr) {
            addRear(ptr->val);
            ptr = ptr->next;
        }
    }// Interate through the other list and add a new node to this list.
    //Be sure to set the front and rear pointers to the correct values.
    //Be sure to set the count to the correct value
    return *this;
}  
