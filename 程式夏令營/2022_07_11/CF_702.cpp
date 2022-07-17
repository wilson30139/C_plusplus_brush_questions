#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    long long x;
    bool yes;
    while(t--){
        yes = false;
        cin >> x;
        long long a;
        for(a = 1; a * a * a <= x; a++){
            long long bThree = x - a * a * a;
            if(bThree != 0){
                long long temp = cbrt(bThree);
                if(temp * temp * temp == bThree){
                    yes = true;
                    break;
                }
            }
        }
        if(yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
