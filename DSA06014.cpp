#include<bits/stdc++.h>

using namespace std;
#define ll long long

int a[1000006];
void sng(){
    for(int i = 2; i <= 1000000; i ++) a[i] = 1;
    for(int i = 2; i <= 1000;i ++){
        if(a[i]){
            for(int j = i * i; j <= 1000000; j += i) a[j] = 0;
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif        

    int t;
    cin >> t;
    sng();
    while(t --){
        int n;
        cin >> n;
        bool check = false;
        for(int i = 2; i <= n; i ++){
            if(a[i]){
                if(a[n - i]){
                    cout << i << ' ' << n - i << '\n';
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        if(!check) cout << -1 << '\n';
    }
    
    return 0;
}