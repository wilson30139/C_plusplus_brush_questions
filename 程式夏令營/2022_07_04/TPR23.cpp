#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a;
    long long number;
    for(int i = 0; i < n; i++){
        cin >> number;
        a.push_back(number);
    }

    int Q;
    cin >> Q;

    int L, R;
    vector<pair<int, int>> LR;
    for(int i = 0; i < Q; i++){
        cin >> L >> R;
        LR.push_back(make_pair(L, R));
    }

    vector<long long> b;
    long long total = 0;
    b.push_back(total);
    for(auto c : a){
        total += c;
        b.push_back(total);
    }

    for(int i = 0; i < Q; i++){
        cout << b[LR[i].second] - b[LR[i].first-1] << '\n';
    }

    return 0;
}
