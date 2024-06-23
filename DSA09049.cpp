#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<int> ke[1000005];
ll soDinh[1000005]; // luu so dinh con cua cay co nut goc la i
ll ans[1000005]; // luu ket qua - luong dinh duong nut i nhan duoc

ll DFS1(int u){ // tim so dinh con cua tung nut
    ll res = 1;
    for(int i : ke[u]){
        res += DFS1(i);
    }
    soDinh[u] = res - 1;
    return res;
}

ll DFS2(int u){ // tim ket qua
    ll res = 1;
    for(int i : ke[u]){
        res += DFS2(i) + soDinh[i] + 1;
    }
    ans[u] = res;
    return res;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n;
    for(int i = 2; i <= n; i ++){
        int x; cin >> x;
        ke[x].push_back(i);
    }
    DFS1(1);
    DFS2(1);
    for(int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
    }

    return 0;
}