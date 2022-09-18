/*給書的價格跟頁數，問在指定的預算下所能達到的最大頁數*/
// 01背包
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 0), cost(n, 0), value(n, 0);
    for (int i = 0; i < n;i++){
        cin >> cost[i];
    }
    for (int i = 0; i < n;i++){
        cin >> value[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = x; j >= cost[i];j--){
            dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
        }
    }
    cout << dp[x] << "\n";
}