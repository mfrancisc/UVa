#include <iostream>

using namespace std;

int main() {
    int d,f;
    double u,h, dist;
    while(true){
        cin>>h>>u>>d>>f;
        if(h == 0) break; 

        dist = 0.0;
        int day = 0;
        double fatigue = (f*u)/100;
        while(dist <= h && dist >= 0){
           day++;
           dist = dist+u;

           if(dist > h) break;

           dist-=d; // slides by night

           if(u>0){
               u = u-fatigue;
           }
        }

        string res = "success";
        if(dist < 0) {
            res = "failure"; 
        }

        cout << res << " on day " << day << endl;
    }

    return 0;
}
