#include <iostream>
using namespace std;
int main(){
    bool IsPrime(int);
    int n, j = 0;
    cin >> n;

    if(IsPrime(n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
bool IsPrime(int n){
    if (n <= 1)
        return false;

    for(int i = 2; i < n/2; i++)
        if (n% i ==0)
        return false;
    return true;
}