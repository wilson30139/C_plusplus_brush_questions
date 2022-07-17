#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5e6+10;
int d[30], visit[SIZE];
int minAnswer, m;

void solve(int index, int pos, int visitCount){
    if(visitCount >= minAnswer)
        return;

    if(index == m){
        minAnswer = min(minAnswer, visitCount);
        return;
    }

    if(visit[pos+d[index]] == 1)
        solve(index + 1, pos + d[index], visitCount);
    else{
        visit[pos+d[index]] = 1;
        solve(index + 1, pos + d[index], visitCount + 1);
        visit[pos+d[index]] = 0;
    }

    if(visit[pos-d[index]] == 1)
        solve(index + 1, pos - d[index], visitCount);
    else{
        visit[pos-d[index]] = 1;
        solve(index + 1, pos - d[index], visitCount + 1);
        visit[pos-d[index]] = 0;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> d[i];

    minAnswer = m + 1;
    visit[SIZE/2] = 1;
    visit[SIZE/2+d[0]] = 1;
    solve(1, SIZE/2+d[0], 2);

    cout << minAnswer << endl;

    return 0;
}
