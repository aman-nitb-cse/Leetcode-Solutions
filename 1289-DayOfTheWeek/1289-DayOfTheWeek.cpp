// Last updated: 6/25/2026, 11:17:54 PM
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days = 0;
        for (int y = 1971; y <= year; y++) {
            int limit = year == y ? month : 12;
            for (int m = 1; m <= limit; m++) {
                int day_limit = (year == y && m == month) ? day : 31;
                // feb
                for (int d = 1; d <= min(28 + ((y % 4 == 0 && y % 100 != 0) ||
                                               y % 400 == 0),
                                         day_limit) &&
                                m == 2;
                     d++) {
                    days++;
                    // cout << d << ' ' << m << ' ' << y << endl;
                }
                if (m == 2)
                    continue;

                for (int d = 1; d <= min(day_limit, 30 + !(m == 6 || m == 11 ||
                                                           m == 4 || m == 9));
                     d++) {
                    days++;
                    // cout << d << ' ' << m << ' ' << y << endl;
                }
            }
        }

        vector<string> v = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday"};
        // cout << days;
        return v[(days + 4) % 7];
    }
};