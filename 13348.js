const MD = Array.from({length: 60}, () => new Int32Array(40).fill(-1));

function getMD(a, b) {
    if (a <= 0 && b <= 0) return 0;
    if (MD[a][b] !== -1) return MD[a][b];
    
    let res = 1e9;
    if (a > 0) res = Math.min(res, 1 + getMD(Math.max(0, a - 1), b));
    if (b > 0) res = Math.min(res, 1 + getMD(a, Math.max(0, b - 1)));
    if (a > 0) res = Math.min(res, 1 + getMD(Math.max(0, a - 2), b));
    if (a > 0 || b > 0) res = Math.min(res, 1 + getMD(Math.max(0, a - 1), Math.max(0, b - 1)));
    if (a > 0) res = Math.min(res, 1 + getMD(Math.max(0, a - 3), b));
    if (b > 0) res = Math.min(res, 1 + getMD(a, Math.max(0, b - 2)));
    
    return MD[a][b] = res;
}

var smallestNumber = function(num, t) {
    let a = 0, b = 0, c = 0, d = 0;
    let temp = BigInt(t);
    while (temp % 2n === 0n) { a++; temp /= 2n; }
    while (temp % 3n === 0n) { b++; temp /= 3n; }
    while (temp % 5n === 0n) { c++; temp /= 5n; }
    while (temp % 7n === 0n) { d++; temp /= 7n; }
    
    if (temp > 1n) return "-1";

    let req = c + d + getMD(a, b);
    let N = num.length;
    
    if (req > N) {
        N = req;
        num = "1".repeat(N);
    }

    let choice = new Int32Array(N);
    let state_a = new Int32Array(N + 1);
    let state_b = new Int32Array(N + 1);
    let state_c = new Int32Array(N + 1);
    let state_d = new Int32Array(N + 1);
    let state_g = new Uint8Array(N + 1);
    
    state_a[0] = a; 
    state_b[0] = b; 
    state_c[0] = c; 
    state_d[0] = d; 
    state_g[0] = 0;
    
    let i = 0;
    while (i < N) {
        let current_g = state_g[i];
        let min_D = choice[i] + 1;
        let val = num.charCodeAt(i) - 48;
        let base_min = current_g ? 1 : (val > 1 ? val : 1);
        
        if (min_D < base_min) min_D = base_min;
        
        let found = false;
        for (let D = min_D; D <= 9; D++) {
            let na = state_a[i], nb = state_b[i], nc = state_c[i], nd = state_d[i];
            
            if (D === 2) na = na > 0 ? na - 1 : 0;
            else if (D === 3) nb = nb > 0 ? nb - 1 : 0;
            else if (D === 4) na = na > 1 ? na - 2 : 0;
            else if (D === 5) nc = nc > 0 ? nc - 1 : 0;
            else if (D === 6) { na = na > 0 ? na - 1 : 0; nb = nb > 0 ? nb - 1 : 0; }
            else if (D === 7) nd = nd > 0 ? nd - 1 : 0;
            else if (D === 8) na = na > 2 ? na - 3 : 0;
            else if (D === 9) nb = nb > 1 ? nb - 2 : 0;
            
            if (nc + nd + getMD(na, nb) <= N - 1 - i) {
                choice[i] = D;
                state_a[i+1] = na;
                state_b[i+1] = nb;
                state_c[i+1] = nc;
                state_d[i+1] = nd;
                state_g[i+1] = current_g || (D > val) ? 1 : 0;
                found = true;
                break;
            }
        }
        
        if (found) {
            i++;
            if (i < N) choice[i] = 0;
        } else {
            choice[i] = 0;
            i--;
            if (i < 0) {
                N++;
                num = "1".repeat(N);
                choice = new Int32Array(N);
                state_a = new Int32Array(N + 1);
                state_b = new Int32Array(N + 1);
                state_c = new Int32Array(N + 1);
                state_d = new Int32Array(N + 1);
                state_g = new Uint8Array(N + 1);
                
                state_a[0] = a; 
                state_b[0] = b; 
                state_c[0] = c; 
                state_d[0] = d; 
                state_g[0] = 0;
                i = 0;
            }
        }
    }
    
    return choice.join('');
};