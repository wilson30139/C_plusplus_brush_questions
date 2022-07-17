#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;

    long long n;
    while(t--){
        cin >> n;
        map<long long, long long> a;
        for(long long i = 0; i < 2*n; i++)
                    a[i] = 1e9;
        for(long long i = 0; i < n; i++){
            long long temp;
            cin >> temp;
            a[temp] = i+1;
        }

        long long ans = 0;
        for(long long x = 3; x <= 2*n-1; x++)
            for(long long i = 1; i <= sqrt(x); i++)
                if(x%i==0&&i*i!=x&&a[i]+a[x/i]==x)
                    ans++;

        cout << ans << endl;
    }

    return 0;
}
