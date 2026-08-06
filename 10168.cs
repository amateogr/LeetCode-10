public class Solution {
    public string ConvertToTitle(int columnNumber) {
        Span<char> buffer = stackalloc char[7];
        int i = 7;
        while (columnNumber > 0) {
            columnNumber--;
            buffer[--i] = (char)('A' + (columnNumber % 26));
            columnNumber /= 26;
        }
        return new string(buffer.Slice(i, 7 - i));
    }
}