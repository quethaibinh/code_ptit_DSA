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
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < n; i ++){
            int x; cin >> x;
            q.push(x);
        }
        ll ans = 0;
        while(!q.empty()){
            ll d1 = q.top(); q.pop();
            ll d2 = q.top(); q.pop();
            ans += (d1 + d2);
            // cout << d1 << ' ' << d2 << '\n';
            if(q.empty()) break;
            q.push(d1 + d2);
        }
        cout << ans << '\n';
    }

    return 0;
}