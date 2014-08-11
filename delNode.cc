//************************************************************
//Linked List Node Deletion
//Programmed By: Britton Kjenner 8/11/2014
//This program demonstrates the deletion of a node inside a linked list
//This operation is done in linear time
//**************************************************************
#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    node* next;
};

node* deleteItem(int item, node* head){
    //If the first node is the item, just delete and return next
    if (head->data == item){
        node* temp = head->next;
        delete head;
        return temp;
    }    

    node* first = head;
    node* second = first->next;
    //Otherwise search the list for the item
    while(second != NULL){
        if (second->data == item){
            first->next = second->next;
            delete second;
            return head;
        }
        //Check the next value in the list
        first = second;
        second = first->next;
    }

    return head;
}

int main()
{
    int numList[] = {1, 5, 7, 23, 4, 32};
    node* head = NULL;
    //Create linked list
    for (int i=0; i <= 5; i++){
        node* temp;
        temp = (node*)malloc(sizeof(node));
        temp->next = head;
        temp->data = numList[i];
        head = temp;
    }

    //Display initial linked list
    node* temp2 = head;
    cout << "Starting Linked List: ";
    while (temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;

    //Display linked list with deleted node
    head = deleteItem(7, head);
    temp2 = head;
    cout << "Deleted 7: ";
    while (temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    return 0;
}
