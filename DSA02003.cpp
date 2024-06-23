#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n;
int a[100][100];
string s;
vector<string> v;
void tryy(int r, int d){
    if(r == n - 1 && d == n - 1){
        v.push_back(s);
    }
    if(a[d + 1][r] == 1 && d < n - 1){
        s = s + 'D';
        tryy(r, d + 1);
        s.pop_back();
    }
    if(a[d][r + 1] == 1 && r < n - 1){
        s = s + 'R';
        tryy(r + 1, d);
        s.pop_back();
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif          

    int t;
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                cin >> a[i][j];
            }
        }
        if(a[0][0] == 1) tryy(0, 0);
        if(v.size() == 0) cout << -1 << '\n';
        else{
            for(auto x : v) cout << x << ' ';
            cout << '\n';
        }
        v.clear();
    }               
    
    return 0;
}