#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sinh(string &s){
    int i = s.size() - 2;
    while(i >= 0 && s[i] >= s[i + 1]) -- i;
    if(i == -1) cout << "BIGGEST\n";
    else{
        int j = s.size() - 1;
        while(s[j] <= s[i]) -- j;
        swap(s[i], s[j]);
        int l = i + 1, r = s.size() - 1;
        while(l < r) swap(s[l ++], s[r --]);
        cout << s << '\n';
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
        int tt;
        string s;
        cin >> tt >> s;
        cout << tt << ' ';
        sinh(s);
    }               
    
    return 0;
}