const findKthNumber = (m, n, k) => {
    let low = 1;
    let high = m * n;

    while (low < high) {
        const mid = low + ((high - low) >> 1);
        let count = 0;
        
        for (let i = 1; i <= m; i++) {
            const maxValInRow = (mid / i) | 0;
            if (maxValInRow === 0) break;
            count += maxValInRow < n ? maxValInRow : n;
        }

        if (count >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
};