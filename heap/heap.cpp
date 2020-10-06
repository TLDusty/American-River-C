#include <iostream>
#include <fstream>

using namespace std;

struct heap {
    static const int size = 31;
    int data[size];
    int end = -1;
};

void siftDown(heap &heap, int parent) {
    if ((2 * parent) + 2 <= heap.end) {
        int left = (2 * parent) + 1;
        int right = (2 * parent) + 2;
        int min = (heap.data[left] < heap.data[right]) ? left : right;
        if (heap.data[min] < heap.data[parent]) {
            int temp = heap.data[parent];
            heap.data[parent] = heap.data[min];
            heap.data[min] = temp;
            siftDown(heap, min);
        }
    }
}

void siftUp(heap &heap, int leaf) {
    if (leaf > 0) {
        int parent = (leaf - 1) / 2;
        if (heap.data[parent] > heap.data[leaf]) {
            int temp = heap.data[parent];
            heap.data[parent] = heap.data[leaf];
            heap.data[leaf] = temp;
            siftUp(heap, parent);
        }
    }
}

int remove(heap &heap) {
    int data = -1;
    if (heap.end > -1) {
        data = heap.data[0];
        heap.data[0] = heap.data[heap.end];
        heap.end--;
        siftDown(heap, 0);
    }
    return data;
}

void insert(heap &heap, int data) {
    if (heap.end < heap.size - 1) {
        heap.end++;
        heap.data[heap.end] = data;
        siftUp(heap, heap.end);
    }
}

void printLevel(heap &heap) {
    for (int i = 0; i <= heap.end; i++) {
        if (i == 0) {
            cout << heap.data[i] << endl;
        } else if (i == 1) {
            cout << heap.data[i] << " ";
        } else if (i == 2) {
            cout << heap.data[i] << endl;
        } else if (i < 7) {
            cout << heap.data[i] << " ";
        } else if (i == 7) {
            cout << endl << heap.data[i] << " ";
        } else {
            cout << heap.data[i] << " ";
        }
    }
}

int main() {
    ifstream inputFile;
    heap heap;
    int input;

    inputFile.open("input.txt");
    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    while (inputFile >> input) {
        insert(heap, input);
    }

    printLevel(heap);
    cout << endl << endl;

    for (int i = 0; i < 5; i++) {
        remove(heap);
        printLevel(heap);
        cout << endl << endl;
    }

    inputFile.close();
    return 0;
}
