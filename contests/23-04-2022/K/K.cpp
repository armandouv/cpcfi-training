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

/*
 * Maintain a set of the characters we've seen as the first letter in any word. For each char in every word, check if
 * that char exists in the built set. If all characters in a word are in the set, this means we can form an acronym with
 * that word.
 */

void solve() {
    int n;
    cin >> n;
    vector<bool> seen_first_letter(26, false);
    vector<string> words(n);

    for (auto i = 0; i < n; i++) {
        string s;
        cin >> s;
        seen_first_letter[s[0] - 'A'] = true;
        words[i] = s;
    }

    for (auto &s: words) {
        bool exists{true};
        for (auto c: s) {
            if (!seen_first_letter[c - 'A']) {
                exists = false;
                break;
            }
        }

        if (exists) {
            cout << 'Y' << endl;
            return;
        }
    }

    cout << 'N' << endl;
}