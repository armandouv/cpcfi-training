//
// Created by armandouv on 11/04/22.
//

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main();

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    for (auto i = 0; i < t; ++i) {
        // if total amount of moves is odd, alice wins
        string s;
        cin >> s;

        auto n = s.size();

        vector<bool> deleted(n, false);

        bool wins{false};

        int zeroes = 0, ones = 0;

        for (auto c: s) {
            if (c == '1') {
                if (zeroes > 0) {
                    zeroes--;
                    wins = !wins;
                } else ones++;
                continue;
            }

            if (ones > 0) {
                ones--;
                wins = !wins;
            } else zeroes++;
        }

        cout << (wins ? "DA" : "NET") << endl;
    }
}