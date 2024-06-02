use std::fmt::Write;
use std::io;
use std::io::Read;

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.trim().split_ascii_whitespace();

    let n = input.next().unwrap().parse::<usize>().unwrap();
    let q = input.next().unwrap().parse::<usize>().unwrap();

    let mut array = Vec::new();
    for _ in 0..n {
        let temp = input.next().unwrap().parse::<usize>().unwrap();
        array.push(temp);
    }
    array.sort();
    let mut prefix_sum = vec![0; n + 1];
    for i in 0..n {
        prefix_sum[i + 1] = prefix_sum[i] + array[i];
    }
    let mut output = String::new();
    for _ in 0..q {
        let st_index = input.next().unwrap().parse::<usize>().unwrap() - 1;
        let end_index = input.next().unwrap().parse::<usize>().unwrap();
        let sum: usize = prefix_sum[end_index] - prefix_sum[st_index];
        writeln!(output, "{sum}").unwrap();
    }
    print!("{output}");
}
