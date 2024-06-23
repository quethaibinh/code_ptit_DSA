#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

bool check(int s, int i){
    vector<int> vc;
    while(s >= 1){
        vc.push_back(s % 10);
        s /= 10;
    }
    for(int i1 : vc){
        if(i == i1) return false;
    }
    return true;
}

vector<int> v;
void solve(){
    queue<int> q;
    for(int i = 1; i <= 5; i ++){
        q.push(i);
    }
    while(!q.empty()){
        int tes = q.front(); q.pop();
        v.push_back(tes);
        if(tes > 100000) return ;
        for(int i = 0; i <= 5; i ++){
            if(check(tes, i)){
                q.push(tes * 10 + i);
                // cout << tes * 10 + i << '\n';
            }
        }
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
    solve();
    while(t --){
        int l, r; cin >> l >> r;
        auto x = lower_bound(v.begin(), v.end(), l);
        auto y = upper_bound(v.begin(), v.end(), r);
        // cout << v[3] << ' ' << v[7] << '\n';
        // cout << y - v.begin() << ' ' << x - v.begin() << '\n';
        int ans = y - x;
        cout << ans << '\n';
    }

    return 0;
}