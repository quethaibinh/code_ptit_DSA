#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll cnt;
void sx(ll a[], int l, int r){
    if(l >= r) return;
    int m = (l + r) / 2;
    sx(a, l, m);
    sx(a, m + 1, r);
    vector<ll> l1(a + l, a + m + 1);
    vector<ll> r1(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < l1.size() && j < r1.size()){
        if(l1[i] <= r1[j]) a[l ++] = l1[i ++];
        else{
            cnt += l1.size() - i;
            a[l ++] = r1[j ++];
        } 
    }
    while(i < l1.size()) a[l ++] = l1[i ++];
    while(j < r1.size()) a[l ++] = r1[j ++];
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      
    
    int t;
    cin >> t;
    while(t --){
        cnt = 0;
        int n;
        cin >> n;
        ll a[n];
        for(auto &x : a) cin >> x;
        sx(a, 0, n - 1);
        cout << cnt;
        cout << '\n';
    }

    return 0;
}