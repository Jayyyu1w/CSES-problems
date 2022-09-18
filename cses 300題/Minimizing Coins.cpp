/*給目標值及錢幣幣值，問最少所需硬幣數量，硬幣可挑無限多次*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 100000000), coin(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
    if (coin.front() > x) {
        cout << "-1\n";
    }
    else {
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= x; j++) {
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            }
        }
        if(dp[x]==100000000)
            cout << "-1\n";
        else
            cout << dp[x] << "\n";
    }
}