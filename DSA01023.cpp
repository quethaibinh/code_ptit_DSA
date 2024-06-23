#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[10005], ok;
void khoitao(int n, int k){
    for(int i = 1; i <= k; i ++) a[i] = i;
}

void sinh(int n, int k){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) -- i;
    if(i == 0) ok = 0;
    else{
        a[i] ++;
        for(int j = i + 1; j <= k; j ++) a[j] = a[j - 1] + 1;
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
        int a1[k];
        ok = 1;
        string s;
        for(int i = 0; i < k; i ++){
            cin >> a1[i];
            s.push_back(a1[i]);
        }
        vector<string> v;
        khoitao(n, k);
        while(ok){
            string s1;
            for(int i = 1; i <= k; i ++){
                s1.push_back(a[i]);
            }
            v.push_back(s1);
            sinh(n, k);
        }
        auto m = lower_bound(v.begin(), v.end(), s);
        cout << m - v.begin() + 1 << '\n';
    }                
    
    return 0;
}