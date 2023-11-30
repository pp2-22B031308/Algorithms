#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> numbers;

    while (true){
        char operations;
        cin >> operations;

        if (operations == '!'){
            cout << "!"<<endl;
            break;
        }
        else if (operations =='+'){
            int n;
            cin >> n;
            numbers.push_front(n);
        }
        else if (operations== '-'){
            int n;
            cin >> n;
            numbers.push_back(n);
        }

        else if (operations== '*'){
            if (numbers.size() < 2){
                cout << "error" << endl;
                break;
            }
            else{
            int first = numbers.front();
            int last = numbers.back();
            cout << first + last << endl;
            numbers.pop_front();
            numbers.pop_back();
            }
        }
    }
return 0;
}