use std::io;

fn is_palindrome(s: &str) -> bool {
    let chars: Vec<char> = s.chars().collect();
    let cnt = chars.len() / 2;
    for i in 0..cnt {
        if chars[i] != chars[chars.len() - 1 - i] {
            return false;
        }
    }
    true
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input = input.trim();

    let mut answer = input.len() * 2 - 1;
    for i in 0..input.len() {
        let temp = &input[i..];
        if is_palindrome(temp) {
            answer = input.len() + i;
            break;
        }
    }

    println!("{}", answer);
}
