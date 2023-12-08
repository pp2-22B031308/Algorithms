#include<iostream>
#include<unordered_map>

using namespace std;

const int d = 256;
const int q = 101;

int RabinKarp(string s, string pattern){
    int n = s.size();
    int m = pattern.size();
    int h = 1;
    int sHash = 0, pHash = 0;

    for (int i = 0; i < m - 1; i++){
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++){
        sHash = (sHash * d * s[i]);
        pHash = (pHash * d * pattern[i]);
    }
    unordered_map<int, int> hashMap;
    hashMap[sHash] = 0;

    for (int i = 0; i < n-m; i++){
        if (sHash == pHash){
            if(pattern ==s.substr(i, m)){
                return i;
            }
        }
    
        if(i == n - m){
            sHash = (d * (sHash - s[i] * h) + s[i+m])% q;
            if (sHash < 0){
                sHash += q;
            }
        }
  
}
return -1;
}

int main (){
    string s, pattern;
    cin >> s;
    cin >> pattern;

    int index = RabinKarp(s, pattern);
    cout << index << endl;

}