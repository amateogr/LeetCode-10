function candy(ratings: number[]): number {
    const n = ratings.length;
    const c = new Array(n).fill(1);
    for (let i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
    }
    let sum = 0;
    for (let i = n - 1; i >= 0; i--) {
        if (i < n - 1 && ratings[i] > ratings[i + 1]) {
            c[i] = Math.max(c[i], c[i + 1] + 1);
        }
        sum += c[i];
    }
    return sum;
}