#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;

        bool yes = false;
        for(int a = 0; a <= 1; a++)
            for(int b = 0; b <= 1; b++)
                for(int c = 0; c <= 1; c++)
                    for(int d = 0; d <= 1; d++)
                        if((U-n+2<=a+b)&&(a+b<=U)&&(R-n+2<=b+c)&&(b+c<=R)&&(D-n+2<=c+d)&&(c+d<=D)&&(L-n+2<=a+d)&&(a+d<=L))
                            yes = true;

        if(yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
