//找1~n中缺失的一個數字
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n - 1;i++){
        cin >> num;
        v[num] = 1;
    }
    for (int i = 1; i <= n;i++){
        if(!v[i]){
            cout << i << "\n";
            break;
        }
    }
}