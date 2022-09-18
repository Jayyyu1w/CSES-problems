//3n+1 problem
#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> v;
void solve(int n){
    v.push_back(n);
    if(n==1)
        return;
    if(n&1){
        solve(3 * n + 1);
    }else{
        solve(n / 2);
    }
}
signed main(){
    int n;
    cin >> n;
    solve(n);
    for (int i = 0; i < v.size();i++){
        if(i!=0)
            cout << " ";
        cout << v[i];
    }
    cout << "\n";
}