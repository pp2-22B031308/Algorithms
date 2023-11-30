#include <iostream>
using namespace std;

int counter = 0;

bool isPrime(int n) {
    if (n < 2) return false; 
    bool answer = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            answer = false;
        }
    }
    return answer;
}

bool isSuperPrime(int n){
    if (!isPrime(n))
    return false;
    counter = 0;
    for (int i = 2; i <= n; i++){
        if (isPrime(i)){
            counter++;
            if (n == counter){
                return true;
            }
        }
    }
    return false;
}

int main  (){
    int n;
    cin >> n;

    int num = 2, counter = 0;

    while (counter < n){
        if (isSuperPrime(num)){
            counter ++;
            if (counter == n){
                cout << num;
                break;
            }
        }
        num++;
    }
    return 0;
}