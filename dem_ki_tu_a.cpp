#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll fib[100];
ll fib2[100];
int fibo(int n, int k){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(k < fib[n - 2]) return fibo(n - 2, k);
    else if(k > fib[n - 2]) return fibo(n - 1, k - fib[n - 2]) + fib2[n - 2];
    else return fib2[k - 1];
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    fib2[0] = 1; fib2[1] = 0;
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= 93; i ++){
        fib[i] = fib[i - 1] + fib[i - 2];
        fib2[i] = fib2[i - 1] + fib2[i - 2];
    }
    while(t --){
        int n, k; cin >> n >> k;
        cout << fibo(n, k) << '\n';
    }

    return 0;
}