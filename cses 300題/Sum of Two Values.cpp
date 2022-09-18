/*在array裡面挑兩個數，問能不能組合出目標數，可以則印出兩數，不行則印IMPOSSIBLE*/
#include<bits/stdc++.h>
using namespace std;

struct ids {
    int id, val;
    ids() {}
    ids(int _id, int _val) {
        id = _id, val = _val;
    }
    friend bool operator<(const ids& a, const ids& b) {
        return a.val < b.val;
    }
    friend bool operator<(const ids& a, const int i) {
        return a.val < i;
    }
};
int main() {
    int n, x, a;
    cin >> n >> x;
    vector<ids> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(ids(i, a));
    }
    sort(v.begin(), v.end());
    bool fail = true;
    int num1, num2;
    for (int i = 0; i < n - 1; i++) {
        auto pos = lower_bound(v.begin() + i + 1, v.end(), x - v[i].val);
        if (pos->val == (x - v[i].val)) {
            fail = false;
            num1 = v[i].id + 1, num2 = pos->id + 1;
            break;
        }
    }
    if (num1 > num2)
        swap(num1, num2);
    fail ? cout << "IMPOSSIBLE\n" : cout << num1 << " " << num2 << "\n";
}