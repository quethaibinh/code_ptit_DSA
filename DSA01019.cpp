#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, a[10004];

void inkq(){
    for(int i = 1; i <= n; i ++){
        if(a[i] == 1) cout << 'H';
        else cout << 'A';
    }
    cout << '\n';
}

void tryy(int i){
    for(int j = 0; j <= 1; j ++){
        if(i == 1 && j == 0) continue;
        if(j == 1 && i == n) continue;
        if(a[i - 1] == 1 && j == 1) continue;
        a[i] = j;
        if(i == n) inkq();
        else tryy(i + 1);
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
        cin >> n;
        int i = 1;
        tryy(i);
    }                  
    
    return 0;
}