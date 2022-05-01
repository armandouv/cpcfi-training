//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

int main();

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int v, n;
    cin >> v >> n;

    ll total_signs{v * n};

    for (int i = 1; i <= 9; ++i) {
        printf("%.0f ", ceil(i * 10. * total_signs / 100.));
        //cout << ceil(i * 10. * total_signs / 100.) << " ";
    }
}
