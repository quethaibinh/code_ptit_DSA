#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, a[1000006], a1[1000006];
bool check;
int tong;
void tryy(int i, int sum){
    if(sum == tong / 2){
        check = true;
        return;
    }
    if(check || sum >= tong / 2 || i == n) return;
    if(sum < tong / 2){
        tryy(i + 1, sum + a[i]);
    }
    tryy(i + 1, sum);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int t;
    cin >> t;
    while(t --){
        cin >> n;
        check = false;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            tong += a[i];
        }
        if(tong % 2 == 0) tryy(1, 0);
        if(check) cout << "YES\n";
        else cout << "NO\n";
        tong = 0;
    }                   
    
    return 0;
}