#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n;
string s;
vector<vector<char>> v;
void tryy(int bd, vector<char> vc){
    for(int j = bd; j < n; j ++){
        vc.push_back(s[j]);
        v.push_back(vc);
        tryy(j + 1, vc);
        vc.pop_back();
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
        cin >> s;
        tryy(0, {});
        for(auto x : v){
            for(int i = 0; i < x.size(); i ++) cout << x[i];
            cout << ' ';
        }
        v.clear();
        cout << '\n';
    }     

    return 0;
}