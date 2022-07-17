#include <iostream>
using namespace std;
int CalculateTotal(int);
int main(){
	int n;
	cin >> n;
	int total = CalculateTotal(n);
	int number[n-1];
	for(int i = 0; i < (sizeof(number)/sizeof(int)); i++){
		cin >> number[i];
		total -= number[i];
	}
	cout << total;
	return 0;
}
int CalculateTotal(int n){
	int total = 0;
	for(int i = 1; i <= n; i++)
		total += i;
	return total;
}
