const checkRecord = function(n) {
    const MOD = 1000000007;
    let dp00 = 1, dp01 = 1, dp02 = 0;
    let dp10 = 1, dp11 = 0, dp12 = 0;

    for (let i = 2; i <= n; i++) {
        const next_dp00 = (dp00 + dp01 + dp02) % MOD;
        const next_dp01 = dp00;
        const next_dp02 = dp01;
        const next_dp10 = (dp00 + dp01 + dp02 + dp10 + dp11 + dp12) % MOD;
        const next_dp11 = dp10;
        const next_dp12 = dp11;

        dp00 = next_dp00;
        dp01 = next_dp01;
        dp02 = next_dp02;
        dp10 = next_dp10;
        dp11 = next_dp11;
        dp12 = next_dp12;
    }

    return (dp00 + dp01 + dp02 + dp10 + dp11 + dp12) % MOD;
};