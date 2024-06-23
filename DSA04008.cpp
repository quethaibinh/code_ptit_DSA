#include<bits/stdc++.h>

using namespace std;
#define ll long long

int mod = 1000000007;

struct matran{
    ll a[2][2];
    friend matran operator * (matran x, matran y){
        matran kq;
        for(int i = 0; i < 2; i ++){
            for(int j = 0; j < 2; j ++){
                kq.a[i][j] = 0;
                for(int k = 0; k < 2; k ++){
                    kq.a[i][j] += (x.a[i][k] * y.a[k][j]);
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq;
    }
};

matran ChiaTri(matran ax, int n){
    if(n == 1) return ax;
    matran X = ChiaTri(ax, n / 2);
    if(n % 2 == 0) return X * X;
    return X * X * ax;
}

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
        matran a1;
        a1.a[0][0] = 1;
        a1.a[0][1] = 1;
        a1.a[1][0] = 1;
        a1.a[1][1] = 0;
        matran kq = ChiaTri(a1, n);
        cout << kq.a[0][1] << '\n';
    }
    
    return 0;
}