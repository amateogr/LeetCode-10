const smallestNumber = (n, t) => {
    let x = n;
    while ([...String(x)].reduce((a, c) => a * c, 1) % t !== 0) {
        x++;
    }
    return x;
};