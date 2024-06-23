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
    
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0;
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i ++){
            sum += (a[i] * i) % MOD;
            sum %= MOD;
        }
        cout << sum << '\n';
    }

    return 0;
}