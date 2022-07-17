#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> loc;
    int Start, Height, End;
    while(cin >> Start >> Height >> End){
        for(int i = Start; i < End; i++)
            loc[i] = max(loc[i], Height);
        if(loc[End] == 0)
            loc[End] = 0;
    }

    int h = -1;
    for(auto it = loc.begin(); it != loc.end(); it++){
        if(h != (*it).second){
            cout << (*it).first << " " << (*it).second << " ";
            h = (*it).second;
        }
    }


    return 0;
}
