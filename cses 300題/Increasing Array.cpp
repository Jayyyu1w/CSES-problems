//最少要加多少能成為遞增序列
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int sum = 0;
    for (int i = 1; i < n;i++){
        if(v[i]<v[i-1]){
            sum += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << sum << "\n";
}