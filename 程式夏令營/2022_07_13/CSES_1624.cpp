#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> remark;
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            char tempChar;
            cin.get(tempChar);
            if(tempChar == '*')
                remark.push_back(make_pair(r, c));
        }
        cin.get();
    }

    vector<int> tempVector = {0, 1, 2, 3, 4, 5, 6, 7};
    int queenLocation[40320][8];

    int index = 0;
    do{
        for(int i = 0; i < tempVector.size(); i++)
            queenLocation[index][i] = tempVector[i];
        index++;
    }
    while(next_permutation(tempVector.begin(), tempVector.end()));

    int chessBoard[8][8], x, y, sucess = 0, queenCount = 0;
    for(int time = 0; time < 40320; time++){
        queenCount = 0;

        for(int a = 0; a < 8; a++){
            for(int b = 0; b < 8; b++)
                chessBoard[a][b] = 0;
        }
        for(int a = 0; a < remark.size(); a++)
            chessBoard[remark[a].first][remark[a].second] = -1;

        for(int row = 0; row < 8; row++){
            int col = queenLocation[time][row];
            if(chessBoard[row][col] == 0){
                queenCount++;

                chessBoard[row][col] = 1;

                for(int i = 0; i < 8; i++){
                    if((i != col) && (chessBoard[row][i] != -1))
                        chessBoard[row][i] = -1;
                    if((i != row) && (chessBoard[i][col] != -1))
                        chessBoard[i][col] = -1;
                }

                x = row, y = col;
                while(0 <= x && 0 <= y){
                    if((row != x || col != y) && (chessBoard[x][y] != -1))
                        chessBoard[x][y] = -1;
                    x -= 1;
                    y -= 1;
                }

                x = row, y = col;
                while(x <= 7 && 0 <= y){
                    if((row != x || col != y) && (chessBoard[x][y] != -1))
                        chessBoard[x][y] = -1;
                    x += 1;
                    y -= 1;
                }

                x = row, y = col;
                while(0 <= x && y <= 7){
                    if((row != x || col != y) && (chessBoard[x][y] != -1))
                        chessBoard[x][y] = -1;
                    x -= 1;
                    y += 1;
                }

                x = row, y = col;
                while(x <= 7 && y <= 7){
                    if((row != x || col != y) && (chessBoard[x][y] != -1))
                        chessBoard[x][y] = -1;
                    x += 1;
                    y += 1;
                }
            }
            else
                break;
        }

        if(queenCount == 8)
            sucess++;
    }
    cout << sucess << endl;

    return 0;
}
