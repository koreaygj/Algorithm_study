use std::io::{stdin, stdout, Write};
fn main() {
    let mut bf = String::new();
    loop {
        bf.clear();
        stdin().read_line(&mut bf).unwrap();
        let n = bf.trim().to_string();
        if n == "0" {
            break;
        }
        let num_len = n.len();
        let mut flag = true;
        for i in 0..num_len / 2 {
            if Some(n.chars().nth(i)) != Some(n.chars().nth(num_len - 1 - i)) {
                flag = false;
                writeln!(stdout(), "no").unwrap();
                break;
            }
        }
        if flag {
            writeln!(stdout(), "yes").unwrap();
        }
    }
}
