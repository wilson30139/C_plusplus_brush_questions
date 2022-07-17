#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        if(n < 4){
            cout << -1 << '\n';
            continue;
        }
        deque<int> p = {3, 1, 4, 2};
        for(int j = 5; j <= n; j++){
            if(j % 2 == 1)
                p.push_back(j);
            else
                p.push_front(j);
        }
        for(int j = 0; j < n; j++)
            cout << p[j] << " ";
        cout << '\n';
    }

    return 0;
}
