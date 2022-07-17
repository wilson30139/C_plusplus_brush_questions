#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    while(cin >> N >> Q ){
        vector<long long> K;
        long long k;
        for(int i = 0; i < N; i++){
            cin >> k;
            K.push_back(k);
        }
        sort(K.begin(), K.end());

        vector<long long> P;
        long long p;
        for(int i = 0; i < Q; i++){
            cin >> p;
            P.push_back(p);
        }

        int count = 0;
        for(int i = 0; i < Q; i++){
            for(int j = 0; j < N; j++){
                if(P[i] < K[j])
                    break;
                count++;
            }
            if(count % 2 == 0)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
            count = 0;
        }
    }
    return 0;
}

