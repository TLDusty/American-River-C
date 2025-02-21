#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int data;
    node *next;
};

struct queue {
    node *front = nullptr;
    node *rear = nullptr;
};

void enqueue(queue &queue, int data) {
    node *nn = new node;
    nn->data = data;
    nn->next = nullptr;
    if (queue.rear) {
        queue.rear->next = nn;
        queue.rear = nn;
    } else {
        queue.front = queue.rear = nn;
    }
}

int dequeue(queue &queue) {
    int data = -1;
    if (queue.front) {
        data = queue.front->data;
        node *temp = queue.front;
        queue.front = queue.front->next;
        delete temp;
        if (!queue.front) {
            queue.front = queue.rear = nullptr;
        }
    }
    return data;
}

void traverse(queue queue) {
    while (queue.front) {
        cout << queue.front->data << ' ';
        queue.front = queue.front->next;
    }
    cout << endl;
}

int getLength(queue queue) {
    int length = 0;
    while (queue.front) {
        length++;
        queue.front = queue.front->next;
    }
    return length;
}

void split(queue &numbers, queue &a, queue &b) {
    if (numbers.front) {
        for (int i = 0; i < getLength(numbers)/2; i++) {
            enqueue(a, dequeue(numbers));
        }
        while (numbers.front) {
            enqueue(b, dequeue(numbers));
        }
    }
}

queue merge(queue &a, queue &b) {
    queue temp;
    while (a.front && b.front) {
        if (a.front->data < b.front->data) {
            enqueue(temp, dequeue(a));
        } else {
            enqueue(temp, dequeue(b));
        }
    }
    while (a.front) {
        enqueue(temp, dequeue(a));
    }
    while (b.front) {
        enqueue(temp, dequeue(b));
    }
    return temp;
}

queue mergeSort(queue &numbers) {
    if (numbers.front == nullptr || numbers.front->next == nullptr) {
        return numbers;
    } else {
        queue a, b, c;
        split(numbers, a, b);
        a = mergeSort(a);
        b = mergeSort(b);
        c = merge(a, b);
        return c;
    }
}

int main() {
    queue numbers;
    int input, num = 0, a[10] ={25,64,123,2,1,10,99,26,999,45};


    while (num < 10) {
        input = a[num];
        enqueue(numbers, input);
        num++;
    }

    traverse(numbers);
    numbers = mergeSort(numbers);
    traverse(numbers);

    return 0;
}
