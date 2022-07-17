#include <bits/stdc++.h>
using namespace std;
class Cake
{
    public:
        long long beauty;
        long long testiness;
        long long popularity;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<Cake> cakes;
    for(int i = 0; i < N; i++)
    {
        Cake cake;
        cin >> cake.beauty >> cake.testiness >> cake.popularity;
        cakes.push_back(cake);
    }

    long long maxValue = 0;
    for(int a = 1; a >= -1; a -= 2)
    {
        for(int b = 1; b >= -1; b -= 2)
        {
            for(int c = 1; c >= -1; c -= 2)
            {
                vector<long long> answer;
                for(int i = 0; i < cakes.size(); i++)
                    answer.push_back(a * cakes[i].beauty + b * cakes[i].testiness + c * cakes[i].popularity);
                sort(answer.rbegin(), answer.rend());
                long long tempValue = 0;
                for(int i = 0; i < M; i++)
                    tempValue += answer[i];
                maxValue = max(maxValue, tempValue);
            }
        }
    }
    cout << maxValue << endl;
    return 0;
}
