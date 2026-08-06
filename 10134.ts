function canCompleteCircuit(gas: number[], cost: number[]): number {
    let total = 0;
    let curr = 0;
    let start = 0;
    
    for (let i = 0; i < gas.length; i++) {
        let diff = gas[i] - cost[i];
        total += diff;
        curr += diff;
        if (curr < 0) {
            start = i + 1;
            curr = 0;
        }
    }
    
    return total >= 0 ? start : -1;
}