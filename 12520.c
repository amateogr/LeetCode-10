int countDigits(int num) {
    int count = 0, temp = num;
    while (temp) {
        if (!(num % (temp % 10))) count++;
        temp /= 10;
    }
    return count;
}