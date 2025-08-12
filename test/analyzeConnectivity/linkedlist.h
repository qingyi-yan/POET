#include <iostream>
// using namespace std;
template <class T>
class LinkedList
{
protected:
    struct ListNode
    {
       T value;
       ListNode *next;
    };
    ListNode *head;                   // List head pointer
public:
    LinkedList() { head = NULL;  }    //Constructor

    // Original remove() function
    void remove_original_function(T value)
    {
        ListNode *nodePtr, *previousNodePtr;

        if (!head)  return;

        if (head->value == value)
        {
            nodePtr = head;
            head = head->next;
            delete nodePtr;
        }
        else
        {
            nodePtr = head;

            while (nodePtr != NULL && nodePtr->value != value)
            {
                previousNodePtr = nodePtr;
                nodePtr = nodePtr->next;
            }
            if (nodePtr)
            {
                previousNodePtr->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }

    //Split into smaller logic blocks to test analyze_connectivity()

    // Expected: Unchanged input graph
    // Current: PASS
    void remove_if_empty(T value)
    {
        if (!head)  return;
    }

    // Expected: Node pointed to by nodePtr (and all references to it) is removed from input graph
    // Current: Not all edges removed in output graph: ("ALIAS","head",1) ("ALIAS","p0",1)
    void remove_first(T value)
    {
        ListNode *nodePtr;
        if (head->value == value)
        {
            nodePtr = head;
            head = head->next;
            delete nodePtr;
        }
    }

    // Expected: 
    // Current: Unchanged except for a stale edge ("next",1,1)
    void remove_not_first(T value)
    {
        ListNode *nodePtr, *previousNodePtr;
        nodePtr = head;

        while (nodePtr != NULL && nodePtr->value != value)
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            previousNodePtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
};
