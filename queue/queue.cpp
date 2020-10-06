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
node *rear = NULL;


void deQueue();
void enQueue(int v);
void traverse()
{
for(node *curr = start; curr != NULL; curr = curr->next)
{
cout << curr->data;}
}


int main()
{
    ifstream input;
    input.open("input.txt");

    for(int value; !input.eof();
    enQueue(value))
    {
	input >> value;
    }
    deQueue();
    traverse();
}


void deQueue()
{
    node *current;
    node *temp;

    if (start == NULL){rear = NULL;}
    else
    {
        current = start;
        while (current->next != NULL)
        {
            if (start->data < 0)
            {
                temp = start;
                start = start->next;
                delete(temp);
                current = start;
            }
            else
            {
                if(current -> data < 0)
                {
                    temp = current;
                    current = temp->next;
                    delete(temp);
                }
                else
                {
                    temp = current->next;
                    if(temp->data < 0)
                    {
                        if (temp->next != NULL)
                        {
                            current -> next = temp->next;
                            delete(temp);
                        }
                        else
                        {
                            current->next = NULL;
                            delete(temp);
                        }
                    }
                    else{current = temp;}
                }
            }
        }
    }
}


void enQueue(int v)
{
    if (start == NULL && rear == NULL){start = rear = new node(v, NULL);}
    else
    {
        node *temp = new node(v, NULL);
        rear->next = temp;
        rear = temp;
    }
}
