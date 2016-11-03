#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

class UnionFind {
    private:
        vector <int> p, rank;
    public:
        UnionFind(int N) {
            rank.assign(N+1, 0); // tree height
            p.assign(N+1, 0); // tree 
            for(int i = 1; i <= N; i++) p[i] = i; // each number is a set
        }

        int findSet(int i) {
            if(p[i] != i)  return p[i] = findSet(p[i]);
            else return i; 
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if(!isSameSet(i, j)){
                int x = findSet(i);         
                int y = findSet(j);

                if(rank[x] > rank[y]){
                    p[y] = x; 
                }else{
                    p[x] = y; 
                    if(rank[x] == rank[y]) rank[y]++;
                }
            } 

        }

};

int main() {

    int T;
    //cin>>T;
    scanf("%d", &T);
    while(T--){
        int comp;
        scanf("\n%d\n", &comp);
        UnionFind set(comp);

        int i,j;
        int succ = 0;
        int fail = 0;
        string s;
        char c;
        //getline(cin, blank);
        while(true) {
            //getline(cin, c);
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&c,&i,&j);

            if(c == 'c') {set.unionSet(i,j);}
            else if(c == 'q') {
                if(set.isSameSet(i,j)) succ++; 
                else fail++;
            }
        }

        cout << succ << ',' << fail << endl;
        if(T) cout << endl;
    }

    return 0;
}
