#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K, remainVolume;
    cin >> N >> K;
    remainVolume = N - K;

    int a, b;
    cin >> a >> b;

    vector<tuple<int, int, int, int>> ans;
    int temp;
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            temp = i * a + j * b;
            if(remainVolume >= temp && temp >= 0)
                ans.push_back(make_tuple(temp, 20-i-j, i, j));
        }
    }
    sort(ans.begin(), ans.end(), greater<tuple<int, int, int, int>>());
    cout << get<2>(ans[0]) << " " << get<3>(ans[0]) << " " << remainVolume - get<0>(ans[0]) << endl;

    return 0;
}
