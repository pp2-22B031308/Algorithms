#include <iostream>

using namespace std;

string remove_back(string str){
    string res;
    for(size_t i= 0; i < str.size(); i++){
        if (str [i]!= '#')
            res.push_back(str[i]);
        else if (!res.empty())
            res.pop_back();
    }
    return res;
}

bool compare(string s, string t){
    t = remove_back(t);
    s = remove_back(s);
    return t ==s;
}
int main(){
    string s,t;
    cin >> s;
    cin >> t;

    if (compare(s,t))
    cout << "Yes";
    else 
    cout << "No";

return 0;
}