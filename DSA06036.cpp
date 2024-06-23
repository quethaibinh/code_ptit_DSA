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
        int n, k;
        cin >> n >> k;
        int a[n];
        bool check = false;
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        for(int l = 0; l < n - 2; l ++){
            if(a[l] < k){
                int m = l + 1, r = n - 1;
                while(m < r){
                    if(a[l] + a[m] + a[r] == k){
                        check = true;
                        break;
                    }
                    else if(a[l] + a[m] + a[r] < k) m ++;
                    else r --;
                } 
                if(check) break;
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}