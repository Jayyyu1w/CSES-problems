/*有1~n的數字，每次只能除去遞增的數字，最少要幾回合才能除完*/
#include<bits/stdc++.h>
using namespace std;

struct ids {
    int val, idx;
    ids() {}
    ids(int _val, int _idx) {
        val = _val, idx = _idx;
    }
    friend bool operator<(const ids& a, const ids& b) {
        return a.val < b.val;
    }
};
int main() {
    int n, num;
    cin >> n;
    vector<ids> v(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        v[i] = ids(num, i + 1);
    }
    sort(v.begin(), v.end());
    int turn = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].idx < v[i - 1].idx) {
            turn++;
        }
    }
    cout << turn << "\n";
}