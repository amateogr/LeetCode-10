use std::collections::{HashMap, HashSet, VecDeque};

impl Solution {
    pub fn find_ladders(begin_word: String, end_word: String, word_list: Vec<String>) -> Vec<Vec<String>> {
        let mut dict: HashSet<String> = word_list.into_iter().collect();
        if !dict.contains(&end_word) {
            return vec![];
        }

        dict.remove(&begin_word);
        dict.remove(&end_word);

        let mut parents: HashMap<String, Vec<String>> = HashMap::new();
        let mut queue = VecDeque::new();
        queue.push_back(begin_word.clone());

        let mut found = false;

        while !queue.is_empty() && !found {
            let size = queue.len();
            let mut visited_this_level = HashSet::new();

            for _ in 0..size {
                let word = queue.pop_front().unwrap();
                let chars: Vec<char> = word.chars().collect();

                for i in 0..chars.len() {
                    for c in b'a'..=b'z' {
                        let ch = c as char;
                        if ch == chars[i] {
                            continue;
                        }
                        let mut next_word_chars = chars.clone();
                        next_word_chars[i] = ch;
                        let next_word: String = next_word_chars.into_iter().collect();

                        if next_word == end_word {
                            found = true;
                            parents.entry(next_word.clone()).or_default().push(word.clone());
                            visited_this_level.insert(next_word);
                        } else if dict.contains(&next_word) {
                            parents.entry(next_word.clone()).or_default().push(word.clone());
                            if !visited_this_level.contains(&next_word) {
                                visited_this_level.insert(next_word.clone());
                                queue.push_back(next_word);
                            }
                        }
                    }
                }
            }

            for w in &visited_this_level {
                dict.remove(w);
            }
        }

        let mut res = vec![];
        if !found {
            return res;
        }

        let mut path = vec![end_word.clone()];
        Self::dfs(&end_word, &begin_word, &parents, &mut path, &mut res);
        res
    }

    fn dfs(
        current: &String,
        begin_word: &String,
        parents: &HashMap<String, Vec<String>>,
        path: &mut Vec<String>,
        res: &mut Vec<Vec<String>>,
    ) {
        if current == begin_word {
            let mut rev = path.clone();
            rev.reverse();
            res.push(rev);
            return;
        }

        if let Some(p_list) = parents.get(current) {
            for p in p_list {
                path.push(p.clone());
                Self::dfs(p, begin_word, parents, path, res);
                path.pop();
            }
        }
    }
}