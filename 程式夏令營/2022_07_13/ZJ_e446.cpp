#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> a;
    for(int i = 1; i <= N; i++)
        a.push_back(i);

    do{
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << '\n';
    }
    while(next_permutation(a.begin(), a.end()));

    return 0;
}
