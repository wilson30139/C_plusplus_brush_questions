#include <bits/stdc++.h>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, L;
    cin >> n >> L;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    for(int index = 0; index < n; index++){
        long long x, i;
        cin >> x >> i;
        pq.push(make_pair(i, x));
    }

    long long value = 0;
    set<long long> s;
    s.insert(0);
    s.insert(L);
    while(!pq.empty()){
        int cutPoint = pq.top().second;
        auto it = s.upper_bound(cutPoint);
        auto it2 = s.lower_bound(cutPoint);
        it2--;
        value = value + *it - *it2;
        s.insert(pq.top().second);
        pq.pop();
    }
    cout << value << endl;
    return 0;
}
