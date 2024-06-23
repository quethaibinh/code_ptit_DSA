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
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        int l = 0, r = n - 1, cnt = 0;
        while(l <= r){
            if(cnt % 2 == 0) cout << a[r --] << ' ';
            else cout << a[l ++] << ' ';
            cnt ++;
        }
        cout << '\n';
    }
    
    return 0;
}