#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[100005];
int ok;
void khoitao(int k){
    for(int i = 1; i <= k; i ++) a[i] = i;
}
void sinh(int n, int k){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) -- i;
    if(i == 0) ok = 0;
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j ++) a[j] = a[j - 1] + 1;
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif          

    while(1){
        int n, k, s;
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0) break;
        int cnt = 0;
        if(n >= k){
            khoitao(k);
            ok = 1;
            while(ok){
                int tong = 0;
                for(int i = 1; i <= k; i ++) tong += a[i];
                if(tong == s) cnt ++;
                sinh(n, k);
            }
        }
        cout << cnt << '\n';
    }               
    
    return 0;
}