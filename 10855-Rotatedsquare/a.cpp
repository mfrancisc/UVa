#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char Nsq[1000][1000];
char nsq[1000][1000];
int N,n;
int verify(){

    int found = 0;
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){

            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int e = 0; e < n; e++){

                    char nC = nsq[i][e];
                    char NC = Nsq[row+i][col+e];
                    if(nC == NC) cnt++;

                }
            }

            if(cnt==n*n) {
                found++;
            }

        }
    }

    return found;

}

int main() {
    while(true){
        memset(nsq, ' ', sizeof(nsq));
        memset(Nsq, ' ', sizeof(Nsq));
        cin>>N>>n;

        if(N==0 && n == 0){
            break;
        }


        // input squares
        for(int i = 0; i < N; i++){
            string s;
            cin>>s;

            for(int e = 0; e < N; e++){
                Nsq[i][e] = s[e];
            }
        }
        for(int i = 0; i < n; i++){
            string s;
            cin>>s;
            for(int e = 0; e < n; e++){
                nsq[i][e] = s[e];
            }
        }
        // verify O°
        int found = verify();
        cout << found << " ";

        // 3 rotationr
        // verify O° --> 90° --> 180° --> 270°
        for(int x = 0; x < 3; x++) {
            // save matrix
            char newNsq[n][n];

            // verify 90°
            for(int e = 0; e < n; e++) {
                for(int w = 0; w < n; w++) {
                    newNsq[e][w] = nsq[n-w-1][e];
                }
            }
            for(int e = 0; e < n; e++) {
                for(int w = 0; w < n; w++) {
                    nsq[e][w] = newNsq[e][w];
                }
            }
            found = verify();
            cout << found;
            if(x != 2){
                cout << " "; 
            }
        }
        cout << endl;

    }



    return 0;
}
