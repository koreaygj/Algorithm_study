use std::io::{ stdin, Read};
use std::fmt::Write;

fn main() {
  let mut input = String::new();
  stdin().read_to_string(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace();

  let n = input.next().unwrap().parse::<usize>().unwrap();
  let mut dp = [[0; 100_001]; 3];
  let mut cases = Vec::with_capacity(n);
  let mut max_case = 0;
  let mut output = String::new();

  for _ in 0..n {
    let case_num = input.next().unwrap().parse::<usize>().unwrap();
    cases.push(case_num);
    if max_case < case_num {max_case = case_num;}
  }
  
  cal_case(max_case, &mut dp);

  for num in cases {
    let result = (dp[0][num - 1] + dp[1][num - 1] + dp[2][num - 1]) % 1_000_000_009;
    writeln!(output, "{}", result).unwrap();
  }
  println!("{output}");
}

fn cal_case(max_case: usize, dp: &mut [[usize; 100_001]; 3]) {
  dp[0][0] = 1;
  dp[1][1] = 1;
  dp[0][2] = 1;
  dp[1][2] = 1;
  dp[2][2] = 1;
  for i in 3..max_case{
    dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % 1_000_000_009;
    dp[1][i] = (dp[0][i - 2] + dp[2][i - 2]) % 1_000_000_009;
    dp[2][i] = (dp[0][i - 3] + dp[1][i - 3]) % 1_000_000_009;
  }
}