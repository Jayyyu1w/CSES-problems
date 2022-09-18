/*問最長不重複序列長度*/
/*two pointers 雙指針*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    map<int, int> mp;
    int l = 0, r = 0, sz = 0, mxsz = 0;
    while (r < n){
        if (mp.find(v[r]) == mp.end() || mp[v[r]] < 1){
            mp[v[r]]++;
            sz++;
            mxsz = max(mxsz, sz);
            r++;
        }else{
            while (v[l] != v[r]){
                mp[v[l]]--;
                l++, sz--;
            }
            mp[v[l]]--;
            l++, sz--;
        }
    }
    cout << mxsz << "\n";
}