#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> x;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        x.push_back(t);
    }

    multiset<int, less<int>> r;
    multiset<int, greater<int>> l;
    auto it = x.begin();
    for(int i = 0; i < n; i++){
        if(i == 0)
            r.insert(x[i]);
        if(i != 0 && ((x[i] > *r.begin() && r.size() != 0) || (r.size() == 0)))
            r.insert(x[i]);
        else if(i != 0 && (x[i] <= *r.begin() && r.size() != 0))
            l.insert(x[i]);

        if((r.size()+l.size())%2==1){
            while(r.size()-l.size()!=1){
                if(r.size()>l.size()){
                    l.insert(*r.begin());
                    r.erase(r.begin());
                }
                else{
                    r.insert(*l.begin());
                    l.erase(l.begin());
                }
            }
        }
        else{
            while(r.size()-l.size()!=0){
                if(r.size()>l.size()){
                    l.insert(*r.begin());
                    r.erase(r.begin());
                }
                else{
                    r.insert(*l.begin());
                    l.erase(l.begin());
                }
            }
        }
        cout << "r: ";
        for(auto it2 = r.begin(); it2 != r.end(); it2++)
            cout << *it2 << " ";
        cout << endl;
        cout << "l: ";
        for(auto it3 = l.begin(); it3 != l.end(); it3++)
            cout << *it3 << " ";
        cout << endl;

        if((l.size() + r.size()) == k){
            if((l.size()+r.size())%2==1)
                cout << *r.begin() << " ";
            else
                cout << *l.begin() << " ";

            if(*it >= *r.begin())
                r.erase(r.find(*it));
            else
                l.erase(l.find(*it));
            it++;
        }

        if((r.size()+l.size())%2==1){
            while(r.size()-l.size()!=1){
                if(r.size()>l.size()){
                    l.insert(*r.begin());
                    r.erase(r.begin());
                }
                else{
                    r.insert(*l.begin());
                    l.erase(l.begin());
                }
            }
        }
        else{
            while(r.size()-l.size()!=0){
                if(r.size()>l.size()){
                    l.insert(*r.begin());
                    r.erase(r.begin());
                }
                else{
                    r.insert(*l.begin());
                    l.erase(l.begin());
                }
            }
        }
    }

    return 0;
}
