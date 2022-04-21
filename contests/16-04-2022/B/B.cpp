//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * We'll calculate the amount of available elements for the left and right halves as follows:
 * elements_greater_than_a = (n - a);
 * elements_greater_than_b = (n - b);
 * half_size = n / 2;
 *
 *  We initially consider all numbers greater than or equal to a as available for the left half. Similarly, we consider
 *  all elements less than or equal to b as available for the right half.
 *  available_for_left_half = greater_than_a + 1;
 *  available_for_right_half = b;
 *
 * If a < b, both arrays have certain overlap between their available elements, and we need to take these overlapping
 * elements into account because they will not be available for both halves:
 *
 * So, if (a < b):
 * - Don't consider b as a candidate element for the left half:  available_for_left_half--
 * - We'll first add all elements > b to the left half, which will not affect the number of available elements for the
 * right half. Since we need to add (half_size - greater_than_b) elements >= a and < b to the left half, we won't
 * consider those as available for the right half. If the number of elements greater than b is equal
 * to half_size, there will be no solution, but we will still decrease the available elements by one to make sure we
 * don't consider a as an available element for the right half.
 * available_for_right_half -= max(1, half_size - greater_than_b);
 * It's worth noting that the only case in which a > b is when both are at the middle of n.
 *
 * If the number of available elements for both halves is greater than or equal to half_size, we can construct the
 * permutation as follows:
 * 1. Add all elements > b to the left half
 * 2. Add all elements > a and <= b to the left half. When it is full, add all remaining elements to the right half.
 * 3. Add all elements < a to the right half.
 */


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
        int n, a, b;
        cin >> n >> a >> b;

        auto half_size = n / 2;
        auto greater_than_a = (n - a);
        auto greater_than_b = (n - b);

        auto available_for_left_half = greater_than_a + 1;
        auto available_for_right_half = b;

        if (a < b) {
            available_for_left_half--;
            available_for_right_half -= max(1, half_size - greater_than_b);
        }

        if (available_for_left_half < half_size || available_for_right_half < half_size) {
            cout << -1 << endl;
            continue;
        }

        vector<int> permutation;

        // Add all elements > b to the left half;
        for (int j = b + 1; j <= n; j++)
            permutation.push_back(j);

        // Add all elements > a to the left half, as well as elements > a and <= b to the right half.
        for (int j = a; j <= b; j++)
            permutation.push_back(j);

        // Add all elements < a to the right half.
        for (int j = 1; j < a; j++)
            permutation.push_back(j);


        for (int j = 0; j < n - 1; j++) {
            cout << permutation[j] << ' ';
        }

        cout << permutation[n - 1] << endl;
    }
}