#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int maTranKe[1005][1005];
vector<int> ke[1005];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> maTranKe[i][j];
            if(maTranKe[i][j]) ke[i].push_back(j);
        }
    }
}

void output(){
    for(int i = 1; i <= n; i ++){
        for(int j : ke[i]) cout << j << ' ';
        cout << '\n';
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    output();

    return 0;
}