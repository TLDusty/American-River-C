#include<iostream>
using namespace std;
// function to get max value
int getMaximum(int array[], int n)
{   int max = array[0];
    for(int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
        return max;
}

struct node{
int data;
node *next;
};

struct nodeQ{
node *front;
node *rear;
};

nodeQ que[10];

void add_q(int i, int data) {
        node *tmp;

        tmp = new node;
        tmp->next = NULL;
        tmp->data = data;
        if (que[i].front) {
                que[i].rear->next = tmp;
        } else {
                que[i].front = tmp;
        }
        que[i].rear = tmp;
}

int delete_q(int i) {
        int data;
        node *tmp;

        tmp = que[i].front;
        if (!tmp) {
                return -1;  /* So that we can check if queue is empty */
        }
        data = tmp->data;
        que[i].front = tmp->next;
        delete tmp;
        return data;
}

void radix_sort(int *arr, const int size) {
        int i, j, k, radix, digits, tmp;

        if (size < 1) {
                return;
        }

        for (digits = 0, radix = 1; arr[0] >= radix; digits++, radix *=10);

        for (i = 0, radix = 1; i < digits; i++, radix *= 10) {
                for (j = 0; j < size; j++) {
                        add_q((arr[j] / radix) % 10, arr[j]);
                }
                for (j = 0, k = 0; j < 10; j++) {
                        for (tmp = delete_q(j); tmp != -1;\
                             tmp = delete_q(j), k++) {
                                arr[k] = tmp;
                        }
                }
        }
}

int main(void) {
        int i;
        int a[5] = {133, 34, 555, 111, 12},
            b[12] = {1, 1, 1, 4, 5, 6, 7, 8, 9, 11, 11, 12};

        radix_sort(a, 5);
        radix_sort(b, 5);

        for (i = 0; i < 5; i++) {
                cout << a[i] << ",";
        }
        cout << endl;

        for (i = 0; i < 12; i++) {
                cout << b[i]  << ",";
        }
        cout << endl;

        return 0;
}
