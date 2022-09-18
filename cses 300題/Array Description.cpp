/*一陣列有n個元素，每個元素值均在1~m之間，當中有未知元素表示為0，問總共有幾組子陣列每個相鄰元素均相差1*/
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(m + 2, vector<ll>(n + 1, 0));
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    //如果一開始為0代表全部均可被轉移，為其他數字則只有該數字能被轉移
    if (v[1] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[i][1] = 1;
        }
    }
    else {
        dp[v[1]][1] = 1;
    }
    //由由當前數字的+-1與0將前一位轉移過來，當前數字為0就全部都轉移
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1]) % MOD;
            }
        }
        else {
            dp[v[i]][i] = (dp[v[i] - 1][i - 1] + dp[v[i]][i - 1] + dp[v[i] + 1][i - 1]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    cout << ans << "\n";
}