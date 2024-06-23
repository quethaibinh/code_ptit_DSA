#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, x, a[1000006];
bool cmp(int a, int b){
    // if(abs(x - a) == abs(x - b)) return a < b; 
    return abs(x - a) < abs(x - b);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif  

    int t;
    cin >> t;
    while(t --){
        cin >> n >> x;
        for(int i = 0; i < n; i ++) cin >> a[i];
        stable_sort(a, a + n, cmp);
        for(int i = 0; i < n; i ++) cout << a[i] << ' ';
        cout << '\n';
    }      
    
    return 0;
}