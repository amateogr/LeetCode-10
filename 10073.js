function setZeroes(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    let col0 = 1;
    for (let i = 0; i < m; i++) {
        if (matrix[i][0] === 0) col0 = 0;
        for (let j = 1; j < n; j++) {
            if (matrix[i][j] === 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 1; j--) {
            if (matrix[i][0] === 0 || matrix[0][j] === 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0 === 0) matrix[i][0] = 0;
    }
}