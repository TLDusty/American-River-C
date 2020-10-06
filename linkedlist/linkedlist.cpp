#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    string data;
    Node* next;

};

typedef struct Node* NodePtr;
Node* readFile(string fileName);
void splitMerge(Node* lis);
Node* merge(Node* list1,Node* list2);
void traverse(Node* lis);


Node* myList1 = NULL;
Node* myList2 = NULL;
int length = 0;
// rest of the prototypes
int main(){


Node* fullList = NULL;
Node* lastList = NULL;
string file = "input.txt";

fullList = readFile(file);

splitMerge(fullList);

}

Node* readFile(string fileName){
    ifstream inFile;
    inFile.open(fileName);

    Node* head = NULL;
    Node* ptr;
    ptr = new Node;

    while(inFile)
    {
        inFile >> ptr->data;
        ptr-> next = head;
        head = ptr;
        ptr = new Node;
        length++;

    }
    return head;
}

void splitMerge(Node* lis)
{

    Node* current = lis;
    for(int i = 0;i <= (length/2); i++)
    {
       myList1->data = current->data;
       myList1->next = NULL;
       current = current->next;
    }

    for(int i = ((length/2)+1);i <= length; i++)
    {
       myList2->data = current->data;
       myList2->next = NULL;
       current = current->next;
    }

    traverse(myList1);
    traverse(myList2);
    Node* finList = merge(myList1, myList2);
    traverse(finList);

}

Node* merge(Node* list1, Node* list2){
    Node* current1 = list1;
    Node* current2 = list2;
    Node* finList = NULL;
    Node* tail = NULL;
    finList = new Node;

    while(current1 != NULL)
    {
        finList->data = current1->data;
        finList->next = NULL;
        current1 = current1->next;
    }

    while(current2 != NULL)
    {
        finList->data = current2->data;
        finList->next = NULL;
        current2 = current2->next;
    }

    return finList;

}

void traverse(Node* l){


    do
    {
        cout << l->data;
        l = l->next;
    }while(l->next != NULL);

}

