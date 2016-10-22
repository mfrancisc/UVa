#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<char, int> c = {
    {'A', 15}, {'K', 14}, {'Q', 13}, {'J', 12}, {'T', 11}, {'9', 9}, {'8',8}, {'7',7}, {'6',6}, {'5',5}, {'4',4}, {'3',3}, {'2',2}
};
int main(){

    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        string cards[52];
        for(int a = 0; a < 52; a++) {
            cin>>cards[a]; 
        }

        int start = 0;
        int y = 0;
        for(int b = 0; b < 3; b++){
            string card = cards[start];
//            cout << "card ";
//            cout << card << endl;

            char cardS = card[0];
//            cout << "cardS ";
//            cout << cardS << endl;

            int x = c.at(cardS);
            if(9 < x){
                x = 10; 
            }
//            cout << "x ";
//            cout << x << endl;
            y += x; 
            start += abs(10 - x)+1;
        }
//            cout << "start ";
//            cout << start << endl;

        int pos;
        //if(y <= 24 - start){
        //    pos = 24 - y; 
        //}else {
        //    y -= 24 - start; 
        //    pos = 51 - y;
        //}

//        cout << "pos ";
//        cout << pos << endl;

        //cout << "Case "<< i+1 << ": "  << cards[pos] << endl;
        //cout << start+y << endl;;
        cout << "Case "<< i+1 << ": "  << cards[start+y-1] << endl;
    }

    return 0;
}
