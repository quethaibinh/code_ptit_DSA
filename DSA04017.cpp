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
        ll a[n], b[n], check;
        bool check1 = true;
        for(int i = 0; i < n; i ++) cin >> a[i];
        for(int i = 0; i < n - 1; i ++){
            cin >> b[i];
            if(b[i] != a[i] && check1){
                check = i + 1; 
                check1 = false;
            }
        }
        cout << check << '\n';
    }
    
    return 0;
}