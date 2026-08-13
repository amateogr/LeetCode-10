var removeBoxes = function(boxes) {
    const n = boxes.length;
    const memo = Array.from({ length: n }, () => 
        Array.from({ length: n }, () => new Int32Array(n + 1))
    );

    const solve = (l, r, k) => {
        if (l > r) return 0;
        if (memo[l][r][k] !== 0) return memo[l][r][k];

        let right = l;
        let count = k;
        while (right + 1 <= r && boxes[right + 1] === boxes[l]) {
            right++;
            count++;
        }

        let maxPoints = (count + 1) * (count + 1) + solve(right + 1, r, 0);

        for (let i = right + 1; i <= r; i++) {
            if (boxes[i] === boxes[l]) {
                maxPoints = Math.max(maxPoints, solve(right + 1, i - 1, 0) + solve(i, r, count + 1));
            }
        }

        return memo[l][r][k] = maxPoints;
    };

    return solve(0, n - 1, 0);
};