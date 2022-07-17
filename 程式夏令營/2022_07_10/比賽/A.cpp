#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        a.push_back(number);
    }

    vector<int> b;
    for(int i = 0; i < n; i++){
        if(a[i] % x == 0)
            b.push_back(i);
    }

    int Start = 0;
    int End = 0;
    long long total = 0;
    int i;
    for(i = 0; i < b.size(); i++){
        if(i != 0){
            if(b[i] == b[i-1]+1){
                End = i;
                if(i == b.size()-1){
                    for(int j=1; j<=End-Start+1; j++)
                        total += j;
                }
            }
            else{
                for(int j=1; j<=End-Start+1; j++)
                    total += j;
                Start = i;
                End = i;
            }
        }
    }
    if(i==Start+1)total++;
    cout << total << endl;

    return 0;
}
