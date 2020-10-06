#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include <iostream>
#include <fstream>
using namespace std;

struct node
{
    char data;
    node *next;
    node(){}
    node(char value, node *in): data(value), next(in){}
};

node *start = NULL;


char pop()
{
    char value;
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

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;

}

bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

int GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	}
	return weight;

}

int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

void push(char value){if (start == NULL){start = new node(value, NULL);}else{start = new node(value, start);}}

string infixToPostfix(string s)
{
    string operand;
    string post = "";
    int l = s.length();
    for(int i = 0; i < l; i++)
    {
        if(IsOperator(s[i])){
            while(!(start == NULL) && HasHigherPrecedence(start->data,s[i]))
            {
                    post+= start->data;
                    pop();

            }
            push(s[i]);
        }

        else if(IsOperand(s[i]))
        {
            post += s[i];
        }

        else if(s[i]  == '(')
        {
            push(s[i]);
        }

        else if(s[i] == ')')
        {
                while(!(start == NULL) && start->data != '('){
                       post += start->data;
                       pop();
                }
                pop();
        }

    }

        while(!(start == NULL)){
            post += start->data;
            pop();
        }
    return post;
}

int main()
{
string test, fina;
ifstream myfile;
myfile.open ("input.txt");

myfile >> test;

fina = infixToPostfix(test);

cout << fina;

myfile.close();

}
