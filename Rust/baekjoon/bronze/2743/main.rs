use std::io::{stdin, stdout, Write};
fn main() {
    let mut bf = String::new();
    stdin().read_line(&mut bf).unwrap();
    let mut s = bf.trim().to_string();
    writeln!(stdout(), "{}", s.len()).unwrap();
}
