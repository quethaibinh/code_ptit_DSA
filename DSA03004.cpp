#include<bits/stdc++.h>

using namespace std;
#define ll long long

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
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        ll s1 = 0, s2 = 0;
        for(int i = 0; i < n ; i ++){
            if(i % 2 == 0) s1 = s1 * 10 + a[i];
            else s2 = s2 * 10 + a[i];
        }
        cout << s1 + s2 << '\n';
    }

    return 0;
}