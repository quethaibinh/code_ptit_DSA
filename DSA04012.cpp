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
        int n, m; cin >> n >> m;
        int a[n], b[m];
        int d[n + m - 1];
        memset(d, 0, sizeof(d));
        for(int &i : a) cin >> i;
        for(int &i : b) cin >> i;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                d[i + j] += a[i] * b[j];
            }
        }
        for(int i = 0; i < n + m - 1; i ++) cout << d[i] << ' ';
        cout << '\n';
    }

    return 0;
}