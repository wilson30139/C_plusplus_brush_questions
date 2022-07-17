#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;

    long long n, k;
    while(t--){
        cin >> n >> k;
        vector<pair<long, long>> a;
        for(long long i = 0; i < n; i++){
            long long temp;
            cin >> temp;
            a.push_back(make_pair(i, temp));
        }

        long long ans = -1e18;
        long long start = max(0LL, n-201);
        for(long long i = start; i < n; i++){
            for(long long j = i+1; j < n; j++){
                ans = max(ans, (i+1)*(j+1)-k*(a[i].second|a[j].second));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
