#include <iostream>
#include <set>

using namespace std;

int main() {
    int d;

    multiset<int> mu;
    while(true){
        mu.clear();
        cin>>d;
       if(d==0) break; 
       long long bills, val, tot;
       tot = 0;
       for(int i = 0; i < d; i++){
            cin>>bills; 
            for(int e = 0; e < bills; e++){
                cin>>val;
                mu.insert(val);
            }
        
            tot += *mu.rbegin() - *mu.begin();
            mu.erase(mu.begin());
            mu.erase(mu.find(*mu.rbegin()));
       }
       cout << tot << endl;
    }

    return 0;
}
