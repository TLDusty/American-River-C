#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
     string name;
     Node *head;
     Node *tail;
};
Node *head = NULL;
Node *tail = NULL;

int length = 0;
int counter;
Node* readFile(string fileName);
void traverseUpandDown(Node* x);


int main(){


Node* fullList = NULL;
string file = "input.txt";

fullList = readFile(file);

traverseUpandDown(fullList);
}

Node* readFile(string fileName){
    ifstream inFile;
    inFile.open(fileName);

    string data = "";
    string del = "";
    Node* first;
    Node* tail = NULL;
    Node* ptr;

    while(inFile)
    {

        inFile >> data;
        ptr = new Node;

        if(!head){   //no other nodes
            ptr->name = data;
            ptr->head = head;
            ptr->tail = NULL;
            first = ptr;
            head = ptr;
            tail = ptr;
            length++;
        }else if (data < head->name){    //smaller than head
            ptr->name = data;
            ptr->head = head;
            ptr->tail = head->tail;
            head = ptr;
            length++;
        }else if (data > tail->name){   //larger than tail
            ptr->name = data;
            ptr->head = tail->head;
            ptr->tail = tail;
            length++;
        }else if (data < tail->name || tail->tail == NULL){   //smaller than tail
            ptr->name = data;
            ptr->head = tail->head;
            ptr->tail = NULL;
            tail = ptr;
            length++;
        }else{                                    //somewhere in the middle
            ptr->name = data;
            ptr->head = head->tail;
            ptr->tail = tail->head;
            length++;

}

}
    first = head;
    while(inFile){
        inFile >> data;
        if(data == "delete"){
            counter = 0;
            inFile >> del;
            for(int i = 0;i < length;i++){
                counter++;
                if(first->name == del && first->head == NULL){
                    first = first->tail;
                    first->head = NULL;
                    length--;
                    break;
                }
                else if(first->name == del && first->tail == NULL){
                    first = first->head;
                    first->tail = NULL;
                    length--;
                    break;
                }
                else if(first->name == del){
                    first = first->tail;
                    length--;
                    break;
                }
            first=first->tail;
        }
            for(int i = 0;i < counter;i++){
                if(first->head != NULL){
                    first=first->head;
                    }
            }
    }
}
    head = first;
    return head;
}


void traverseUpandDown(Node* x){
    ofstream myfile("output.txt");
    counter = 0;
        for(int i = 0;i < length;i++){
                myfile << x->name;
                x = x->tail;
                counter++;
        }
            myfile << "=============";
        for(int i = 0;i < counter;i++){
                if(x == NULL){
                    break;
                }
                myfile << x->name;
                x = x->head;
        }

}
