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
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        int cnt = 0;
        for(int i = 1; i < n; i ++){
            if(a[i] - a[i - 1] > 1) cnt += (a[i] - a[i - 1] - 1);
        }
        cout << cnt << '\n';
    }
    
    return 0;
}