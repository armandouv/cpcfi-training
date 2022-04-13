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

    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        double cost_per_unit{(double) c / (double) b};

        if (a < c) cout << 1 << " ";
        else cout << -1 << " ";

        if (cost_per_unit >= a) cout << -1 << endl;
        else cout << b << endl;
    }
}