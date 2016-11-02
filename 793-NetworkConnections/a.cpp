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
        //cin>>comp;
    scanf("%d", &comp);
        cout << "comp: " << comp << endl;
        m.resize(comp);
        q.resize(comp);

        int i,j;
        char c,blank;
        while(true){
            //cin>>c>>i>>j;
            //getline(cin, c);
            scanf("%s %d %d", &c, &i, &j);
            cout << c << endl;
            
            if(c == ' ') break;

            if(c != 'c' && c != 'q') break;

            // multiple connections
            if(c == 'c') {
                m[i].insert(j);
                m[j].insert(i);
            } else {
                q[i].push_back(j); 
                cout << i << " " << j << endl;
            }
        }

        int succ = 0;
        int fail = 0;
        for(int f = 1; f <= comp; f++){

            while(!q[f].empty()){
                int val = q[f].back();
                q[f].pop_back();

                if(f == val) {
                    succ++; 
                    continue;
                }

                if(m[val].find(f) != m[val].end()){
                    succ++; 
                    continue;
                }

                bool found = false;
                for(set <int>::iterator it = m[val].begin(); it != m[val].end(); ++it){
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
