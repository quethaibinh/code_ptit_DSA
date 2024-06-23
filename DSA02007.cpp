#include<bits/stdc++.h>

using namespace std;
#define ll long long

int k;
string maxs;
void tryy(int i, int cnt, string s){
    if(cnt == k || i == s.size()){
        maxs = max(maxs, s);
        return;
    }
    char maxx = s[i];
    vector<int> maxPos;
    for(int j = i + 1; j < s.size(); j ++){
        if(s[j] > maxx){
            maxx = s[j];
            maxPos.clear();
        }
        if(s[j] == maxx) maxPos.push_back(j);
    } 
    if(s[i] < maxx){
        for(int j = 0; j < maxPos.size(); j ++){
            string tmp = s;
            swap(tmp[i], tmp[maxPos[j]]);
            tryy(i + 1, cnt + 1, tmp);
        }
    }
    else tryy(i + 1, cnt, s);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif     

    int t;
    cin >> t;
    while(t --){
        string s;
        cin >> k >> s;
        maxs = "0";
        tryy(0, 0, s);
        cout << maxs << '\n';
    }   
    
    return 0;
}