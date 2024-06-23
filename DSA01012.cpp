#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[1005];
void in(){
    cout << a[1];
    for(int i = 2; i <= n; i ++){
        if(a[i - 1] == 1) cout << abs(a[i] - 1);
        else cout << a[i];
    }
    cout << ' ';
}

void tryy(int i){
    for(int j = 0; j <= 1; j ++){
        a[i] = j;
        if(i == n) in();
        else tryy(i + 1);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        cin >> n;
        tryy(1);
        cout << '\n';
    }

    return 0;
}