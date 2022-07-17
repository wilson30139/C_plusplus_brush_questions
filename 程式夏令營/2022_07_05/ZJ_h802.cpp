#include <bits/stdc++.h>
using namespace std;
class Person{
    public:
        int number;
        long long S;
        long long T;
        int totalLost;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Person> personList;
    for(int i = 0; i < n; i++){
        Person person;
        person.totalLost = 0;
        person.number = i+1;
        personList.push_back(person);
    }
    for(int i = 0; i < n; i++)
        cin >> personList[i].S;
    for(int i = 0; i < n; i++)
        cin >> personList[i].T;
    vector<int> order;
    for(int i = 0; i < n; i++){
        int n1;
        cin >> n1;
        order.push_back(n1);
    }

    vector<Person> temp;
    for(int i = 0; i < order.size(); i++)
        temp.push_back(personList[order[i]-1]);
    personList.clear();

    for(auto t : temp){
        personList.push_back(t);
    }

    while(personList.size() > 1){
        vector<Person> win, lost;
        for(int i = 0; i < personList.size(); i+=2){
            if(i == personList.size()-1){
                win.push_back(personList[i]);
                break;
            }

            long long a = personList[i].S;
            long long b = personList[i].T;
            long long c = personList[i+1].S;
            long long d = personList[i+1].T;
            if(a*b >= c*d){
                personList[i].S = a + c * d / (2 * b);
                personList[i].T = b + c * d / (2 * a);
                personList[i+1].S = c + c / 2;
                personList[i+1].T = d + d / 2;
                personList[i+1].totalLost += 1;
                if(personList[i+1].totalLost < m)
                    lost.push_back(personList[i+1]);
                win.push_back(personList[i]);
            }else{
                personList[i].S = a + a / 2;
                personList[i].T = b + b / 2;
                personList[i+1].S = c + a * b / (2 * d);
                personList[i+1].T = d + a * b / (2 * c);
                personList[i].totalLost += 1;
                if(personList[i].totalLost < m)
                    lost.push_back(personList[i]);
                win.push_back(personList[i+1]);
            }
        }

        personList.clear();
        for(int i = 0; i < win.size(); i++)
            personList.push_back(win[i]);
        for(int i = 0; i < lost.size(); i++)
            personList.push_back(lost[i]);
    }
    cout << personList[0].number << '\n';

    return 0;
}
