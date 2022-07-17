#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, L;
    cin >> N >> L;

    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> A;
    for(long long i = 0; i < N; i++){
        long long t;
        cin >> t;
        A.push(t);
        sum += t;
    }
    if(L - sum > 0)
        A.push(L-sum);

    long long money = 0;
    while(A.size()!=1){
        long long a, b;
        a = A.top();
        A.pop();
        b = A.top();
        A.pop();
        money += (a+b);
        A.push(a+b);
    }
    cout << money << '\n';
    return 0;
}
