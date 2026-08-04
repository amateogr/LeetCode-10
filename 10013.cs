public class Solution {
    public int RomanToInt(string s) {
        int total = 0;
        int prevValue = 0;

        for (int i = s.Length - 1; i >= 0; i--) {
            int currentValue = s[i] switch {
                'I' => 1,
                'V' => 5,
                'X' => 10,
                'L' => 50,
                'C' => 100,
                'D' => 500,
                'M' => 1000,
                _ => 0
            };

            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }

            prevValue = currentValue;
        }

        return total;
    }
}