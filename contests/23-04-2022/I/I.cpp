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
 * We get the number of days to wait for a bank operation for each deposit, and obtain the minimum of them.
 *
 * To get the number of days to wait for each deposit creation, we need to know their earliest renewal dates from today.
 * To do this, we first get the weekday in which the deposit was created. Afterwards, we start at the creation date and
 * advance renewal cycles as needed, until we get the latest one after the current day. We will not be able to advance
 * 30 days in each cycle, instead, the following rules apply:
 * - Tue -> Thu (30 days)
 * - Thu -> Mon (32 days)
 * - Mon -> Wed (30 days)
 * - Wed -> Fri (30 days)
 * - Fri -> Mon (31 days)
 * Note that there is a "cycle" if we are on a Mon, Wed, or Fri. Thus, if it's possible, we can skip larger cycles of 91
 * days and end up at the same start weekday.
 */

void solve() {
    vector<string> weekdays{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    string current_day;
    cin >> current_day;

    int current_day_index = find(weekdays.begin(), weekdays.end(), current_day) - weekdays.begin();

    int n;
    cin >> n;

    int min_days{32};

    for (auto i = 0; i < n; i++) {
        int since_creation;
        cin >> since_creation;

        // Deposit was created today
        if (since_creation == 0) {
            int remaining_days{30};
            if (current_day == "Thu") remaining_days += 2;
            else if (current_day == "Fri") remaining_days++;
            min_days = min(min_days, remaining_days);
            continue;
        }

        // Get the weekday in which the deposit was created
        int since_creation_weekday{since_creation % 7};
        int creation_weekday_index{current_day_index};

        while (since_creation_weekday != 0) {
            creation_weekday_index = creation_weekday_index == 0 ? 6 : creation_weekday_index - 1;
            since_creation_weekday--;
        }

        string creation_weekday = weekdays[creation_weekday_index];

        // Get the number of remaining days for the next renewal, considering the creation weekday.
        int remaining_days{since_creation};

        // If it was created on a Tuesday, the next renewal will be 30 days after, on a Thursday.
        if (remaining_days > 0 && creation_weekday == "Tue") {
            remaining_days -= 30;
            creation_weekday = "Thu";
        }

        // If it was created on a Thurday, the next renewal will be 32 days after, on a Monday.
        if (remaining_days > 0 && creation_weekday == "Thu") {
            remaining_days -= 32;
            creation_weekday = "Mon";
        }

        // If it was created on a Mon, Wed, or Fri, renewals will cycle as follows:
        // Mon -> Wed (30 days), Wed -> Fri (30 days), Fri -> Mon (31 days)
        if (remaining_days > 0) {
            // Advance full cycles as needed (91 days after we'll be in the same weekday)
            remaining_days = remaining_days % 91;

            // Get the remaining days for the next renewal
            while (remaining_days > 0) {
                remaining_days -= 30;

                if (creation_weekday == "Mon") creation_weekday = "Wed";
                else if (creation_weekday == "Wed") creation_weekday = "Fri";
                else {
                    remaining_days--;
                    creation_weekday = "Mon";
                }
            }
        }

        // We can renew today, this is the best we can do.
        if (remaining_days == 0) {
            cout << 0 << endl;
            return;
        }

        min_days = min(min_days, abs(remaining_days));

    }

    cout << min_days << endl;
}