#include <iostream>
#include <fstream>
using namespace std;

void stringCopy(char *A, char *B);
bool stringCompare(char *A, char *B);
void stringConcatenation (char *A, char *B);
int stringPosition(char *A, char B);
int stringLength(char *A);
// rest of the prototypes
ifstream in("input.txt");
int main(){
char a[20],b[20];
char bb;
int test;
in>>a>>b;
stringCopy(a,b);
in>>a>>b;
stringCompare(a,b);
in>>a>>b;
stringConcatenation(a,b);
in>>a>>bb;
test = stringPosition(a,bb);
in>>a;
stringLength(a);
//the rest of the reads and function calls
in.close();
}
void stringCopy(char *A, char *B)
    {
    int i = 0;
    while(B[i]!='\0')
    {
        A[i] = B[i];
        i++;
    }
    A[i]='\0';
        cout << A << endl;

 //Copy contents of B to A
    }

//Rest of the function definitions

bool stringCompare(char *A, char *B)
    {
    int i = 0;
    for(i=0; A[i] != '\0' && B[i] != '\0'; i++)
    {
      if(A[i] == B[i] || (A[i] ^ 32) == B[i])
      {
          continue;
      }
      else break;

    }
       if(A[i]==B[i])
        {
            cout << "True" << endl;
            return true;

        }
        if (A[i] != B[i])
        {
            cout << "False" << endl;
            return false;

        }
    cout << "True" << endl;
    return true;

    }


void stringConcatenation (char *A, char *B)
    {
    int i;
    int j;

    for (i = 0; A[i] != '\0'; i++);
    for (j = 0; B[j] != '\0'; j++) {
        A[i+j] = B[j];
    }

    A[i+j] = '\0';

    cout << A << endl;

    }

int stringPosition(char *A, char B){

    for(int i = 0;A[i] != '\0';i++){
        if(A[i] == B){
            return (i + 1);
        }
    }
    return -1;

}


int stringLength(char *A){

    int i,s = 0;
    for(int i =0; A[i]!='\0'; i++){
        s++;
        }
    char c = '0' + s;
    char temp[s++];
    temp[0] = c;
    for(i = 1; i < s + 2; i++ )
        {
            temp[i] = A[i-1];
        }
    temp[s] = '\0';
    stringCopy(A,temp);
    cout << A;
   return s;

}
