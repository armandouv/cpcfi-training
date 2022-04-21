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
    int t;
    cin >> t;

    for (auto i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;

        // The Manhattan distance from A (the origin) to B (x, y) is x + y.
        int manhattan_distance{x + y};

        // If the Manhattan distance is odd, we will not be able to find a middle point.
        if (manhattan_distance % 2 != 0) {
            cout << -1 << ' ' << -1 << endl;
            continue;
        }

        // To find C, go half steps in direction to the farthest coordinate in B. In this way, the number of remaining
        // steps to B from C will be equal, and it will be on the shortest possible path to B, according to the
        // Manhattan distance.
        if (x > y) cout << manhattan_distance / 2 << ' ' << 0 << endl;
        else cout << 0 << ' ' << manhattan_distance / 2 << endl;
    }
}
