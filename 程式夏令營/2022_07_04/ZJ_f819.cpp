#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> book;
    for(int i = 0; i < N; i++){
        int S, D;
        cin >> S >> D;
        book.push_back(make_pair(S, D));
    }

    int money = 0;
    vector<int> fineBook;
    for(auto b : book){
        if(b.second > 100){
            money = money + (b.second - 100) * 5;
            fineBook.push_back(b.first);
        }
    }

    if(fineBook.size() == 0){
        cout << 0 << '\n';
        return 0;
    }
    sort(fineBook.begin(), fineBook.end());
    for(auto f : fineBook)
        cout << f << " ";
    cout << '\n';
    cout << money << '\n';
    return 0;
}
