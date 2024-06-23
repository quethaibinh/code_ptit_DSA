#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[1006], ok;
void khoitao(int n){
    for(int i = 1; i <= n; i ++){
        a[i] = 0;
    }
}
void sinh(int n){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        -- i;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif            

    int n;
    cin >> n;
    if(n % 2 == 0){
        khoitao(n / 2);
        ok = 1;
        while(ok){
            for(int i = 1; i <= n / 2; i ++){
                cout << a[i] << ' ';
            }
            for(int i = n / 2; i >= 1; i --){
                cout << a[i] << ' ';
            }
            cout << '\n';
            sinh(n / 2);
        }
    }  
    else{
        ok = 1;
        khoitao(n / 2);
        while(ok){
            for(int j = 0; j <= 1; j ++){
                for(int i = 1; i <= n / 2; i ++){
                    cout << a[i] << ' ';
                }
                cout << j << ' ';
                for(int i = n / 2; i >= 1; i --){
                    cout << a[i] << ' ';
                }
            }
            cout << '\n';
            sinh(n / 2);
        }
    }
    
    return 0;
}