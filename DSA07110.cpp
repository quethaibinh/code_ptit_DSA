#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else{
            if(!st.empty()){
                if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else{
                    cout << "NO";
                    return;
                }
            }
            else{
                cout << "NO";
                return;
            }
        }
    }
    if(!st.empty()) cout << "NO";
    else cout << "YES";
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        string s; cin >> s;
        solve(s);
        cout << '\n';
    }

    return 0;
}