/*使所有棍子等長的最小花費*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int val = v[v.size() / 2];
    ll sum = 0;
    for (int i = 0; i < n;i++){
        sum += abs(v[i] - val);
    }
    cout << sum << "\n";
}