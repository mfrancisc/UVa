#include <iostream>
#include <stdio.h>

using namespace std;

char Nsq[1000][1000];
char nsq[1000][1000];
int N,n;
int verify(){

	int cntCol, cntRow;
	int found = 0;
	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){

			cntRow = 0;
			for(int i = 0; i < n; i++){
				cntCol = 0;
				for(int e = 0; e < n; e++){

					char nC = nsq[i][e];
					char NC = Nsq[row+i][col+e];
					if(nC == NC) cntCol++;

				}

				if(cntCol==n){ cntRow++;}
			}

			if(cntRow==n) {
				found = 1;
				break;
			}

		}
	}

	return found;

}

int main() {
	while(true){

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
		cout << found << endl;


		// verify 90°
	

	}



	return 0;
}
