#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    cin.ignore();
    while(t --){
        string s; getline(cin, s);
        bool check = false;
        // for(int i = 0; i < s.size(); i ++) cout << s[i] << '\n';
        stack<char> st;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
            if(s[i] == ']' || s[i] == ')'){
                if(!st.empty() && s[i] == ')' && st.top() == '(') st.pop();
                else if(!st.empty() && s[i] == ']' && st.top() == '[') st.pop();
                else st.push(s[i]);
            }
        }
        if(st.empty()) check = true;
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}