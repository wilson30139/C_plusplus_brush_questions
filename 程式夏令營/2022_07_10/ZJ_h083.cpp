#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<string> strSet;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string t;
        cin >> t;
        strSet.insert(t);
    }

    int ans = 0;
    for(auto it = strSet.begin(); it != strSet.end(); it++){
        if((*it).size() < 3)
            continue;
        for(int i = 1; i <= (*it).size()/2; i++){
            if((*it).substr(0, i) == (*it).substr((*it).size()-i, i)){
                string str = (*it).substr(i, (*it).size()-2*i);
                if(strSet.count(str))
                    ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
