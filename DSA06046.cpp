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
        int n, min_kc = INT_MAX;
        cin >> n;
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        for(int i = 1; i < n; i ++){
            min_kc = min(min_kc, a[i] - a[i - 1]);
        }
        cout << min_kc << '\n';
    }

    return 0;
}