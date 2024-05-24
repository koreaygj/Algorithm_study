use std::io::{ stdin, Read};
use std::fmt::Write;

fn main(){
  let mut input = String::new();
  stdin().read_to_string(&mut input).unwrap();
  let mut input = input.split_ascii_whitespace();
  let n = input.next().unwrap().parse::<usize>().unwrap();
  let x = input.next().unwrap().parse::<usize>().unwrap();
  let mut sum_array = vec![0; n];
  
  for i in 0..n{
    let num = input.next().unwrap().parse::<usize>().unwrap();
    if i == 0 {
      sum_array[i] = num
    }
    else{
      sum_array[i] = num + sum_array[i - 1]
    }
  }
  
  let mut max_visit = sum_array[x - 1];
  let mut ans = 1;

  for i in x..n {
    let visit = sum_array[i] - sum_array[i - x];
    if max_visit < visit {
      max_visit = visit;
      ans = 1;
    }else if max_visit == visit{
      ans += 1;
    }
  }

  if max_visit == 0{
    println!("SAD");
  }else{
    let mut output = String::new();
    writeln!(output, "{}", max_visit).unwrap();
    write!(output, "{}", ans).unwrap();
    println!("{}", output);
  }

}