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
        int n, minn = INT_MAX;
        cin >> n;
        int a[n];
        for(auto &x : a){
            cin >> x;
            minn = min(minn, x);
        }
        for(int i = n - 1; i >= 0; i --){
            if(a[i] == minn){
                int k = i;
                while(a[k] == minn) -- k;
                cout << k + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}