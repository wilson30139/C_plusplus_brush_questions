#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<string> e;
    string temp;
    for(int i = 0; i < m; i++){
        cin >> temp;
        e.push_back(temp);
    }

    string temp2;
    for(int i = 0; i < 1; i++)
        cin >> temp2;
    deque<char> T;
    for(int i = 0; i < temp.length(); i++)
        T.push_back(temp2[i]);

    int count;
    string S_str;
    deque<char> S;
    for(int i = m-1; i >= 0; i--){
        for(int j = e[i].length()-1; j >= 0; j--){
            if(e[i][j] == '0'){
                S.push_front(T[j]);
                T.pop_back();
            }else{
                S.push_back(T[j]);
                T.pop_back();
            }
        }

        S_str = "";
        for(int j = 0; j < S.size(); j++)
            S_str += S[j];

        count = 0;
        for(int j = 0; j < e[i].length(); j++){
            if(e[i][j] == '1')
                count++;
        }
        if(count % 2 == 1){
            if(e[i].length() % 2 == 0)
                temp = S_str.substr(n/2, n/2) + S_str.substr(0, n/2);
            else
                temp = S_str.substr(n/2+1, n/2) + S_str[n/2] + S_str.substr(0, n/2);
            S_str = temp;
        }

        T.clear();
        for(int j = 0; j < S_str.length(); j++)
            T.push_back(S_str[j]);
        S.clear();
    }
    cout << S_str << '\n';
    return 0;
}
