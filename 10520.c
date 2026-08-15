bool detectCapitalUse(char* word) {
    if (!word || !word[0] || !word[1]) return true;
    int secondCap = word[1] <= 'Z';
    if (word[0] > 'Z' && secondCap) return false;
    for (int i = 2; word[i] != '\0'; i++) {
        if ((word[i] <= 'Z') != secondCap) return false;
    }
    return true;
}