#include <bits/stdc++.h>
using namespace std;

void TestCase() {
    int n, count;
    string st, en, s;
    cin >> n >> st >> en;
    set<string> dd;
    while (n--) {
        cin >> s;
        dd.insert(s);
    }

    queue<pair<string, int>> q;
    q.push({st, 1});
    while (!q.empty()) {
        s = q.front().first;
        count = q.front().second;
        q.pop();

        if (s == en) {
            cout << count;
            return;
        }
        
        for (int i = 0; i < s.length(); ++i) {
            string tmp = s;
            for (char j = 'A'; j <= 'Z'; ++j) {
                tmp[i] = j;
                if (dd.find(tmp) != dd.end()) {
                    dd.erase(tmp);
                    q.push({tmp, count + 1});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 1; cin >> T;
    while (T--) {
        TestCase();
        cout << endl;
    }
    return 0;
}



// code tle
// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// const int MOD = 1e9 + 7;

// int n;
// string s, t; 
// int startt, endd;
// vector<string> inp;
// vector<int> ke[100005];
// int vis[100005];
// int par[100005];

// int checkSame(string s1, string s2) {
//     if(s1.size() != s2.size()) return 2;
//     int cnt = 0;
//     for(int i = 0; i < s1.size(); i++)
//         if(s1[i] != s2[i]) cnt++;
//     return cnt;
// }

// void input(){
//     cin >> n;
//     cin >> s >> t;
//     inp.push_back("");
//     for(int i = 1; i <= n; i ++){
//         vis[i] = 0;
//         par[i] = 0;
//     }
//     for(int i = 1; i <= n; i ++){
//         string x; cin >> x;
//         if(x == s) startt = i;
//         if(x == t) endd = i;
//         inp.push_back(x);
//     }
//     for(int i = 1; i < n; i ++){
//         for(int j = i + 1; j <= n; j ++){
//             if(checkSame(inp[i], inp[j]) <= 1){
//                 ke[i].push_back(j);
//                 ke[j].push_back(i);
//             }
//         }
//     }
// }

// void BFS(int u){
//     queue<int> q;
//     q.push(u);
//     vis[u] = 1;
//     while(!q.empty()){
//         int tmp = q.front(); q.pop();
//         for(int i : ke[tmp]){
//             if(!vis[i]){
//                 vis[i] = 1;
//                 par[i] = tmp;
//                 q.push(i);
//             }
//         }
//     }
// }

// int main(){
    
//     #ifndef ONLINE_JUDGE
//     freopen("nhap.txt", "r", stdin);
//     freopen("xuat.txt", "w", stdout);
//     #endif 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);      

//     int tc; cin >> tc;
//     while(tc --){
//         input();
//         BFS(startt);
//         if(!vis[endd]) cout << 0 << '\n';
//         else{
//             int cnt;
//             if(endd != startt) cnt = 1;
//             else cnt = 0;
//             while(endd != startt){
//                 endd = par[endd];
//                 cnt ++;
//             }
//             cout << cnt << '\n';
//         }
//         inp.clear();
//         for(int i = 1; i <= n; i ++) ke[i].clear();
//     }

//     return 0;
// }