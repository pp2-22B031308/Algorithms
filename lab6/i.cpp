#include <iostream>
#include <vector>

#include<string>
using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(string &s, int low, int high)
{
    int pivot = s[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (s[j] < pivot) {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return (i + 1);
}

void quickSort(string &s, int low, int high)
{
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

int main (){

    int n ;
    cin >> n;
    string s;
    cin >>s;

    int low = 0, high = n-1;

    quickSort(s, 0, n -1);

    vector<char> vowels;
    vector<char> consonants;

    for (int i = 0; i < n; i++){
        char c = tolower(s[i]);
        if (c == 'a'|| c== 'e' ||c== 'u' ||c== 'i' ||c == 'o'){
        vowels.push_back(s[i]);
        }
        else
        consonants.push_back(s[i]);
    }

    

    for (const char& vow : vowels)
        cout << vow;

    for (const char& cons : consonants)
        cout << cons;
    
    
return 0;

}