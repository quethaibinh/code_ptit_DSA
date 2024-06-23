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
        ll a[n], pow_a[n];
        bool check = false;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            pow_a[i] = a[i] * a[i];
        }
        sort(pow_a, pow_a + n);
        for(int i = 0; i < n - 2; i ++){
            for(int j = i + 1; j < n - 1; j ++){
                auto x = lower_bound(pow_a + j + 1, pow_a + n, pow_a[i] + pow_a[j]);
                if(pow_a[i] + pow_a[j] == *x){
                    check = true;
                    break;
                }
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}