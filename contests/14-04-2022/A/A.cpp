//
// Created by armandouv on 11/04/22.
//

#include <bits/stdc++.h>

using namespace std;

int main();

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int result{0};
        for (int j = 0; j < n - 2; j++) {
            if (s[j] == '1') continue;

            if (s[j + 1] == '0') result += 2;
            else if (s[j + 2] == '0') result += 1;
        }

        if (s[n - 2] == '0' && s[n - 1] == '0') result += 2;

        cout << result << endl;
    }
}