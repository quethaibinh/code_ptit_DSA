#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int A[1005], B[1005];
int C[105][105];

bool equals(int a, int b, int c, int d){
    return abs(((double) a / b - (double) c / d)) < 0.000001;
}

int qhd(){
    int ans = 0;
    for(int i = 1; i < n; i ++){    
        for(int j = 1; j < m; j ++){
            if(equals(A[i], B[j], A[i - 1], B[j - 1])) C[i][j] = C[i - 1][j - 1] + 1;
            else C[i][j] = 1;
            ans = max(ans, C[i][j]);
        }
    }
    return ans;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n >> m;
    A[0] = B[0] = -1;
    for(int i = 1; i <= n; i ++) cin >> A[i];
    for(int j = 1; j <= m; j ++) cin >> B[j];
    cout << qhd() << '\n';
    

    return 0;
}