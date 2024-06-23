#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int a[100005], b[100005];
int cnt[5];

int solve(int x){
    int ans = 0;
    if(x == 0) return 0;
    if(x == 1){
        return cnt[0];
    }
    ans += (cnt[0] + cnt[1]);
    int i = upper_bound(b, b + m, x) - b;
    ans += (m - i);
    if(x == 2){
        ans -= (cnt[3] + cnt[4]);
    }
    if(x == 3){
        ans += cnt[2];
    }
    return ans;
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
        cin >> n >> m;
        int ans = 0;
        for(int i = 0; i < 5; i ++) cnt[i] = 0;
        for(int i = 0; i < n; i ++) cin >> a[i];
        for(int i = 0; i < m; i ++){
            cin >> b[i];
            if(b[i] < 5) cnt[b[i]] ++;
        }
        sort(a, a + n);
        sort(b, b + m);
        for(int i = 0; i < n; i ++){
            ans += solve(a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}