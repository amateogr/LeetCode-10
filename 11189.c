int maxNumberOfBalloons(char * text) {
    int count[26] = {0};
    
    while (*text) {
        count[*text++ - 'a']++;
    }
    
    int b = count['b' - 'a'];
    int a = count['a' - 'a'];
    int l = count['l' - 'a'] >> 1;
    int o = count['o' - 'a'] >> 1;
    int n = count['n' - 'a'];
    
    int min = b;
    if (a < min) min = a;
    if (l < min) min = l;
    if (o < min) min = o;
    if (n < min) min = n;
    
    return min;
}