/*給一字串，問可不可以成為回文，可以的話再印出排出的回文*/
#include<bits/stdc++.h>
using namespace std;

struct alphabet {
    char ch;
    int cnt;
    alphabet() {}
    alphabet(char _ch, int _cnt) {
        ch = _ch, cnt = _cnt;
    }
    friend bool operator<(const alphabet& a, const alphabet& b) {
        if (a.cnt & 1)
            return false;
        if (b.cnt & 1)
            return true;
        return a.cnt > b.cnt;
    }
};
int main() {
    string s;
    cin >> s;
    vector<int> count(26);
    vector<alphabet> exist;
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i]) {
            exist.push_back(alphabet(i + 'A', count[i]));
            if (count[i] & 1)
                odd++;
        }
    }
    if (odd > 1)
        cout << "NO SOLUTION\n";
    else {
        sort(exist.begin(), exist.end());
        string ans;
        for (int i = 0; i < exist.size() - 1; i++) {
            for (int j = 0; j < (exist[i].cnt >> 1); j++) {
                ans += exist[i].ch;
            }
            exist[i].cnt >>= 1;
        }
        for (int i = 0; i < exist[exist.size() - 1].cnt; i++) {
            ans += exist[exist.size() - 1].ch;
        }
        for (int i = exist.size() - 2; i >= 0; i--) {
            for (int j = 0; j < exist[i].cnt; j++) {
                ans += exist[i].ch;
            }
        }
        cout << ans << "\n";
    }
}