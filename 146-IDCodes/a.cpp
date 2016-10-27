#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int main() {
	while(true){

		string input;	
		cin>>input;
		if(input[0] == '#') break;

		if(std::next_permutation(input.begin(), input.end())){
			cout << input << endl;

		} else {


			printf("No Successor\n");
		}
	}



	return 0;
}
