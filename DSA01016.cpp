#include<bits/stdc++.h>

using namespace std;
#define ll long long

int a[1000006], n, cnt, ok;
void khoi_tao(){
    a[1] = n;
    cnt = 1;
}
void sinh(){
    int i = cnt;
    while(i >= 1 && a[i] == 1) -- i;
    if(i == 0) ok = 0;
    else{
        a[i] --;
        int d = cnt - i + 1;
        cnt = i;
        int x = d / a[i], y = d % a[i];
        for(int j = 0; j < x; j ++) a[++ cnt] = a[i];
        if(y != 0) a[++ cnt] = y;
    }
}

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
        cin >> n;
        khoi_tao();
        ok = 1;
        while(ok){
            cout << '(';
            for(int i = 1; i <= cnt; i ++){
                if(i == cnt) cout << a[i];
                else cout << a[i] << ' ';
            }
            cout << ") ";
            sinh();
        }
        cout << '\n';
    }

    return 0;
}