#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif        

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n + 1], li[n + 1] = {}, ri[n + 1] = {};
        for(int i = 1; i <= n; i ++) cin >> a[i];
        int ans = 0;
        for(int l = 1; l <= n; l ++){
            if(a[l] > a[l - 1]) li[l] = li[l - 1] + 1;
            else li[l] = 1;
        }
        for(int r = n; r >= 1; r --){
            if(a[r] > a[r + 1]) ri[r] = ri[r + 1] + 1;
            else ri[r] = 1;
        }
        for(int i = 1; i <= n; i ++) ans = max(ans, li[i] + ri[i] - 1);
        cout << ans << '\n';
    }

    return 0;
}