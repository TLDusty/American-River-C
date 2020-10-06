#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node(){}
    node(int value, node *in): data(value), next(in){}
};

node *start = NULL;


int pop()
{
    int value;
    if (start == NULL){cout << "Invalid" << endl;}
    else
    {
        node *current = start;
        start = start->next;
        value = current->data;
        delete(current);
    }
    return value;
}

void push(int value){if (start == NULL){start = new node(value, NULL);}else{start = new node(value, start);}}


int main()
{

    int input, hex;
    char hexNumbers[] = "0123456789ABCDEF";

    hex = input;


    cout << "Please enter a number: ";
    cin >> input;

    cout << "Binary Number: ";
    for(; input > 0; input = input/2){push(input % 2);}

    while(true){if (start != NULL){cout << pop();}else{break;}}
    cout << endl;




    for(; hex > 0; hex = hex/16){push(hex % 16);}

    cout << "Hex Number: ";
    while (true){if (start != NULL){cout << hexNumbers[pop()];}else{break;}}
    cout << endl;


}
