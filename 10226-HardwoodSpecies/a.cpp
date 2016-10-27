#include <iostream>
#include <map>
#include <iomanip> 

using namespace std;

int main() {
    int t;
    string s;
    map<string, float> m;
    //cin.ignore(256, '\n');
    cin>>t;
    string b;
    getline(cin, b);
    getline(cin, b);

    for(int i= 0; i < t; i++){
        float tot = 0.0;
        while(getline(cin, s)&& s.length()!=0){
            m[s]+=1;
            tot++;
        }

        // output percent
       for(map<string, float>::iterator it = m.begin(); it != m.end(); it++){
           float percent = it->second/tot*100;
            cout <<  it->first << " "; 
            cout<< fixed << setprecision(4) << percent << endl; 
       }

       if (i != t-1){
			printf("\n");
       }
       m.clear();
    }


    return 0;
}
