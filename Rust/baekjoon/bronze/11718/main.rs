use std::io::{stdin, stdout, Write};
fn main() {
    let mut buffer = String::new();
    let mut input = vec![];
    while true {
        buffer.clear();
        let bytes_read = stdin().read_line(&mut buffer).unwrap();
        if bytes_read == 0 {
            break;
        }
        input.push(buffer.trim().to_string());
    }
    let mut stdout = stdout();
    for line in input {
        writeln!(stdout, "{}", line).unwrap();
    }
}
