#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int Q;
    cin >> Q;

    int b[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0){
                b[i][j] = a[i][j];
                continue;
            }
            if(j == 0){
                b[i][j] = b[i-1][j] + a[i][j];
                continue;
            }
            if(i == 0){
                b[i][j] = b[i][j-1] + a[i][j];
                continue;
            }
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
        }
    }

    vector<tuple<int, int, int, int>> loc;
    int x1, y1, x2, y2;
    for(int i = 0; i < Q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        loc.push_back(make_tuple(x1, y1, x2, y2));
    }
    for(int i = 0; i < Q; i++){
        tie(x1, y1, x2, y2) = loc[i];
        if(x1 == 0 && y1 == 0){
            cout << b[x2][y2] << '\n';
            continue;
        }
        if(x1 == 0 && x2 == 0){
            cout << b[x2][y2] - b[x1][y1-1] << '\n';
            continue;
        }
        if(y1 == 0 && y2 == 0){
            cout << b[x2][y2] - b[x1-1][y1] << '\n';
            continue;
        }
        if(x1 == 0){
            cout << b[x2][y2] - b[x2][y1-1] << '\n';
            continue;
        }
        if(y1 == 0){
            cout << b[x2][y2] - b[x1-1][y2] << '\n';
            continue;
        }
        cout << b[x2][y2] - b[x1-1][y2] - b[x2][y1-1] + b[x1-1][y1-1] << '\n';
    }
    return 0;
}
