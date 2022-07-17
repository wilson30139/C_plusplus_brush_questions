#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pq2;

    while(1){
        int n;
        cin >> n;
        if(n == 0)
            break;

        if(pq.size() == 0){
            pq.push(n);
            cout << n << '\n';
            continue;
        }

        if(n > pq.top())
            pq.push(n);
        else
            pq2.push(n);

        if((pq.size() + pq2.size()) % 2 == 0){
            if(pq.size() > pq2.size()){
                pq2.push(pq.top());
                pq.pop();
            }
            cout << (pq.top() + pq2.top()) / 2 << '\n';
        }else{
            if(pq.size() < pq2.size()){
                pq.push(pq2.top());
                pq2.pop();
            }
            cout << pq.top() << '\n';
        }
    }

    return 0;
}
