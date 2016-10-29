#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    char s[256];
    int q_num, period;
    priority_queue< pair<int, pair <int , int> >, vector<pair<int , pair<int, int> > >, greater <pair<int , pair<int, int> > > > pq;

    while(scanf("%s", s)){
        if(s[0] == '#') break;

        scanf("%d %d", &q_num, &period);
        pq.push(pair<int , pair<int, int> >(period, pair<int, int>(q_num, period)) );
    }

    int q;
    scanf("%d", &q);

    while(q--){
        pair<int , pair<int,int> > pr = pq.top();
        pq.pop();
        cout << pr.second.first << endl;

        pr.first += pr.second.second;
        pq.push(pr);
    }

    return 0;
}
