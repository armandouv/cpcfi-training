//
// Created by armandouv on 21/04/22.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
 * If x > k^2 (all possible printed emojis), we can safely print all 2k - 1 messages.
 *
 *
 * Else:
 *
 * Consider sum(n) the sum of all positive integers up to n. The formula to calculate this number is n * (n + 1) / 2.
 *
 * If x <= arr[k], perform a binary search on the numbers from 1 to k to find the minimum number n such that
 * sum(n) >= x. Namely, search for x in the sums, and if it is not found, return n such that sum(n) is the smallest sum
 * greater than x. This number will be the number of messages to print, and we can see the problem as finding the
 * minimum number of messages that exceed the allowed number of emojis.
 *
 * Else, we can safely print all k messages from the first half of the triangle, but now we need to find the appropriate
 * number of messages to print from the second half, starting with the message with k - 1 emojis. Conversely, we can
 * also think of the problem as trying to find the appropriate number of messages to avoid printing from the second
 * half, starting with the message with 1 emoji (the last one). Using the latter approach, we can calculate the correct
 * number of messages to avoid printing as follows:
 * - Assume y = (k^2 - sum(n)) is the total number of emojis that will be printed if we avoid printing the last n
 * messages.
 * - Find the minimum number n from 1 to k - 1 such that y >= x.
 *
 * In the previous case, we could use standard binary search because the sums were directly proportional to the numbers.
 * However, we now have that y is an inversely proportional function. As a consequence, if we want to perform a
 * binary search, we need to go in the opposite direction to find the desired value.
 * Once we find n, the result will be 2k - 1 - n.
 */

int main();

void solve();

ll get_sum(ll);

ll sums_binary_search(ll, ll, ll, const function<ll(ll)> &, bool = false);

int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    for (auto i = 0; i < t; i++) {
        ll k, x;
        cin >> k >> x;

        if (x > k * k) {
            cout << 2 * k - 1 << endl;
            continue;
        }

        ll messages;
        if (x <= get_sum(k))
            messages = sums_binary_search(1, k, x, get_sum);
        else
            messages = 2 * k - 1 - sums_binary_search(1, k - 1, x,
                                                      [=](ll n) { return k * k - get_sum(n); },
                                                      true);

        cout << messages << endl;
    }
}


ll get_sum(ll n) {
    return n * (n + 1) / 2;
}


/*
 * Returns the minimum number n such that get_value(n) is >= to x. If reverse = true, it is assumed that get_value is an
 * inversely proportional function, and thus search is performed in a reverse fashion.
 */
ll sums_binary_search(ll start, ll end, ll x, const function<ll(ll)> &get_value, bool reverse) {
    if (start > end) return reverse ? end : start;

    ll middle{(start + end) / 2};
    ll middle_val{get_value(middle)};
    if (middle_val == x) return middle;

    if (reverse) {
        if (middle_val < x)
            return sums_binary_search(start, middle - 1, x, get_value, reverse);
        return sums_binary_search(middle + 1, end, x, get_value, reverse);
    }

    if (middle_val > x)
        return sums_binary_search(start, middle - 1, x, get_value, reverse);
    return sums_binary_search(middle + 1, end, x, get_value, reverse);
}