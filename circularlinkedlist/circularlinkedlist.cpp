#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    string name;
    node * next;
    node * prev;
    node(){};
    node(string _data, node *_next, node *_prev):name(_data), next(_next), prev(_prev){};
    node(string _data, node *_next):name(_data), next(_next){}
};

node * head = NULL;
node * rear = NULL;
node * current = NULL;
void Traverse();
void Delete(int num);
void Insert(string n);
int main()
{
    ifstream input;
    input.open("input.txt");
    string n,in;
    while(input >> n){Insert(n);}
    Traverse();
    int num;
    do{
        cout << "Enter number to delete: ";
        cin >> num;
        Delete(num);
        cout << endl;
        cout << "Enter any key except 'x' to continue program: ";
        cin >> in;
        cout << endl;
    }
    while(in != "x");
    return 0;
}

void Traverse()
{
    node * temp = head;
    for(node *temp = head; temp; temp = temp->next)
    {
        if (temp -> next != head){cout << temp -> name << endl;}
        else
        {
            cout << rear -> name << endl;
            break;
        }
    }
}





void Delete(int num)
{
    node* temp = head;
    for(int i = 0;i < num;i++){
      current = temp -> next;
      temp -> prev -> next = current;
      current -> prev = temp -> prev;
      head = head->next;
      temp = head;
    }
    delete(temp);

      Traverse();
}

void Insert(string n)
{
  if(!head){head = rear = current = new node(n, NULL, NULL);}
  else
  {
    node * temp = new node(n, NULL, current);
    current->next = temp;
    rear = temp;
    current = temp;
    rear -> next = head;
    head -> prev = rear;
  }
}
