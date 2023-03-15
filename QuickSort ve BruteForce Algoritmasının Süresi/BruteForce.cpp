#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void brute_force_sort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (arr[i] > arr[j]) {
int tmp = arr[i];
arr[i] = arr[j];
arr[j] = tmp;
}
}
}
}

int main() {
int arr[10000];
srand(time(NULL)); // seed for random number generator
// fill array with random numbers between 1 and 10000
for (int i = 0; i < 10000; i++) {
    arr[i] = rand() % 10000 + 1;
}

clock_t tStart = clock();
brute_force_sort(arr, 10000); // sort the array
cout << "BruteForce runtime: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds" << endl;

return 0;
}
