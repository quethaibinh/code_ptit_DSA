#include<bits/stdc++.h>

using namespace std;

#define ll long long

int ok;
void sinh(int n, int k, int a[]){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) -- i;
    if(i == 0) ok = 0;
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j ++){
            a[j] = a[j - 1] + 1;
        }
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
        int n, k, cnt = 0;
        cin >> n >> k;
        int a[k + 1];
        map<int, int> mp;
        for(int i = 1; i <= k; i ++){
            cin >> a[i];
            mp[a[i]] ++;
        }
        ok = 1;
        sinh(n, k, a);
        if(ok){
            for(int i = 1; i <= k; i ++){
                if(mp.find(a[i]) == mp.end()) cnt ++;
            }
        }
        else cnt = k;
        cout << cnt << '\n';
    }                   
    
    return 0;
}