#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string s = "MCMXCIV";
	int total = 0;
	int currentInteger = 0;
	int laterInteger = 0;
	char romanCharacter[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int romanInteger[7] = {1, 5, 10, 50, 100, 500, 1000};
	for(int i = 0; i < s.length(); i++){
		for(int j = 0; j < 7; j++){
			if(s[i] == romanCharacter[j])
				currentInteger = romanInteger[j];
			if(i != s.length()-1){
				if(s[i+1] == romanCharacter[j])
					laterInteger = romanInteger[j];
				if(currentInteger != 0 && laterInteger != 0)
					break;
			}
			if(i == s.length()-1){
				if(currentInteger != 0)
					break;
			}
		}
		if(i != s.length()-1){
			if(currentInteger < laterInteger)
				total -= currentInteger;
			if(currentInteger >= laterInteger)
				total += currentInteger;
		}
		if(i == s.length()-1)
			total += currentInteger;
		currentInteger = 0;
		laterInteger = 0;
	}
	cout << "total = " << total << endl; 
	return 0;
}
