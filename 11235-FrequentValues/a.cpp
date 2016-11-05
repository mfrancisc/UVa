#include <iostream>
#include <vector>
#include <map>

using namespace std;
class SegmentTree {
    private: 
        vector<int> A, st, cnt1, cnt2;
        int n;
        int left(int p) { return p << 1; }
        int right(int p) { return (p << 1)+1; }

        void build(int p, int L, int R) {
            if(L == R) {
                st[p] = 1; 
            } else {
                int mid = (L+R)/2;
                build(left(p), L, mid);
                build(right(p), mid+1, R);

                if (A[mid]==A[mid+1])
                {
                    int tmp1, tmp2;
                    if (abs(mid-L+1)>cnt1[mid]) tmp1 = cnt1[mid];
                    else tmp1 = cnt1[mid]-cnt1[L]+1;
                    if (abs(R-(mid+1)+1)>cnt2[mid+1]) tmp2 = cnt2[mid+1];
                    else tmp2 = cnt2[mid+1]-cnt2[R]+1;
                    st[p] = max(max(st[left(p)],st[right(p)]),tmp1+tmp2);
                }
                else st[p] = max(st[left(p)],st[right(p)]);
            } 
        }
        int rmq(int p, int L, int R, int i, int j){
            if(j < L || i > R) return -1; // out of range 
            if(L >= i && R <= j) { 
                return st[p]; 
            } // in range

            int mid = (L+R)/2;
            int p1 = rmq(left(p), L, mid, i, j);
            int p2 = rmq(right(p), mid+1,R, i, j);

            if (p1==-1) return(p2);
            if (p2==-1) return(p1);

            // out of query range
            if (A[mid]==A[mid+1]) 
            {
                int tmp1, tmp2;
                if (abs(mid-max(L,i)+1)>cnt1[mid]) tmp1 = cnt1[mid];
                else tmp1 = cnt1[mid]-cnt1[max(L,i)]+1;
                if (abs(min(R,j)-(mid+1)+1)>cnt2[mid+1]) tmp2 = cnt2[mid+1];
                else tmp2 = cnt2[mid+1]-cnt2[min(R,j)]+1;
                return(max((tmp1+tmp2),max(p1,p2)));
            }
            else return(max(p1,p2));
        } 

    public:
        SegmentTree(const vector<int> &_A, vector<int> &_cnt1, vector<int> &_cnt2) {
            A = _A;
            cnt1.assign(n, 0);
            cnt2.assign(n, 0);
            cnt1 = _cnt1;
            cnt2 = _cnt2;
            n = (int)A.size();
            st.assign(4*n,0);

            build(1, 0, n-1);
        }

        int rmq(int i , int j) { return rmq(1, 0, n-1, i, j); }
};

int main(void){
    int n,q;

    while(true){
        cin>>n; 
        if(!n) break;
        cin>>q;
        vector <int> A;
        A.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin>>A[i];
        }

        vector<int> cnt1(n);
        vector<int> cnt2(n);

        cnt1[0] = 1;
        for (int i=1; i<n; i++)
            if (A[i]!=A[i-1]) cnt1[i] = 1;
            else cnt1[i] = cnt1[i-1]+1;

        cnt2[n-1] = 1;
        for (int i=n-1; i>=1; i--)
            if (A[i]!=A[i+1]) cnt2[i] = 1;
            else cnt2[i] = cnt2[i+1]+1;

        SegmentTree st(A, cnt1, cnt2);

        int from,to;
        for(int i = 0; i < q; i++){
            cin>>from>>to; 
            from--;
            to--;
            cout << st.rmq(from , to) << endl;
        }

    }


    return 0;
}

