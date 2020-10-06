#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;


#define TABLE_SIZE 10
#define PRIME 7

class DoubleHash {
    int* hashTable;
    int curr_size;

public:
bool isFull()
    {

        return (curr_size == TABLE_SIZE);
    }

DoubleHash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
            hashTable[i] = -1;
    }

int hash1(int key)
    {
        return (key % TABLE_SIZE);
    }

void insertHash(int key)
    {
        int colCount = 0;
        if (isFull())
            return;

        int index = hash1(key);

        if (hashTable[index] != -1) {
            int i = 1;
            while (1) {
                // get newIndex
                int newIndex = i;
                if (hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    break;
                }
                colCount++;

                int doubleH = newIndex;

                newIndex = (doubleH - (key % doubleH)); //double hashing
                if (hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    break;
                }

                colCount++;

                newIndex = ((index + i*i) + 3) % TABLE_SIZE;
                if(hashTable[newIndex] == -1){ //quadratic probing
                hashTable[newIndex] = key;
                break;
                }
                colCount++;

                newIndex = (index + i) % TABLE_SIZE;
                if(hashTable[newIndex] == -1){ //linear probing
                hashTable[newIndex] = key;
                break;
                }
                colCount++;

                i++;
            }
        }

        // if no collision occurs
        else
            cout << "Number of collisions" << colCount << endl;
            hashTable[index] = key;
        curr_size++;
    }

    // function to search key in hash table
   void search(int key)
    {
        int index1 = hash1(key);
        int i = 0;
        while (hashTable[i] != key) {
            if (hashTable[i] == -1) {
                cout << key << " not in list" << endl;
                return;
            }
            i++;
        }
        cout << key << " found" << endl;
    }

    // function to display the hash table
    void displayHash()
    {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashTable[i] != -1)
                cout << i << " --> "
                     << hashTable[i] << endl;
            else
                cout << i << endl;
        }
    }
};


int main()
{
    ifstream inputFile;
    int arraySize = 10;
    int array[arraySize];
    int input;


    // inserting keys into hash table
    inputFile.open("input.txt");
    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    for (int i = 0; i < arraySize - 1; i++) {
            DoubleHash();
    }

        for (int i = 0; i < TABLE_SIZE; i++){
            inputFile >> input;
            array[i] = input;
        }


    DoubleHash h;
    for (int i = 0; i < arraySize - 1; i++) {
        h.insertHash(array[i]);
    }

    h.displayHash();
    int in;

    cout << "Search for value" << endl;
    cin >> in;
    h.search(in);

    inputFile.close();
    return 0;
}
