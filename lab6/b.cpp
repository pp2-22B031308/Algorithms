
#include <iostream>
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



int main(){
    int n, m;
    cin >> n>> m;
    int a1[n], a2[m];
    for (int i = 0; i < n; i++){
        cin >> a1[i];
    }
    for (int j = 0; j < m; j++){
        cin >> a2[j];
    }

    quickSort(a1, 0, n-1);
    quickSort(a2, 0, m-1);

    int i = 0;
    int j = 0;
    int found = 0;
    while (i < n && j < m) {
        if (a1[i] == a2[j]) {
            cout << a1[i] << ' ';
            i++;
            j++;
        }
        else if (a1[i] < a2[j])
            i++;
        else
            j++;
    }
    cout << endl;
return 0;
}