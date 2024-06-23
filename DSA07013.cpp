#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int check(char x, int a, int b){
    if(x == '*') return a * b;
    if(x == '+') return a + b;
    if(x == '-') return a - b;
    if(x == '/') return a / b;
}

void solve(string s){
    stack<int> st;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            int dig1 = st.top(); st.pop();
            int dig2 = st.top(); st.pop();
            // cout << dig1 << ' ' << dig2 << '\n';
            int ans = check(s[i], dig2, dig1);
            // cout << ans << '\n';
            st.push(ans);
        }
        else st.push(int(s[i] - '0'));
    }
    cout << st.top() << '\n';
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
        // cout << s << '\n';
        solve(s);
    }

    return 0;
}