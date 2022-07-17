#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pq2;

    while(1)
    {
        int n;
        cin >> n;
        if(!n)
            break;

        if(pq.size() == 0)
            pq.push(n);
        if(n > pq.top())

        if((pq.size() + pq2.size()) % 2 == 1)
            cout << "output = " << pq.top() << '\n';
        else
        {
            pq2.push(pq.top());
            pq.pop();
            cout << "output = " << (pq.top() + pq2.top()) / 2 << '\n';
        }

    }

    return 0;
}
