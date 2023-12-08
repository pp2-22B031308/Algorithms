#include <iostream>
#include <cmath>
using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main (){
    int n;
    int maximum = 9999999;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    quickSort(a, 0, n-1);

    for (int i = 0; i < n- 1; i++){
        if (a[i + 1] - a[i] < maximum){
        maximum = abs(a[i + 1] - a[i]);
        }
    }

    for (int i = 0; i < n-1 ; i++){
        if (a[i + 1] - a[i] == maximum)
        cout << a[i] << " "<< a[i + 1]<< " ";
    }
    return 0;
}