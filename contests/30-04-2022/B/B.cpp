//
// Created by armandouv on 12/04/22.
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
    int n;
    cin >> n;

    vector<int> votes;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        votes.push_back(v);
    }

    int elected = reduce(votes.begin(), votes.end(), votes[0],
                         [](int prev_max, int current) { return max(prev_max, current); });

    if (elected == votes[0]) cout << "S" << endl;
    else cout << "N" << endl;
}