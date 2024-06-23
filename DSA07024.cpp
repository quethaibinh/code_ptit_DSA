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
        int a[n + 1];
        int ans = 0;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        stack<int> st;
        st.push(1);
        for(int i = 2; i <= n; i ++){
            while(!st.empty() && a[st.top()] >= a[i]){
                int hight = st.top();
                st.pop();
                int width;
                if(st.empty()) width = i - 1;
                else width = i - st.top() - 1;
                if(width >= a[hight]) ans = max(a[hight], ans);
            }
            st.push(i);
        }
        while(!st.empty()){
            int width;
            int hight = st.top(); st.pop();
            if(st.empty()) width = n;
            else width = n - st.top() - 1;
            if(width >= a[hight]) ans = max(ans, a[hight]);
        }
        cout << ans << '\n';
    }
    return 0;
}