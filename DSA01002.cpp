#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sinh(int a[], int n, int k){
    int i = k - 1;
    while(i >= 0 && a[i] == n - k + i + 1) -- i;
    if(i == -1){
        for(int i = 0; i < k; i ++){
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    else{
        a[i] ++;
        // int j = i + 1;
        for(int j = i + 1; j < k; j ++){
            a[j] = a[j - 1] + 1;
        }
        for(int i = 0; i < k; i ++) cout << a[i] << ' ';
        cout << '\n';
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
        int a[k];
        for(auto &x : a) cin >> x;
        sinh(a, n, k);
    }                
    
    return 0;
}