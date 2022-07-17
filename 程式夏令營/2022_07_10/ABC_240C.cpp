#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bitset<10010> visit[110];
    visit[0][0] = 1;
    int N, X;
    cin >> N >> X;
    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        visit[i] = visit[i-1] << a | visit[i-1] << b;
    }
    if(visit[N][X])
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    return 0;
}
