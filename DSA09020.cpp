#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<int> ke[1005];
int maTranKe[1005][1005];
void input(){
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i ++){
        string s;
        getline(cin, s);
        string token;
        stringstream ss(s);
        while(ss >> token){
            ke[i].push_back(stoi(token));
        }
    }
}

void chuyen(){
    memset(maTranKe, 0, sizeof(maTranKe));
    for(int i = 1; i <= n; i ++){
        for(int j : ke[i]) maTranKe[i][j] = 1;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cout << maTranKe[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    chuyen();

    return 0;
}