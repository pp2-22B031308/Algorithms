#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

void swap(pair<string, double> arr[], int i, int j) {
    pair<string, double> temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool comparator(pair<string, double> a, pair<string, double> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int partition(pair<string, double> arr[], int l, int r) {
    int pivot = r;
    int i = l - 1;
     
    for (int j = l; j < r; j++) {
        if (comparator(arr[j], arr[pivot])) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(pair<string, double> arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main() {
    map<string, double> grades {
        {"A+", 4.00},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.00},
        {"C+", 2.50},
        {"C", 2.00},
        {"D+", 1.50},
        {"D", 1.00},
        {"F", 0}
    };

    int n;
    cin >> n;
    pair<string, double> students[n];
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int numD;
        cin >> numD;
        pair<string, int> arr[numD];
        for (int j = 0; j < numD; j++) {
            string grade;
            cin >> grade;
            arr[j].first = grade;
            arr[j].second = 0;
        }
        double gpaG = 0;
        for (int j = 0; j < numD; j++) {
            gpaG += grades[arr[j].first];
        }
        gpaG /= numD;
        students[i].first = name;
        students[i].second = gpaG;
    }
    
    quickSort(students, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << students[i].first << " " << setprecision(3) << fixed << students[i].second << endl;
    }
}
