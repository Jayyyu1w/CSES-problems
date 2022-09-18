/*給每張票的票價(售完為止)跟每個人願意出的最高價錢 問他們能拿到多少錢的票 如果不行則輸出-1*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, cost;
    cin >> n >> m;
    map<int, int> ticket;
    for (int i = 0; i < n; i++) {
        cin >> cost;
        ticket[cost]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> cost;
        auto it = ticket.lower_bound(cost+1);
        if(it!=ticket.begin()){
            it--;
            cout << it->first << "\n";
            it->second--;
            if(it->second==0)
                ticket.erase(it);
        }else
            cout << "-1\n";
    }
}