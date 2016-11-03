#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {

    int T;
    //cin>>T;
    scanf("%d", &T);
    while(T--){
        vector <  set <int>  >m;
        vector <  vector <int>  >q;

        int comp;
        scanf("%d", &comp);
        cout << "comp: " << comp << endl;
        m.resize(comp);
        q.resize(comp);

        int i,j;
        string c;
	string blank;
	getline(cin, blank);

        while(true) {

		getline(cin, c);

		if(c[0] != 'c' && c[0] != 'q') break;

		i = c[2] - '0';
		j = c[4] - '0';

		// multiple connections
		if(c[0] == 'c') {
			m[i].insert(j);
			m[j].insert(i);
		} else {
			q[i].push_back(j); 
			cout << i << " " << j << endl;
		}
        }
	
	cout << " out loop " << endl;

        int succ = 0;
        int fail = 0;
        for(int f = 1; f <= comp; f++) {

	cout << "f: " << f << " size: " << q[f].size() << endl;

            while(!q[f].empty()) {

                int val = q[f].back();
                q[f].pop_back();
		cout << "val: " << val << endl;

		if(val == 0) continue;

                if(f == val) {
                    succ++; 
                    continue;
                }

                if(m[val].find(f) != m[val].end()) {
                    succ++; 
                    continue;
                }

                bool found = false;
                for(set <int>::iterator it = m[val].begin(); it != m[val].end(); ++it){
			cout << "it: " << *it << endl;
                    if(m[*it].find(f) != m[*it].end()) {
                        succ++; 
                        found = true;
                    }
                }


                if(!found)fail++;
            }

        }

        cout << succ << "," << fail << endl;
        if(T!=0) cout << endl;
    }

    return 0;
}
