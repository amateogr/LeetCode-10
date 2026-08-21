char nextGreatestLetter(char* letters, int lettersSize, char target) {
    if (target >= letters[lettersSize - 1]) return letters[0];
    int l = 0, r = lettersSize - 1;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (letters[m] <= target) l = m + 1;
        else r = m;
    }
    return letters[l];
}