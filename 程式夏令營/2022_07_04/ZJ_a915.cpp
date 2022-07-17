#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> loc;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        loc.push_back(make_pair(x, y));
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(loc[i].first > loc[j].first){
                pair<int, int> temp = make_pair(loc[i].first, loc[i].second);
                loc[i] = loc[j];
                loc[j] = temp;
                continue;
            }
            if(loc[i].first == loc[j].first && loc[i].second > loc[j].second){
                int temp = loc[i].second;
                loc[i].second = loc[j].second;
                loc[j].second = temp;
                continue;
            }
        }
    }

    for(auto l : loc)
        cout << l.first << " " << l.second << '\n';
    return 0;
}
