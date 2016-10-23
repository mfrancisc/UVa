#include<iostream>
#include <cmath>

using namespace std;

int main() {

    while(true) {
        int n = -1;
        cin>>n; 
        if(n == -1) break;

        int diff = 0;
        int temp = 0;
        int x;
        string res = "Jolly";
        for(int i = 0; i < n; i++) {
            cin>>x; 
            temp = abs(temp - x);
            cout << diff << endl;
            if(diff == 0){
                diff = temp; 
            }else {
                if(diff != abs(temp + 1)) {
                    res = "Not jolly"; 
                }
                temp = diff;
            }

        }
        cout << res << endl;
    }

    return 0;
}
