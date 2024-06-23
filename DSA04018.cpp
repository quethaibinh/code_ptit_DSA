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
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            if(a[i] == 0) cnt ++;
        }
        cout << cnt << '\n';
    }   
    
    return 0;
}