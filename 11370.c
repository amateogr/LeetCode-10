char * sortString(char * s) {
    int counts[26] = {0};
    int len = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        counts[s[i] - 'a']++;
        len++;
    }
    
    int pos = 0;
    while (pos < len) {
        for (int i = 0; i < 26; i++) {
            if (counts[i]) {
                s[pos++] = i + 'a';
                counts[i]--;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (counts[i]) {
                s[pos++] = i + 'a';
                counts[i]--;
            }
        }
    }
    
    return s;
}