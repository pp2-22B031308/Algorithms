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

int main(){
    int n;
    cin >> n;

    for (int i= 0, counter= 0; counter <= n; i++){
        if (isPrime(i)){
            counter++;
            if (counter == n)
            cout << i;
        }
    }
    return 0;    
}

