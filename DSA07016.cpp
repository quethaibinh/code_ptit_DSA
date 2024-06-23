#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve(string s){
    stack<int> st;
    int cnt = 1;
    st.push(cnt ++);
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == 'D') st.push(cnt ++);
        else{
            while(!st.empty()){
                cout << st.top();
                st.pop();
            }
            st.push(cnt ++);
        }
    }
    while(!st.empty()){
        cout << st.top(); 
        st.pop();
    }
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