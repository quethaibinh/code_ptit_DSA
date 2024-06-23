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

    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i ++) cin >> a[i];
    stack<int> st;
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(st.empty()) st.push(i);
        else{
            if(a[st.top()] > a[i]){
                st.push(i);
                cnt ++;
            }
            else{
                while(!st.empty() && a[st.top()] <= a[i]){
                    cnt ++;
                    st.pop();
                }
                st.push(i);
                cnt ++;
            }
        }
    }
    cout << cnt;

    return 0;
}