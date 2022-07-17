#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    while(n--)
    {
        string s;
        getline(cin, s);
        if(s.empty())
        {
            cout << "Yes" << '\n';
            continue;
        }

        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] == ')' || s[i] == ']') && st.size() == 0){
                cout << "No" << '\n';
                break;
            }

            if(s[i] == '(' || s[i] == '[')
                st.push(s[i]);

            if(s[i] == ')')
            {
                if(st.top() == '(')
                    st.pop();
                else
                {
                    cout << "No" << '\n';
                    break;
                }
            }
            if(s[i] == ']')
            {
                if(st.top() == '[')
                    st.pop();
                else
                {
                    cout << "No" << '\n';
                    break;
                }
            }

            if(i == s.length()-1 && st.size() == 0)
                cout << "Yes" << '\n';
            if(i == s.length()-1 && st.size() != 0)
                cout << "No" << '\n';
        }

    }

    return 0;
}
