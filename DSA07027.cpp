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
        int a[n];
        stack<int> st;
        for(int &i : a) cin >> i;
        st.push(0);
        for(int i = 1; i < n; i ++){
            while(!st.empty() && a[i] > a[st.top()]){
                a[st.top()] = a[i]; st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            a[st.top()] = -1; st.pop();
        }
        for(int i : a) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}