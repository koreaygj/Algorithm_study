use std::io::stdin;

fn main() {
    let mut buffer = String::new();
    stdin().read_line(&mut buffer).unwrap();
    let a = buffer.trim().parse::<usize>().unwrap();
    buffer.clear();
    stdin().read_line(&mut buffer).unwrap();
    let b = buffer.trim().parse::<usize>().unwrap();
    buffer.clear();

    let answer = a + b;
    println!("{}", answer);
}
