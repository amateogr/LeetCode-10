class Solution {
    private static final String[] DAYS = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    private static final int[] DAYS_IN_MONTH = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public String dayOfTheWeek(int day, int month, int year) {
        int totalDays = day - 1;
        for (int y = 1971; y < year; y++) {
            totalDays += ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 366 : 365;
        }
        for (int m = 1; m < month; m++) {
            totalDays += DAYS_IN_MONTH[m];
            if (m == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
                totalDays++;
            }
        }
        return DAYS[(totalDays + 5) % 7];
    }
}