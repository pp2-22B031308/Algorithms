#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date {
    string day;
    string month;
    string year;

    void insert(const string& dateStr) {
        day = dateStr.substr(0, 2);
        month = dateStr.substr(3, 2);
        year = dateStr.substr(6, 4);
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    void print() {
        cout << day << "-" << month << "-" << year << endl;
    }
};

void swap(Date& a, Date& b) {
    Date t = a;
    a = b;
    b = t;
}

int partition(vector<Date>& arr, int low, int high) {
    Date pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<Date>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        string dateStr;
        cin >> dateStr;
        dates[i].insert(dateStr);
    }

    quickSort(dates, 0, n - 1);

    for (int i = 0; i < n; i++) {
        dates[i].print();
    }

    return 0;
}
