#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[1005];
int vis[1005];
void xuly(){
    int sum = 0;
    for(int i = 1; i < n; i ++){
        sum += (a[i] - a[i + 1]);
    }
    if(sum > 0){
        for(int i = 1; i <= n; i ++) cout << a[i] << ' ';
        cout << '\n';
    }
}

void tryy(int i){
    for(int j = 1; j <= n; j ++){
        if(!vis[j]){
            vis[j] = 1;
            a[i] = j;
            if(i == n) xuly();
            else tryy(i + 1);
            vis[j] = 0;
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n;
    tryy(1);

    return 0;
}