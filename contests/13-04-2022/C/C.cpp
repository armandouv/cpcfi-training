//
// Created by armandouv on 12/04/22.
//

/* Second attempt (didn't work) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main();

void solve();


int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    /* Current balance = 0
     * for i = 0 to n
     * if current char = -:
     * current balance--
     * else current balance++
     * if current balance < 0
     * res += i + 1
     * current balance = 0
     *
     * */

    for (auto i = 0; i < t; i++) {
        string s;
        cin >> s;
        auto n{s.size()};

        ll balance{0}, res{static_cast<int>(n)};
        for (ll j = 0; j < n; j++) {
            if (s[j] == '-') balance--;
            else balance++;

            if (balance < 0) {
                res += j + 1;
                balance = 0;
            }
        }

        cout << res << endl;
    }
}