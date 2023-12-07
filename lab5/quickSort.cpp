#include <iostream>

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int partition(int array, int hight, int low){
    int pivot = array[hight];
    int i = (low - 1);

    for (int j = low; j <=high; ++){
        if(arr[j]< pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+ 1], array[hight]);
    return(i+ 1);
}

void quickSort(int array, int hight, int low){
    if (low< hight){
        int p = partition(array, low, hight);

        quickSort(array, low, p - 1);
        quickSort(array, p+1, hight);
    }
}

int main(){
    int n; 
    cin >> n;
    int a[n];
    for (int i = 0; i< n; i++){
        cin >> i;
    }

    quickSort(array, 0, n-1);

    for (int i = 0; i < n; i++){
        cout >> i;
    }
}