impl Solution {
    pub fn is_additive_number(num: String) -> bool {
        let b = num.as_bytes();
        let n = b.len();
        if n < 3 {
            return false;
        }
        for i in 1..=n / 2 {
            if b[0] == b'0' && i > 1 {
                break;
            }
            let n1 = match parse(b, 0, i) {
                Some(v) => v,
                None => continue,
            };
            for j in 1..=n - i {
                if i + j + i.max(j) > n {
                    break;
                }
                if b[i] == b'0' && j > 1 {
                    break;
                }
                let n2 = match parse(b, i, i + j) {
                    Some(v) => v,
                    None => continue,
                };
                if check(n1, n2, b, i + j) {
                    return true;
                }
            }
        }
        false
    }
}

fn parse(b: &[u8], start: usize, end: usize) -> Option<u128> {
    if end - start > 38 || (end - start > 1 && b[start] == b'0') {
        return None;
    }
    let mut acc: u128 = 0;
    for &ch in &b[start..end] {
        if !ch.is_ascii_digit() {
            return None;
        }
        acc = acc.checked_mul(10)?.checked_add((ch - b'0') as u128)?;
    }
    Some(acc)
}

fn check(n1: u128, n2: u128, b: &[u8], mut idx: usize) -> bool {
    if idx == b.len() {
        return true;
    }
    let sum = match n1.checked_add(n2) {
        Some(v) => v,
        None => return false,
    };
    let mut sum_val: u128 = 0;
    if b[idx] == b'0' {
        if sum != 0 {
            return false;
        }
        idx += 1;
    } else {
        while idx < b.len() && b[idx].is_ascii_digit() {
            let digit = (b[idx] - b'0') as u128;
            sum_val = match sum_val.checked_mul(10).and_then(|v| v.checked_add(digit)) {
                Some(v) => v,
                None => return false,
            };
            idx += 1;
            if sum_val >= sum {
                break;
            }
        }
        if sum_val != sum {
            return false;
        }
    }
    check(n2, sum, b, idx)
}