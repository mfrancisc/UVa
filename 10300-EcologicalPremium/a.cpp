#include <iostream>

using namespace std;

int main() {
    int n,f,a,b,c;
    cin>>n;
    while(n--){
        int tot=0;
        cin>>f; 
        while(f--){
            cin>>a>>b>>c; 
            tot += a*c;
        }

        cout << tot << endl;
    }

    return 0;
}
