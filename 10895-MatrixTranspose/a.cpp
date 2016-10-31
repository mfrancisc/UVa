#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {

int m,n;
cin>>m>>n;

// init input
int matrix[m+1][n+1];
int tMatrix[n+1][m+1];
for(int i = 1; i <= m; i++) {
	for(int e = 1; e <= n; e++) { 
		matrix[i][e] = 0;
	}
}
for(int i = 1; i <= n; i++) {
	for(int e = 1; e <= m; e++) { 
		tMatrix[i][e] = 0;
	}
}

// load matrix
int x;
for(int i = 1; i <= m; i++){
	cin>>x;
	if(x == 0) continue;

	int index[x];
	for(int e = 0; e < x; e++) {
		cin>>index[e];
	}
	for(int e = 0; e < x; e++) {
		cin>>matrix[i][index[e]];
	}
}

// transpose matrix
for(int i = 1; i <= m; i++) {
	for(int e = 1; e <= n; e++) { 
		tMatrix[e][i] = matrix[i][e];
	}
}

// output transpose
cout << n << " " << m << endl;
for(int i = 1; i <= n; i++){
	int cnt = 0;
	int index[m];
	memsize(index, 0, index+n);
	for(int e = 1; e <= m; e++){
		if(tMatrix[i][e] != 0) {
			cnt++;
			index[cnt] = e;
		}
	}
	
	if(cnt == 0) {
		cout << 0 << endl;
		continue;
	}

	cout << cnt << endl;
	for(int a = 0; a < cnt; a++){
		cout << index[a] << " ";
	}
	cout << endl;
	for(int a = 0; a < cnt; a++){
		cout << tMatrix[i][index[a]]<< " ";
	}
	cout << endl;
}

return 0;
}
