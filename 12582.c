int passThePillow(int n, int time) {
    int chunk = time / (n - 1);
    int rem = time % (n - 1);
    return (chunk & 1) ? (n - rem) : (1 + rem);
}