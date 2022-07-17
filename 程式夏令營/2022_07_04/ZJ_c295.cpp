#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> number;
    int num;
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < M; j++){
            cin >> num;
            temp.push_back(num);
        }
        number.push_back(temp);
    }
    vector<int> maxNumber;
    int total = 0;
    for(auto num : number){
        int max = 0;
        for(auto n : num){
            if(max < n){
                max = n;
            }
        }
        total += max;
        maxNumber.push_back(max);
    }
    cout << total << '\n';
    int count = 0;
    vector<int> testNumber;
    for(auto n : maxNumber){
        if(total % n == 0){
            count++;
            testNumber.push_back(n);
        }
    }
    if(count != 0){
        for(int i = 0; i < testNumber.size(); i++){
            if(i != testNumber.size()-1)
                cout << testNumber[i] << " ";
            else
                cout << testNumber[i];
        }
    }
    if(count == 0){
        cout << -1 << '\n';
        return 0;
    }
    return 0;
}
