#include<bits/stdc++.h>

using namespace std;
#define ll long long

string s;
int n, k;
int a[100005];
string sc;
set<string> v;
void tryy(int i, int bd){
    for(int j = bd; j < s.size(); j ++){
        sc.push_back(s[j]);
        if(i == k) v.insert(sc);
        else tryy(i + 1, j + 1);
        sc.pop_back();
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t;
    cin >> t;
    while(t --){
        cin >> s >> k;
        tryy(1, 0);
        for(auto x : v) cout << x << '\n';
        v.clear();
    }

    return 0;
}