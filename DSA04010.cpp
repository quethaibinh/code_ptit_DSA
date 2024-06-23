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
        int a[n], tong[n + 1];
        int max_tong = 0;
        tong[0] = 0;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            if(i == 0) tong[i + 1] = a[i];
            else tong[i + 1] = tong[i] + a[i]; 
        }
        for(int i = 0; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++) max_tong = max(max_tong, tong[j] - tong[i]);
        }
        cout << max_tong << '\n';
    }      
    
    return 0;
}