#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int c = 1;
    while(n--){
        int m = 0;
        int y;
        cin>>y;

        int a;
        for(int i = 0; i < y; ++i)
        {
            cin>>a;
            m = max(m,a);         
        }
        cout << "Case " << c << ": " << m << endl;
        c++;
    } 
    return 0;
}
