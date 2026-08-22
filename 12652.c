int sumOfMultiples(int n) {
    long long m3 = n / 3, m5 = n / 5, m7 = n / 7;
    long long m15 = n / 15, m21 = n / 21, m35 = n / 35, m105 = n / 105;
    return 3 * m3 * (m3 + 1) / 2 + 5 * m5 * (m5 + 1) / 2 + 7 * m7 * (m7 + 1) / 2 
         - 15 * m15 * (m15 + 1) / 2 - 21 * m21 * (m21 + 1) / 2 - 35 * m35 * (m35 + 1) / 2 
         + 105 * m105 * (m105 + 1) / 2;
}