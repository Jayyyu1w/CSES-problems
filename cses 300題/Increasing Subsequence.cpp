/*LIS*/
/*O(nlgn)才會過*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, len = 1;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1, 0), inc;
    for (int i = 1; i <= n;i++){
        cin >> v[i];
    }
    inc.push_back(v[1]);
    dp[1] = 1;
    for (int i = 2; i <= n;i++){
        if(v[i]>inc.back()){    //大於當前子序列最大
            inc.push_back(v[i]);    //推入，最大長度增加
            dp[i] = ++len;
        }else{      //否則找到當前小於該數的下一位，將其替換為當前之數，dp值為到該位置的長度
            auto it = lower_bound(inc.begin(), inc.end(), v[i]);
            *it = v[i];
            dp[i] = it - v.begin() + 1;
        }
    }
    cout << len << "\n";
}