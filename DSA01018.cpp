#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k, ok;
int a[1000006], ac[1000006];
void sinh(){
    int i = k;
    while(i >= 1  && a[i] == a[i - 1] + 1) -- i;
    if(i != 0) a[i] --;
    for(int j = i + 1; j <= k; j ++) a[j] = n - k + j;
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
        cin >> n >> k;
        for(int i = 1; i <= k; i ++) cin >> a[i];
        sinh();
        for(int i = 1; i <= k; i ++) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}