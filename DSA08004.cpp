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
        int k; cin >> k;
        string s; cin >> s;
        // cout << 'Z' - 'A';
        priority_queue<int> q;
        ll ans = 0;
        int check[26];
        memset(check, 0, sizeof(check));
        for(int i = 0; i < s.size(); i ++){
            check[(s[i] - 'A')] ++;
        }
        for(int i = 0; i < 26; i ++){
            if(check[i]) q.push(check[i]);
        }
        while(k --){
            if(!q.empty()){
                int tes = q.top(); q.pop();
                tes --;
                q.push(tes);
            }
            else break;
        }
        while(!q.empty()){
            ll res = q.top(); q.pop();
            ans += res * res;
        }
        cout << ans << '\n';
    }

    return 0;
}