use std::io::{stdin, stdout, Write};
fn main() {
    let mut bf = String::new();
    stdin().read_line(&mut bf).unwrap();
    let st = bf.trim().parse::<usize>().unwrap();
    for _ in 0..(st / 4) {
        write!(stdout(), "long ");
    }
    write!(stdout(), "int\n");
}
