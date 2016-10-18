#include <iostream>
#include <fstream>

using namespace std;

int main() {
//    ifstream cin("a.in");
    int partecipants, budget, hotels, weeks;
    while( cin>>partecipants>>budget>>hotels>>weeks){
        int price,beds, actTot;
        int tot = 500050;
        string res = " ";
        for(int i = 0; i < hotels; i++){
            cin>>price; 
            actTot = price*partecipants;
            if(actTot > budget) {
                res = "stay home";
            for(int e = 0; e < weeks; e++) {
                cin>>beds; 
            }
            continue;
            }

            bool foundBeds = false;
            for(int e = 0; e < weeks; e++) {
                cin>>beds; 
                if(beds>= partecipants) {
                    foundBeds = true;
                }
            }
            if(!foundBeds) res = "stay home";
            else if(actTot < tot ) {tot = actTot; res = " ";}
        } 

        if(res == " ") cout << tot << endl;
        else cout << res << endl;
    }

    return 0;
}
