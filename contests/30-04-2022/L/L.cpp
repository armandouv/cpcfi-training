//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

int main();

void solve();

ll count_ones(ll);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

void solve() {
    ll n;
    cin >> n;

    printf("%.0f", pow(2, count_ones(n)));

    //cout << pow(2, count_ones(n)) << endl;
}

ll count_ones(ll n) {
    ll count{0};

    while (n != 0) {
        n = n & (n - 1);
        count++;
    }

    return count;
}