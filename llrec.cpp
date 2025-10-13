#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
bool isLarger(int val, int pivot){
    return val > pivot;
}

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
    if(head != nullptr){
        if(isLarger(head->val, pivot)){
            larger = head;
            head = head -> next;
            larger -> next = nullptr;
            llpivot(head, smaller, larger->next, pivot);
        }

        else{
            smaller = head;
            head = head -> next;
            smaller -> next = nullptr;
            llpivot(head, smaller->next, larger, pivot);
        }
    }    
}