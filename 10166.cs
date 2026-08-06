using System;
using System.Collections.Generic;
using System.Text;

public class Solution {
    public string FractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        StringBuilder sb = new StringBuilder();
        if ((numerator < 0) ^ (denominator < 0)) sb.Append('-');

        long num = Math.Abs((long)numerator);
        long den = Math.Abs((long)denominator);

        sb.Append(num / den);
        long rem = num % den;
        if (rem == 0) return sb.ToString();

        sb.Append('.');
        Dictionary<long, int> map = new Dictionary<long, int>();

        while (rem != 0) {
            if (map.TryGetValue(rem, out int index)) {
                sb.Insert(index, '(');
                sb.Append(')');
                break;
            }

            map[rem] = sb.Length;
            rem *= 10;
            sb.Append(rem / den);
            rem %= den;
        }

        return sb.ToString();
    }
}