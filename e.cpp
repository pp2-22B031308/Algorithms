#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int> Boris(5);
    vector<int> Nursik(5);

    for (int i = 0; i < 5; i++){
        cin >> Boris[i];
    }
    for (int i = 0; i < 5; i++){
        cin >> Nursik[i];
    }
    int rounds = 0;

    while (rounds < 1000000){
        int Boris_card = Boris.front();
        int Nursik_card = Nursik.front();

        if ((Boris_card == 0 && Nursik_card ==9) || (Nursik_card > Boris_card)){
            Nursik.push_back(Nursik_card);
            Nursik.push_back(Boris_card);
        }
        else{
            Boris.push_back(Boris_card);
            Boris.push_back(Nursik_card);
        }
        rounds ++;
    }
    if (Boris.empty()){
        cout<< "Boris " << rounds << endl;
    }
    else{
        cout << "Nursik " << rounds << endl;
    }

    Boris.erase(Boris.begin());
    Nursik.erase(Nursik.begin());

return 0;
}