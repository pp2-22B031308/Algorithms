#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main (){
    int n;
    cin >> n;

    vector<int> ages(n);
    vector<int> pos (n, -1);
 
    for(int i = 0; i < n; i++)
        cin >> ages[i];

    stack<pair<int, int> >s;

    for (int i = 0; i < n; i++){
        while(!s.empty() && s.top().first>= ages[i]){
            s.pop();
        }
        if (!s.empty()){
            pos[i] = s.top().first;
        }
        s.push(make_pair(ages[i],i));
    }
    for (int i =0; i < n; i++)
    cout << pos[i]  << " ";

return 0;
}