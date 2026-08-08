impl Solution {
    pub fn nth_super_ugly_number(n: i32, primes: Vec<i32>) -> i32 {
        let n = n as usize;
        let k = primes.len();
        let mut ugly = Vec::with_capacity(n);
        ugly.push(1);

        let mut pointers = vec![0; k];
        let mut next_multiples: Vec<i64> = primes.iter().map(|&p| p as i64).collect();

        for _ in 1..n {
            let mut min_val = i64::MAX;
            for &m in &next_multiples {
                if m < min_val {
                    min_val = m;
                }
            }
            ugly.push(min_val as i32);

            for i in 0..k {
                if next_multiples[i] == min_val {
                    pointers[i] += 1;
                    next_multiples[i] = primes[i] as i64 * ugly[pointers[i]] as i64;
                }
            }
        }

        ugly[n - 1]
    }
}