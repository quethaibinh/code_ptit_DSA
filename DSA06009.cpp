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
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        int cnt = 0;
        for(int l = 0; l < n; l ++){
            for(int r = l + 1; r < n; r ++){
                if(a[l] + a[r] == k) cnt ++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}