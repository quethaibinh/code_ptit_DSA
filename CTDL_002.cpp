#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, k, kt[1005], ok;
void khoitao(){
    for(int i = 0; i < n; i ++) kt[i] = 0;
}
void sinh(){
    int i = n - 1;
    while(i >= 0 && kt[i] == 1){
        kt[i] = 0;
        -- i;
    }
    if(i == -1) ok = 0;
    else kt[i] = 1;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    cin >> n >> k;
    int a[n];
    for(auto &x : a) cin >> x; 
    int cnt = 0;
    khoitao();
    ok = 1;
    while(ok){
        int tong = 0;
        for(int i = 0; i < n; i ++){
            if(kt[i]){
                tong += kt[i] * a[i];
            }
        }
        if(tong == k){
            cnt ++;
            for(int i = 0; i < n; i ++){
                if(kt[i]){
                    cout << a[i] << ' ';
                }
            }
            cout << '\n';
        }
        sinh();
    }        
    cout << cnt;          
    
    return 0;
}