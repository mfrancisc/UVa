#include<iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	while(true) {
		int n = -1;
		cin>>n; 
		if(n == -1) break;

		int x;
		int nums[3010];
		int diffs[3010];

		for(int i = 0; i < n; i++) {
			cin>>x; 
			nums[i] = x;

		}

		int i;
		for(i = 0; i < n-1; i++){
			diffs[i] = abs(nums[i+1] - nums[i]);
		}

		sort(diffs, diffs+i);	


		int j = 1;
		for(int i = 1; i < n; i++){

			if(diffs[i] == diffs[i-1]){
				j = 0;
				break;
			}

		}

		if(j == 1){
			cout << "Jolly";
		}else{
			cout << "Not jolly";
		}
		cout << endl;


	}

	return 0;
}
