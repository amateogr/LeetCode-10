const searchMatrix = (matrix, target) => {
    const m = matrix.length, n = matrix[0].length;
    let left = 0, right = m * n - 1;
    while (left <= right) {
        const mid = (left + right) >> 1;
        const val = matrix[(mid / n) | 0][mid % n];
        if (val === target) return true;
        if (val < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
};