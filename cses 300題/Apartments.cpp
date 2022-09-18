/*在差距不能超過k的情況下兩陣列能匹配幾個*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> app(n), apar(m);
    for (int i = 0; i < n;i++){
        cin >> app[i];
    }
    for (int i = 0; i < m;i++){
        cin >> apar[i];
    }
    sort(app.begin(), app.end(), greater<int>());
    sort(apar.begin(), apar.end(), greater<int>());
    int ans = 0;
    while(app.size()&&apar.size()){
        if(abs(app.back()-apar.back())<=k){
            app.pop_back(), apar.pop_back();
            ans++;
        }else{
            if(app.back()>apar.back())
                apar.pop_back();
            else
                app.pop_back();
        }
    }
    cout << ans << "\n";
}