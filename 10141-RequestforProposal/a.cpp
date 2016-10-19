#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct proposal {
	string name;
	float price;
	int meetReq;
	vector<string> meetReqList;
};

bool acompare(proposal lhs, proposal rhs) { 
	return (lhs.meetReq > rhs.meetReq) || 
		((lhs.meetReq == rhs.meetReq ) && ( lhs.price < rhs.price ));
 }

int main() {
	int n,p;
		int cnt  = 1;
	while(true){
		cin>>n;
		if(n == 0) break;
		cin>>p;
		cin.ignore();
		string req[n];

		proposal proposals[p];

		for(int i = 0; i < n; i++){
			//cin>>req[i];
			getline(cin, req[i]);
		}

		for(int e = 0; e < p; e++){

			cin>>proposals[e].name;
			cin.ignore();
			cin>>proposals[e].price;
			cin.ignore();
			cin>>proposals[e].meetReq;
			cin.ignore();

			int mr = proposals[e].meetReq;

			//cout<<proposals[e].name;
			//cout<<proposals[e].price;
			//cout<<proposals[e].meetReq;

			for(int a = 0; a < mr; a++){
				string reqs;
				//	cin>>reqs;
				getline(cin, reqs);
				proposals[e].meetReqList.push_back(reqs);
			}

		}
		
		sort(proposals, proposals+p, acompare);
		cout << "RFP #" << cnt << endl;
		cout << proposals[0].name << endl;
		cout << endl;
		cnt++;
		
	}


	return 0;
}
