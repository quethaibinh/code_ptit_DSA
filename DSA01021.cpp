#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, k, a[10004];
void sinh(){
    int i = k;
    // int b[k + 1];
    map<int, int> mp;
    for(int j = 1; j <= k; j ++) mp[a[j]] ++;
    while(i >= 1 && a[i] == n - k + i){
        -- i;
    }
    if(i == 0) cout << k << '\n';
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j ++) a[j] = a[j - 1] + 1;
        int cnt = 0;
        for(int j = 1; j <= k; j ++){
            if(mp.find(a[j]) == mp.end()) ++ cnt;
        }
        cout << cnt << '\n';
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
        cin >> n >> k;
        for(int i = 1; i <= k; i ++) cin >> a[i];
        sinh();
    }                    
    
    return 0;
}