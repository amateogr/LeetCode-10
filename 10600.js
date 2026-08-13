const findIntegers = (n) => {
    const f = new Uint32Array(32);
    f[0] = 1;
    f[1] = 2;
    for (let i = 2; i < 32; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    let ans = 0;
    let prevBit = 0;

    for (let i = 30; i >= 0; i--) {
        if ((n & (1 << i)) !== 0) {
            ans += f[i];
            if (prevBit === 1) {
                ans--;
                break;
            }
            prevBit = 1;
        } else {
            prevBit = 0;
        }
    }

    return ans + 1;
};