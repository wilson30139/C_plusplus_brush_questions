#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long temp;
    vector<long long> x;
    for(int i = 0; i < n; i++){
        cin >> temp;
        x.push_back(temp);
    }

    multiset<long long> R;
    multiset<long long, greater<long long>> L;
    long long index = 0, RSum = 0, LSum = 0;
    for(int i = 0; i < n; i++){
        if(x[i] > *R.begin()){
            RSum += x[i];
            R.insert(x[i]);
        }
        else{
            LSum += x[i];
            L.insert(x[i]);
        }

        if(L.size()+R.size()>k){
            if(x[index] >= *R.begin()){
                RSum -= x[index];
                R.erase(R.find(x[index]));
            }
            else{
                LSum -= x[index];
                L.erase(L.find(x[index]));
            }
            index++;
        }

        if((L.size()+R.size())%2==0){
            while(L.size()!=R.size()){
                if(L.size()>R.size()){
                    RSum += *L.begin();
                    R.insert(*L.begin());
                    LSum -= *L.begin();
                    L.erase(L.find(*L.begin()));
                }
                else{
                    LSum += *R.begin();
                    L.insert(*R.begin());
                    RSum -= *R.begin();
                    R.erase(R.find(*R.begin()));
                }
            }
        }
        else{
            while(R.size()-L.size()!=1){
                if(L.size()>R.size()){
                    RSum += *L.begin();
                    R.insert(*L.begin());
                    LSum -= *L.begin();
                    L.erase(L.find(*L.begin()));
                }
                else{
                    LSum += *R.begin();
                    L.insert(*R.begin());
                    RSum -= *R.begin();
                    R.erase(R.find(*R.begin()));
                }
            }
        }

        if(i>=k-1){
            if(k%2==1)
                cout << RSum - *R.begin() * R.size() + *R.begin() * L.size() - LSum << " ";
            else
                cout << RSum - *L.begin() * R.size() + *L.begin() * L.size() - LSum << " ";
        }


    }
    return 0;
}
