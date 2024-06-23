#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[10005];
void khoitao(int n, int k){
    for(int i = 1; i <= k; i ++){
        a[i] = i;
    }
}
void sinh(int n, int k, int &ok){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){ 
        -- i;
    }
    if(i == 0){
        ok = 0;
    }
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j ++){
            a[j] = a[j - 1] + 1;
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
    while(t --){
        int n, k;
        cin >> n >> k;
        // int a[n + 1];
        int ok = 1;
        khoitao(n, k);
        while(ok){
            for(int i = 1; i <= k; i ++) cout << a[i];
            cout << ' ';
            sinh(n, k, ok);
        }
        cout << '\n';
    }                    
    
    return 0;
}