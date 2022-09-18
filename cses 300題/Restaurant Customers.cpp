/*給客人停留區段，問最多同時有幾個人*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> customer(n);
    vector<int> disc;
    for (int i = 0; i < n;i++){
        cin >> customer[i].first >> customer[i].second;
        disc.push_back(customer[i].first);
        disc.push_back(customer[i].second);
    }
    sort(disc.begin(), disc.end());
    int tot = unique(disc.begin(), disc.end()) - disc.begin();
    int cnt = 0, mxn = -1;
    vector<int> weight(tot + 1, 0);
    for (int i = 0; i < n;i++){
        customer[i].first = lower_bound(disc.begin(), disc.begin() + tot, customer[i].first) - disc.begin();
        customer[i].second = lower_bound(disc.begin(), disc.begin() + tot, customer[i].second) - disc.begin();
        weight[customer[i].first] += 1;
        weight[customer[i].second + 1] += -1;
    }
    for (int i = 0; i <= tot;i++){
        cnt += weight[i];
        mxn = max(mxn, cnt);
    }
    cout << mxn << "\n";
}