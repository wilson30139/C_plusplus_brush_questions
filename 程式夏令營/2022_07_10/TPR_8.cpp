#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        vector<int> a;
        map<int, int> aMap;
        while(m--){
            int number;
            cin >> number;
            a.push_back(number);
            aMap.insert(pair<int, int>(number, 0));
        }
        int count = 1;
        for(auto it = aMap.begin(); it != aMap.end(); it++){
            (*it).second = count;
            count++;
        }
        for(int i = 0; i < a.size(); i++)
            cout << aMap[a[i]] << " ";
        cout << endl;

    }
    return 0;
}
