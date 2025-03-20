use std::cmp;
use std::io::{stdin, stdout, Write};

fn main() {
    let mut bf = String::new();
    let mut st = vec![];
    let mut max_length = 0;
    for _ in 0..5 {
        bf.clear();
        stdin().read_line(&mut bf).unwrap();
        let tmp = bf.trim().to_string();
        max_length = cmp::max(tmp.len(), max_length);
        st.push(tmp);
    }
    for i in 0..max_length {
        for j in 0..5 {
            if let Some(c) = st[j].chars().nth(i) {
                write!(stdout(), "{}", c).unwrap();
            }
        }
    }
}
