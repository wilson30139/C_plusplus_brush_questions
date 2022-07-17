#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long x, n;
    cin >> x >> n;

    priority_queue<long long, vector<long long>, greater<long long>> d;
    for(long long i = 0; i < n; i++){
        long long t;
        cin >> t;
        d.push(t);
    }

    long long money = 0;
    while(d.size()!=1){
        long long a, b;
        a = d.top();
        d.pop();
        b = d.top();
        d.pop();
        d.push(a+b);
        money += (a+b);
    }
    cout << money << '\n';
    return 0;
}
