#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> answer;
    deque<int> trainNumber;
    for(int i = 0; i < N; i++){
        int number;
        cin >> number;
        answer.push_back(number);
        trainNumber.push_back(i+1);
    }

    stack<int> station, tempStation;
    deque<int> station2;
    bool no = false;
    bool have = false;
    for(int i = 0; i < answer.size(); i++){
        if(station.size() != 0 && station.top() == answer[i]){
            station.pop();
            station2.pop_front();
            continue;
        }

        if(station.size() != 0){
            for(int j = 0; j < station2.size(); j++){
                if(answer[i] == station2[j]){
                    for(int k = 0; k < j; k++){
                        if(tempStation.size() + j <= M){
                            tempStation.push(station.top());
                            station.pop();
                            station2.pop_front();
                        }
                        else
                            no = true;
                    }
                    station.pop();
                    station2.pop_front();
                    have = true;
                    break;
                }
            }
            if(no)
                break;
            if(have)
                continue;
        }

        if(tempStation.size() == 0){
            for(int j = 0; j < trainNumber.size(); j++){
                if(answer[i] == trainNumber[j]){
                    for(int k = 0; k <= j; k++){
                        station.push(trainNumber[0]);
                        station2.push_front(trainNumber[0]);
                        trainNumber.pop_front();
                    }
                    station.pop();
                    station2.pop_front();
                    break;
                }
            }
            continue;
        }

        if(tempStation.size() != 0){
            for(int j = 0; j < tempStation.size(); j++){
                station.push(tempStation.top());
                tempStation.pop();
            }
            for(int j = 0; j < trainNumber.size(); j++){
                if(answer[i] == trainNumber[j]){
                    for(int k = 0; k < j; k++){
                        station.push(trainNumber[0]);
                        station2.push_front(trainNumber[0]);
                        trainNumber.pop_front();
                    }
                    station.pop();
                    station2.pop_front();
                    break;
                }
            }
            continue;
        }
    }
    if(no){
        cout << "no" << '\n';
        return 0;
    }
    cout << "yes" << '\n';
    return 0;
}
