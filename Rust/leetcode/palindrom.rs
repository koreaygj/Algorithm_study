use std::cmp;
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let n = s.len();
        if n <= 1 {
            return s;
        }

        let b = s.as_bytes();
        let mut dp = vec![vec![false; n]; n];

        let mut start = 0;
        let mut max_len = 1;

        for i in 0..n {
            dp[i][i] = true;
        }

        for i in 0..n - 1 {
            if b[i] == b[i + 1] {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
        }

        for len in 3..=n {
            for i in 0..n - len + 1 {
                let j = i + len - 1;

                if b[i] == b[j] && dp[i + 1][j - 1] {
                    dp[i][j] = true;
                    if len > max_len {
                        start = i;
                        max_len = len;
                    }
                }
            }
        }

        s[start..start + max_len].to_string()
    }
}
