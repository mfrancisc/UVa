#include <iostream>
#include <vector>

class SegmentTree {
private: 
	vector<int> A, st;
	int n;
public:
 SegmentTree(const vector<int> &_A){
	A = _A;
	n = A.size();
}
	

}


using namespace std;
	int n,q;

	while(true){
		cin>>n>>q;
		if(n==0) break;
		
		int *values = new int[n+1];

		for(int i = 1; i <= n; i++) {
			cin>>values[i];
		}
		vector<int> A(values, values+n);
		// create segment tree
		SegmentTree st(A);
		
		int from,to;
		for(int i = 0; i < q; i++) {
			cin>>from>>to;	
			cout << st.rmq(i, j) << endl;
		}


	}


	return 0;

}
