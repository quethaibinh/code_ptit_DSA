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
    while(t --){
        int n; cin >> n;
        int a[n + 1], f[n + 1], ans[n + 1];
        map<int, int> mp;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            mp[a[i]] ++;
        }
        for(int i = 1; i <= n; i ++) f[i] = mp[a[i]];
        stack<int> st;
        st.push(1);
        for(int i = 2; i <= n; i ++){
            if(f[i] <= f[st.top()]) st.push(i);
            else{
                while(!st.empty() && f[i] > f[st.top()]){
                    ans[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            ans[st.top()] = -1;
            st.pop();
        }
        for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}