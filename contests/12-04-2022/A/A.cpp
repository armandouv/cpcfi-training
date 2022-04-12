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

    for (auto i = 0; i < t; i++) {
        ull n, s;
        cin >> n >> s;

        auto squared{n * n};
        ull times{s / squared};

        cout << times << endl;
    }
}