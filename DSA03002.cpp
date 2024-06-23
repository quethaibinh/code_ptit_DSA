#include<bits/stdc++.h>

using namespace std;
#define ll long long

string change(string &s, int check){
    for(int i = 0; i < s.size(); i ++){
        if(!check && s[i] == '6') s[i] = '5';
        if(check && s[i] == '5') s[i] = '6';
    }
    return s;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      
    
    int n, m;
    cin >> n >> m;
    string s1 = to_string(n), s2 = to_string(m);
    int minn = stoi(change(s1, 0)) + stoi(change(s2, 0));
    int maxx = stoi(change(s1, 1)) + stoi(change(s2, 1));
    cout << minn << ' ' << maxx;

    return 0;
}