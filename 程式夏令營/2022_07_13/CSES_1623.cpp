#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> p;
    long long temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        p.push_back(temp);
    }
    sort(p.begin(), p.end());

    long long answer = 1e18;
    for(int i = 0; i <= pow(2, n) - 1; i++){
        bitset<20> temp = i;
        long long groupA = 0, groupB = 0;
        for(int j = 0; j < n; j++){
            if(temp[j] == 0)
                groupA += p[j];
            else
                groupB += p[j];
        }
        answer = min(answer, abs(groupA - groupB));
    }

    cout << answer << endl;

    return 0;
}
