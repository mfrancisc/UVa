#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

    int m,n;
    while(scanf("%d%d", &m, &n) != EOF) {

        // init input
        int matrix[m+1][n+1];
        int tMatrix[n+1][m+1];
        for(int i = 1; i <= m; i++) {
            for(int e = 1; e <= n; e++) { 
                matrix[i][e] = 0;
                tMatrix[e][i] = 0;
            }
        }

        // load matrix
        int x;
        for(int i = 1; i <= m; i++){
            cin>>x;
            if(x == 0) continue;

            int index[x];
            memset(index, 0, x);
            for(int e = 0; e < x; e++) {
                cin>>index[e];
            }
            for(int e = 0; e < x; e++) {
                cin>>matrix[i][index[e]];
                // transpose matrix
                tMatrix[index[e]][i] = matrix[i][index[e]];
            }
        }

        // output transpose
        cout << n << " " << m << endl;
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            int index[m];
            memset(index, 0, n);
            for(int e = 1; e <= m; e++){
                if(tMatrix[i][e] != 0) {
                    index[cnt] = e;
                    cnt++;
                }
            }

            if(cnt == 0) {
                cout << 0 << endl;
                cout << endl;
                continue;
            }

            cout << cnt << " ";
            for(int a = 0; a < cnt; a++){
                cout << index[a];
                if(a != cnt - 1) cout << " "; 
            }
            cout << endl;
            for(int a = 0; a < cnt; a++){
                cout << tMatrix[i][index[a]];
                if(a != cnt - 1) cout << " "; 
            }
            cout << endl;
        }
    }

    return 0;
}
