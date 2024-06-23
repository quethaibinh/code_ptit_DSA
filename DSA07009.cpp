#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve(string s){
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i --){
        if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') st.push(string(1, s[i]));
        else{
            string bt1 = st.top(); st.pop();
            string bt2 = st.top(); st.pop();
            string tes = "(" + bt1 + s[i] + bt2 + ")";
            // cout << tes << '\n';
            st.push(tes);
        }
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
        solve(s);
    }

    return 0;
}