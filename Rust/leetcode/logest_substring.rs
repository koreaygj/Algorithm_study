use std::cmp;
use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map: HashMap<char, usize> = HashMap::new();
        let mut left = 0;
        let mut max_length = 0;

        for (right, current_char) in s.chars().enumerate() {
            if let Some(&last_seen_index) = map.get(&current_char) {
                if last_seen_index >= left {
                    left = last_seen_index + 1;
                }
            }

            map.insert(current_char, right);
            max_length = cmp::max(max_length, right - left + 1);
        }

        max_length as i32
    }
}
