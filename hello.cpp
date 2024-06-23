#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, s;
int a[105][105];
void EULER()
{
    vector<int> CE;
    stack<int> st;
    st.push(s);
    while (st.size())
    {
        int u = st.top();
        st.pop();
        bool disjointed = true;
        for (int v = 1; v <= n; v++)
            if (a[u][v] == 1)
            {
                disjointed = false;
                st.push(v);
                a[u][v] = 0;
                break;
        }
        if (disjointed) CE.push_back(u);
    }
    for(int i = CE.size() - 1; i >= 0; i--)
        cout << CE[i] << " ";
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    if(t == 1){
        cin >> n;
        int bacc[n + 1], bact[n + 1];
        for(int i = 1; i <= n; i ++) bact[i] = 0;
        for(int i = 1; i <= n; i ++){
            bacc[i] = 0;
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
                if(a[i][j]){
                    bacc[i] ++;
                    bact[j] ++;
                }
            }
        }
        int cnt = 0;
        bool check = true;
        for(int i = 1; i <= n; i ++){
            // cout << bacc[i] << ' ' << bact[i] << '\n';
            if(bacc[i] == bact[i]) continue;
            else{
                if(abs(bacc[i] - bact[i]) == 1) cnt ++;
                else{
                    check = false;
                    break;
                }
            }
            
        }
        // cout << cnt;
        if(check && cnt > 2) check = false;
        if(!check) cout << 0 << '\n';
        if(check && cnt == 2) cout << 2 << '\n';
        if(check && cnt == 0) cout << 1 << '\n';
    }
    if(t == 2){
        cin >> n >> s;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cin >> a[i][j];
        }
        EULER();
    }

    return 0;
}