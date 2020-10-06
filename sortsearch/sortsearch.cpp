 #include <stdlib.h>
 #include <stdio.h>
 #include <iostream>
 #include <string.h>

 using namespace std;

int arr[5][4] = {
    {5, 3, 2, 16},
    {9, 8, 10, 17},
    {4, 7, 11, 18},
    {2, 5, 9, 12},
    {7, 9, 4, 10},
};

int o[5][4] = {
    {5, 3, 2, 16},
    {9, 8, 10, 17},
    {4, 7, 11, 18},
    {2, 5, 9, 12},
    {7, 9, 4, 10},
};

void resetArray()
{
    memcpy(arr, o, sizeof(o));
}

void s(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[][4])
    { int i,j,rows = 5;
        for(i=0; i< rows - 1;i++)

            { for(j=0;j<rows-i-1;j++)
                if(arr[j][0] > arr[j+1][0])
                {
                    s(&arr[j][0],&arr[j+1][0]);
                }
            }
    }

void selectionSort(int arr[][4])
{
    resetArray();
    int i, j, min_index, n = 5;

    for (i = 5 - 1; i > 0; i--)
    {
        min_index = 0;

        for (j = 1; j <= i; j++)
        if (arr[j][1] < arr[min_index][1])
            min_index = j;

        s(&arr[min_index][1], &arr[i][1]);
    }
}

void shellSort(int arr[][4])
{
    resetArray();
    int n = 5;
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i][2];

            int j;
            for (j = i; j >= gap && arr[j - gap][2] > temp; j -= gap)
                arr[j][2] = arr[j - gap][2];

            arr[j][2] = temp;
        }
    }
}

void insertionSort(int arr[][4])
{
    resetArray();
    int n = 4;
        int i, key, j;
    for (i = 1; i < 4; i++)
    {
        key = arr[4][i];
        j = i - 1;

        while (j >= 0 && arr[4][j] > key)
        {
            for(int k = 0;k < 5;k++){
            arr[k][j + 1] = arr[k][j];
            }
            j = j - 1;
        }
        arr[4][j + 1] = key;
    }
}

void binarySearch(int arr[][4],int target)
{
    int low = 0, high = 3;
    while(low <= high)
    {
        int m = low + (high - 1) /2;
        if(arr[4][m] == target)
        {
            for(int k = 0;k < 5;k++){
                cout << arr[k][m] << endl;
            }
        }

        if(arr[4][m] < target)
            low = m + 1;

        else
            high = m - 1;
    }
}

int main()
{
    int t;
    bubbleSort(arr);
    selectionSort(arr);
    shellSort(arr);
    insertionSort(arr);
    cout << "What number do you want to search" << endl;
    cin >> t;
    cout << endl;
    binarySearch(arr, t);

    return 0;
}

