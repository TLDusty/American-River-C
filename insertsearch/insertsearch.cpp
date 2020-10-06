#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct node {
    char name[30];
    node *next;
};

struct BinaryTree {
    char name[30];
    node *names = nullptr;
    BinaryTree *left;
    BinaryTree *right;
};

void push(node *&head, char name[]) {
    node *nn = new node;
    strcpy(nn->name, name);
    if (head) {
        nn->next = head;
    } else {
        nn->next = nullptr;
    }
    head = nn;
}

void pop(node *&head) {
    if (head) {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

void printName(BinaryTree *leaf) {
    if (leaf) {
        int count = 1;
        while (leaf->names) {
            pop(leaf->names);
            count++;
        }
        cout << leaf->name << ' ' << '(' << count << ')' << endl;
    }
}

BinaryTree *insert(BinaryTree *leaf, char name[]) {
    if (!leaf) {
        leaf = new BinaryTree;
        strcpy(leaf->name, name);
        leaf->left = nullptr;
        leaf->right = nullptr;
    } else if (strcmp(name, leaf->name) == 0) {
        push(leaf->names, name);
    } else if (strcmp(name, leaf->name) > 0) {
        leaf->left = insert(leaf->left, name);
    } else if (strcmp(name, leaf->name) < 0) {
        leaf->right = insert(leaf->right, name);
    }
    return leaf;
}

void search(BinaryTree *leaf, char name[]) {
    if (leaf) {
        printName(leaf);
        if (strcmp(name, leaf->name) > 0) {
            search(leaf->left, name);
        } else if (strcmp(name, leaf->name) < 0) {
            search(leaf->right, name);
        }
    } else {
        cout << "Name not found." << endl;
    }
}

int main() {
    ifstream in;
    BinaryTree *tree = nullptr;
    char input[30];

    in.open("input.txt");
    if (!in) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    while (in >> input) {
        tree = insert(tree, input);
    }

    cout << "Enter a name to search for: ";
    cin >> input;

    cout << "Searching for " << input << "..." << endl;
    search(tree, input);

    in.close();
    return 0;
}
