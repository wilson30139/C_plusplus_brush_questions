#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bitset<2510> person[2510];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int d;
        cin >> d;
        for(int j = 0; j < d; j++){
            int t;
            cin >> t;
            person[i][t] = 1;
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if((person[i]&person[j]).any())
                answer++;
        }
    }
    cout << answer << '\n';

    return 0;
}
