#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        s.push_back(temp);
    }

    map<int, int> record;
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j <= sqrt(s[i]); j++){
            if(s[i] % j == 0){
                if(j != (s[i] / j))
                    record[s[i]/j] += 1;
                record[j] += 1;
            }
        }
    }

    if(record.size()==1){
        cout << 1 << endl;
        return 0;
    }

    int maxValue = 0;
    auto it = record.begin();
    it++;
    for(it; it != record.end(); it++)
        maxValue = max(maxValue, (*it).second);
    cout << maxValue << endl;

    return 0;
}
