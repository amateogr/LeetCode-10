use std::collections::HashSet;

impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        let mut dict: HashSet<Vec<u8>> = word_list.into_iter().map(|w| w.into_bytes()).collect();
        let end_word_bytes = end_word.into_bytes();
        
        if !dict.contains(&end_word_bytes) {
            return 0;
        }
        dict.remove(&end_word_bytes);

        let mut front = HashSet::new();
        let mut back = HashSet::new();
        
        front.insert(begin_word.into_bytes());
        back.insert(end_word_bytes);
        
        let mut step = 1;
        
        while !front.is_empty() && !back.is_empty() {
            if front.len() > back.len() {
                std::mem::swap(&mut front, &mut back);
            }
            
            let mut next_front = HashSet::new();
            
            for mut bytes in front {
                for i in 0..bytes.len() {
                    let old_byte = bytes[i];
                    for b in b'a'..=b'z' {
                        if b == old_byte { 
                            continue; 
                        }
                        bytes[i] = b;
                        
                        if back.contains(&bytes) {
                            return step + 1;
                        }
                        
                        if dict.remove(&bytes) {
                            next_front.insert(bytes.clone());
                        }
                    }
                    bytes[i] = old_byte;
                }
            }
            front = next_front;
            step += 1;
        }
        
        0
    }
}