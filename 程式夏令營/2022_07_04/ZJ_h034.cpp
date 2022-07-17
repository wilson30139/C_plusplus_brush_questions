#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> restaurant;
    vector<int> strLength;
    string res;
    for(int i = 0; i < N; i++){
        cin >> res;
        restaurant.push_back(res);
        strLength.push_back(res.length());
    }

    int max = strLength[0];
    for(auto sl : strLength){
        if(max < sl)
            max = sl;
    }

    string result = "";
    for(int i = 0; i < max; i++){
        for(auto res : restaurant){
            if(res.length() <= i)
                continue;
            if(res[i] != '0' && res[i] != '1' && res[i] != '2' && res[i] != '3' && res[i] != '4' && res[i] != '5' && res[i] != '6' && res[i] != '7' && res[i] != '8' && res[i] != '9'){
                result += res[i];
            }
        }
    }
    cout << result << '\n';
    return 0;
}
