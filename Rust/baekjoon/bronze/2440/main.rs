use std::io::{stdin, stdout, Write};
fn main() {
    let mut bf = String::new();
    stdin().read_line(&mut bf).unwrap();
    let n = bf.trim().parse::<usize>().unwrap();
    for i in (1..=n).rev() {
        for _ in 0..i {
            write!(stdout(), "*").unwrap();
        }
        writeln!(stdout()).unwrap();
    }
}
