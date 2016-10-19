#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int n,p;
	int cnt  = 1;
	while(true){
		cin>>n>>p;
		cin.ignore();

		if(n == 0 && p == 0) break;

		string save_name;
		string name;
		float save_p = 2000000000;
		int reqMeet = -1;
		int meetReq;
		float price;


		string x;
		for(int i = 0; i < n; i++){
			//cin>>req[i];
			getline(cin, x);
		}

		for(int e = 0; e < p; e++){

			getline(cin, name);

			cin>>price;
			cin.ignore();
			cin>>meetReq;
			cin.ignore();

			if(meetReq > reqMeet) {

				save_name = name;
				reqMeet = meetReq;
				save_p = price;
			} else if( meetReq == reqMeet && price < save_p){
				save_name = name;
				reqMeet = meetReq;
				save_p = price;
			}



			for(int a = 0; a < meetReq; a++){
				string reqs;
				//	cin>>reqs;
				getline(cin, reqs);
			}

		}
		
		if(cnt > 1) cout << endl;

		cout << "RFP #" << cnt << endl;
		cout << save_name << endl;
		cnt++;
		
	}


	return 0;
}
