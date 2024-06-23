#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;


// ll f[35][35] = {};
// void p(){
//     f[0][0] = 0;
//     f[0][1] = f[1][0] = 1;
//     for(int  i = 0; i <= 30; i ++){
//         for(int j = 0; j <= 30; j ++){
//             if(i == 0) f[i][j] = 1;
//             if(j == 0) f[i][j] = f[i - 1][1];
//             if(i && j) f[i][j] = f[i - 1][j + 1] + f[i][j - 1];
//         }
//     }
// }

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        vector<string> v;
        queue<string> q;
        q.push("");
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(s.length() == n) v.push_back(s);
            if(s.length() == n) continue;
            q.push(s + "6");
            q.push(s + "8");
        }
        cout << v.size() << '\n';
    }

    return 0;
}