#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> uglyNumbers = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15};
    int count = 0;
    for(auto it = uglyNumbers.begin(); it != uglyNumbers.end(); it++){
        count++;
        if(count == 1500){
            cout << "The 1500'th ugly number is " << *it << ".";
            break;
        }
        uglyNumbers.insert(*it * 2);
        uglyNumbers.insert(*it * 3);
        uglyNumbers.insert(*it * 5);
    }

    return 0;
}
