#include <bits/stdc++.h>
using namespace std;

bool visit[6][6];
vector<int> p[6];
deque<int> dq;

void DFS(int x, int Count){
    dq.push_back(x);
    if(Count == 8){
        for(int i = 0; i < dq.size(); i++)
            cout << dq[i];
        cout << endl;
    }
    for(int i = 0; i < p[x].size(); i++){
        if(!visit[x][p[x][i]]){
            Count++;
            visit[x][p[x][i]] = true;
            visit[p[x][i]][x] = true;
            DFS(p[x][i], Count);

            Count--;
            visit[x][p[x][i]] = false;
            visit[p[x][i]][x] = false;
        }
    }
    dq.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p[1].push_back(2);
    p[1].push_back(3);
    p[1].push_back(5);
    p[2].push_back(1);
    p[2].push_back(3);
    p[2].push_back(5);
    p[3].push_back(1);
    p[3].push_back(2);
    p[3].push_back(4);
    p[3].push_back(5);
    p[4].push_back(3);
    p[4].push_back(5);
    p[5].push_back(1);
    p[5].push_back(2);
    p[5].push_back(3);
    p[5].push_back(4);

    int Count = 0;
    DFS(1, Count);

    return 0;
}
