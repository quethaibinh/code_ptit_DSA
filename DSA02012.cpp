#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, m;
int a[104][104];
int cnt = 0;
void solve(int d, int r){
    if(d == m - 1 && r == n - 1) cnt ++;
    if(d < m - 1) solve(d + 1, r);
    if(r < n - 1) solve(d, r + 1);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif             

    int t;
    cin >> t;
    while(t --){
        cin >> m >> n;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++) cin >> a[i][j];
        }
        solve(0, 0);
        cout << cnt << '\n';
        cnt = 0;
    }            
    
    return 0;
}