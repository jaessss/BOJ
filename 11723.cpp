#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
bool check[21];

int main(){
	string input_oper;
	int input_val;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> input_oper;
		cin >> input_val;
		if (input_oper == "add"){
			check[input_val] = true;
		}
		else if (input_oper == "remove"){
			check[input_val] = false;
		}
		else if (input_oper == "check"){
			cout << check[input_val] << endl;
			
		}
		else if (input_oper == "toggle"){
			//if (check[input_val] == 0) check[input_val] = 1;
			//else check[input_val] = 1;
			check[input_val] ^= 1;
		}
		else if (input_oper == "all"){
			//for (int j = 1; j < 21; j++) check[j] = 1;
			fill(check + 1, check + 21, true);
		}
		else if (input_oper == "empty"){
			//for (int j = 1; j < 21; j++) check[j] = 0;
			fill(check + 1, check + 21, false);

		}
	}
	return 0;
} 
