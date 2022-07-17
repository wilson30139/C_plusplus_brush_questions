#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int ans = 0, a, b, c;
    for(a = 0; a <= N; a++){
        for(b = 0; b <= N; b++){
            if(a + b <= N){
                c = N - a - b;
                ans = max(ans, 2022+abs(b-c)+a*b+b*c+c*c-abs(b*b-a*a));
            }
        }
    }
    cout << ans << endl;

    return 0;
}
