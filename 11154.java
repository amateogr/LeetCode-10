class Solution {
    private static final int[] DAYS = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    public int dayOfYear(String date) {
        int year = (date.charAt(0) - '0') * 1000 + (date.charAt(1) - '0') * 100 + (date.charAt(2) - '0') * 10 + (date.charAt(3) - '0');
        int month = (date.charAt(5) - '0') * 10 + (date.charAt(6) - '0');
        int day = (date.charAt(8) - '0') * 10 + (date.charAt(9) - '0');
        
        int ans = DAYS[month - 1] + day;
        if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            ans++;
        }
        
        return ans;
    }
}