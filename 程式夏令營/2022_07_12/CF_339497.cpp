#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int n[6][3] = {
        {a, b, c},
        {a, c, b},
        {b, a, c},
        {b, c, a},
        {c, a, b},
        {c, b, a}
    };

    int maxAnswer = 0, answer;
    for(int i = 0; i < 6; i++){
        answer = 0;
        int odd = 0, even = 0;
        for(int j = 0; j < 3; j++){
            if(n[i][j] % 2 == 1)
                odd++;
            if(n[i][j] % 2 == 0)
                even++;
        }
        if(odd == 2)
            answer++;
        if(even == 2)
            answer += 2;
        if(odd == 3 || even == 3)
            answer += 5;
        for(int j = 0; j < 2; j++){
            if(n[i][j] % 2 == 1 && n[i][j+1] % 2 == 1 || n[i][j] % 2 == 0 && n[i][j+1] % 2 == 0)
                answer += 5;
        }
        if(n[i][0] + n[i][2] > n[i][1])
            answer += 5;
        if((n[i][0] + n[i][1] > n[i][2]) && (n[i][0] + n[i][2] > n[i][1]) && (n[i][1] + n[i][2] > n[i][0]))
            answer += 7;
        maxAnswer = max(answer, maxAnswer);
    }
    cout << maxAnswer << endl;

    return 0;
}
