#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string>
#include <iostream>
#include <fstream>
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

int postfix(string s)
{

    char tempChar;
    string operand;
    int post = 0, tempInt, num1, num2;
    int l = s.length();
    for(int i = 0; i < l; i++)
    {
            switch(s[i])
            {
                case '+':
                    num2 = (pop());
                    num1 = (pop());
                    push(num1 + num2);
                    break;
                case '-':
                    num2 = (pop());
                    num1 = (pop());
                    push(num1 - num2);
                    break;
                case '*':
                    num2 = (pop());
                    num1 = (pop());
                    push(num1 * num2);
                    break;
                case '/':
                    num2 = (pop());
                    num1 = (pop());
                    push(num1 / num2);
                    break;

                default:
                    tempChar = s[i];
                    tempInt = tempChar - '0';

                    push(tempInt);
                    break;

            }


        }
    post = pop();
    return post;
}

int main()
{
string test;
ifstream myfile;
int fina = 0;
myfile.open ("input.txt");

myfile >> test;
fina = postfix(test);

cout << fina;

myfile.close();

}
