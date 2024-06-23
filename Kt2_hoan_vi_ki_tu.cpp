#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

char c1, c2;
int n;
int vis[1005];
int a[1005];
void in(){
    for(int i = 1; i <= n; i ++) cout << char(a[i] + min(c1, c2) - 1);
    cout << '\n';
}

void tryy(int i){
    for(int j = 1; j <= n; j ++){
        if(!vis[j]){
            vis[j] = 1;
            a[i] = j;
            if(i == n) in();
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

    cin >> c1 >> c2;
    n = abs(c1 - c2) + 1;
    tryy(1);

    return 0;
}