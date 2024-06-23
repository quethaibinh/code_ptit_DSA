#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve(string s){
    stack<string> st;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            string bt1 = st.top(); st.pop();
            string bt2 = st.top(); st.pop();
            string ans = "(" + bt2 + s[i] + bt1 + ")";
            st.push(ans);
        } 
        else st.push(string(1, s[i]));  
    }
    cout << st.top();
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