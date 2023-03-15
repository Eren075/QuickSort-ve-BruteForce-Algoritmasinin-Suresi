#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main() {
    int arr[10000];
    srand(time(NULL)); // seed for random number generator

    // fill array with random numbers between 1 and 10000
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000 + 1;
    }

    clock_t tStart = clock();
    quicksort(arr, 0, 9999); // sort the array
    cout << "Quicksort runtime: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}

