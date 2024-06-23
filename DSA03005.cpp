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
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        int s2 = 0, s1 = 0;
        for(int i = 0; i < n; i ++){
            if(k <= n / 2){
                if(i < k) s1 += a[i];
                else s2 += a[i];
            }
            else{
                if(i < n - k) s1 += a[i];
                else s2 += a[i];
            }
        }
        cout << s2 - s1 << '\n';
    }

    return 0;
}