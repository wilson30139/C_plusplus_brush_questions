#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S, Case = 0;
    while(cin >> S){
        int N, M;
        cin >> N >> M;

        int answer[N][M];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> answer[i][j];

        queue<tuple<int, int, int>> q;
        bool visit[N][M];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                visit[i][j] = false;

        for(int i = 0; i < M; i++){
            if(answer[0][i] == 1){
                q.push(make_tuple(0, i, answer[0][i]));
                visit[0][i] = true;
                break;
            }
        }

        while(!q.empty()){
            int row = get<0>(q.front()), col = get<1>(q.front()), value = get<2>(q.front());
            q.pop();

            if(!visit[row][col-1] && (col - 1 >= 0) && (answer[row][col-1] != 0)){ ///left
                q.push(make_tuple(row, col-1, value+1));
                visit[row][col-1] = true;
                answer[row][col-1] = value + 1;
            }

            if(!visit[row][col+1] && (col + 1 < M) && (answer[row][col+1] != 0)){ ///right
                q.push(make_tuple(row, col+1, value+1));
                visit[row][col+1] = true;
                answer[row][col+1] = value + 1;
            }

            if(!visit[row-1][col] && (row - 1 >= 0) && (answer[row-1][col] != 0) && (S == 1)){ ///up
                q.push(make_tuple(row-1, col, value+1));
                visit[row-1][col] = true;
                answer[row-1][col] = value + 1;
            }

            if(!visit[row+1][col] && (row + 1 < N) && (answer[row+1][col] != 0)){ ///down
                q.push(make_tuple(row+1, col, value+1));
                visit[row+1][col] = true;
                answer[row+1][col] = value + 1;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visit[i][j] && (answer[i][j] == 1))
                    answer[i][j] = 0;
            }
        }

        Case++;
        cout << "Case " << Case << ":" << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
                cout << answer[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
