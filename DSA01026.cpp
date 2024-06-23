#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n;
int a[10004];
void in(){
    for(int i = 1; i <= n; i ++){
        if(a[i] == 0) cout << 6;
        else cout << 8;
    }
    // for(int i = 1; i <= n; i ++) cout << a[i];
    cout << '\n';
}
void tryy(int i){
    for(int j = 0; j <= 1; j ++){
        if(i == 0 && j == 0) continue;
        if(i == n && j == 1) continue;
        if(a[i - 1] == 1 && j == 1) continue;
        if(a[i - 1] == 0 && a[i - 2] == 0 && a[i - 3] == 0 && j == 0) continue;
        a[i] = j;
        if(i == n) in();
        else tryy(i + 1); 
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif         

    cin >> n;    
    tryy(1);            
    
    return 0;
}