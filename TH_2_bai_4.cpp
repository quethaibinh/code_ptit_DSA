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

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), nxt(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    stack<int> st;
    for(int i = n; i >= 1; i --){
        while(!st.empty() && a[i] >= a[st.top()]) st.pop();
        if(st.size()) nxt[i] = st.top();
        else nxt[i] = n + 1;
        st.push(i);
    }
    // for(int i = 1; i <= n; i ++) cout << i << ' ' << nxt[i] << '\n';
    vector<int> dp(n + 5);
    for(int i = n; i >= 1; i --){
        dp[i] = dp[nxt[i]] + 1;
    }
    while(q --){
        int x; cin >> x;
        cout << dp[x] - 1 << '\n';
    }

    return 0;
}