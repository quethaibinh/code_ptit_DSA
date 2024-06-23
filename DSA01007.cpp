#include<bits/stdc++.h>

using namespace std;

#define ll long long

int ok;
void sinh(string &s){
    int i = s.size() - 1;
    while(i >= 0 && s[i] == 'B'){
        s[i] = 'A';
        -- i;
    }
    if(i == -1){
        ok = 0;
    }
    else{
        s[i] = 'B';
        // cout << s << ' ';
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
        int n;
        cin >> n;
        string s;
        ok = 1;
        for(int i = 0; i < n; i ++) s.push_back('A');
        while(ok){
            cout << s << ' ';
            sinh(s);
        }
        cout << '\n';
    }       
    
    return 0;
}