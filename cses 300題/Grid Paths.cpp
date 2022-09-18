/*給一張只含.跟*的圖，*不能走，問從左上到右下只能往右跟下，有幾種方法*/
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<vector<bool>> graph(n, vector<bool>(n));
    for (int i = 0; i < n;i++){
        cin >> s;
        for (int j = 0; j < s.length();j++){
            if(s[j]=='.')
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
        }
    }
    if(graph[0][0]){
        cout << "0\n";
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if((i==0&&j==0)||graph[i][j])
                continue;
            if(i==0)
                dp[i][j] = dp[i][j - 1];
            else if(j==0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}