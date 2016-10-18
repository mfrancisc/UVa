#include <iostream>

using namespace std;

int main() {
    int n;
    string s;

    cin>>n;
    while(n--){
        cin>>s;
        int pos = s.size()-2;
        if(s == "1" || s == "4" || s== "78") {
            cout << '+' << endl;; 
        } else if( s.substr(pos, 2) == "35") {
            cout << '-' << endl; 
        } else if( s[0] == '9' && s[s.size()-1] == '4') {
            cout << '*' << endl; 
        } else if( s.substr( 0, 3) == "190" ) {
            cout << '?' << endl; 
        }
    }

    return 0;
}
