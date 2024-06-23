#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n;
int a[100005];
vector<vector<char>> v;
void in(){
    map<int, int> mp;
    vector<char> vc;
    for(int i = 1; i <= n; i ++){
        if(a[i] == 0) vc.push_back('A');
        else if(a[i] == 1) vc.push_back('B');
        else vc.push_back('C');
        mp[a[i]] ++;
    }
    if(mp[0] != 0 && mp[1] != 0 && mp[2] != 0 && mp[0] <= mp[1] && mp[1] <= mp[2]) v.push_back(vc);
}
void tryy(int i){
    for(int j = 0; j <= 2; j ++){
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

    int n1;
    cin >> n1;    
    for(int i = 1; i <= n1; i ++){
        n = i;
        tryy(1);
        for(auto x : v) {
            for(auto y : x) cout << y;
            cout << '\n';
        } 
        v.clear();
    }
    
    return 0;
}