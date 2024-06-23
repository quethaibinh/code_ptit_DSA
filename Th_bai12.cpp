#include<bits/stdc++.h>

using namespace std;
#define ll long long
int mod = 1e9 + 7;

struct matran{
    int n;
    ll a[105][105];
    friend matran operator * (matran a1, matran a2){
        matran kq;
        kq.n = a1.n;
        for(int i = 0; i < a1.n; i ++){
            for(int j = 0; j < a1.n; j ++){
                kq.a[i][j] = 0;
                for(int k = 0; k < a1.n; k ++){
                    kq.a[i][j] += (a1.a[i][k] * a2.a[k][j]);
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq;
    }
};

void nhap(matran &x, ll &k){
    cin >> x.n >> k;
    for(int i = 0; i < x.n; i ++){
        for(int j = 0; j < x.n; j ++) cin >> x.a[i][j];
    }
}

matran tryy(matran a, ll k){
    if(k == 1) return a;
    matran kq = tryy(a, k / 2);
    if(k % 2 == 0) return kq * kq;
    return kq * kq * a;
}

ll tong(matran a1){
    ll sum = 0;
    for(int i = 0; i < a1.n; i ++){
        sum += a1.a[i][i];
        sum %= mod;
    }
    return sum;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif   

    int t;
    cin >> t;
    while(t --){
        ll k;
        matran x;
        nhap(x, k);
        matran x1 = tryy(x, k);
        // for(int i = 0; i < x1.n; i ++){
        //     for(int j = 0; j < x1.n; j ++) cout << x1.a[i][j] << ' ';
        //     cout << '\n';
        // }
        cout << tong(x1) << '\n';
    }     
    
    return 0;
}