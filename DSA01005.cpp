#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif           

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i ++) a[i] = n - i;
        for(auto x : a) cout << x;
        cout << ' ';
        while(prev_permutation(a, a + n)){
            for(int i = 0; i < n; i ++) cout << a[i];
            cout << ' ';
        }
        cout << '\n';
    }              
    
    return 0;
}