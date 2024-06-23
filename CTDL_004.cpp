#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;
int a[100005], a1[100005], b[100005];
int cnt;

void tryy(int i){
    for(int j = a1[i - 1] + 1; j <= n - k + i; j ++){
        if(a[j] > b[i - 1]){
            b[i] = a[j];
            a1[i] = j;
            if(i == k) cnt ++;
            else tryy(i + 1);
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif            

    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];             
    tryy(1);
    cout << cnt;

    return 0;
}