#include <iostream>

using namespace std;

int recursionSum(int input) {
    if (input == 0) {
        return 0;
    } else {
        return (input % 10) + recursionSum(input / 10);
    }
}

int main() {
    int input;

    cout << "Enter a number: ";
    cin >> input;

    cout << recursionSum(input) << endl;

    return 0;
}
