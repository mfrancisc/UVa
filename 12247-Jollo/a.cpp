#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int princess[3];
    int prince[2];

    while(true){
        int card = 53;
        int used[53];
        memset(used, false, sizeof(used));
        cin>>princess[0]>>princess[1]>>princess[2]>>prince[0]>>prince[1]; 
        used[princess[0]] = true;
        used[princess[1]] = true;
        used[princess[2]] = true;
        used[prince[0]] = true;
        used[prince[1]] = true;
        if(princess[0] == 0 && princess[1] == 0 && princess[2] == 0 && prince[0] == 0 && prince[1] == 0) break;

        sort(princess, princess+3);
        sort(prince, prince+2);

        // 2 cards higher then all find the smallest available
        if(princess[2] < prince[0]) {
            for(int i = 1; i < 53 && i < card; i++){
                if(used[i] == false){
                    card = i;
                } 
            }
        } 

        // 1 card higher then all, find onother one
    if((princess[2] < prince[1]) ) {
        for(int i = princess[2] + 1; i < 53 && i < card; i++){
            if(used[i] == false){
                card = i;
            } 
        }        
    }

    // 2 cards higher then 2 cards, find onother one bigger then two
    if(princess[1] < prince[0]){

        for(int i = princess[1] + 1; i < 53 && i < card; i++){
            if(used[i] == false){
                card = i;
            } 
        }
    } 
    // impossible
    if(card == 53) {
        card = -1;
    }

        cout << card << endl;
    }
    return 0;
}

