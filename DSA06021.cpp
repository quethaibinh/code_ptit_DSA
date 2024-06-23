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
        int n, x;
        cin >> n >> x;
        for(int i = 1; i <= n; i ++){
            int m; cin >> m;
            if(m == x) cout << i << '\n';
        }
    } 
    
    return 0;
}