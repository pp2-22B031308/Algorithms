#include <iostream> 
#include <vector> 
#include <unordered_map> 
using namespace std; 
 
int q = 101; 

 
int ans(string str){ 
    
    unordered_map<int, bool> hashes; 
    for (int i = 0; i < str.size(); i++) { 
        int sHash = 0; 
        for (int j = i; j < str.size(); j++) { 
            sHash = (q * sHash + str[j]);
            
             
            if (hashes.find(sHash) == hashes.end()) { 
                hashes[sHash] = true; 
            } 
        }  
    } 
     
    return hashes.size(); 
} 


int main() { 
    string s; 
    cin >> s; 
    cout << ans(s);
}