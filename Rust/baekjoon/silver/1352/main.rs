use std::collections::VecDeque;
use std::fmt::Write;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.trim().split_ascii_whitespace();

    let n = input.next().unwrap().parse::<usize>().unwrap();
    let m = input.next().unwrap().parse::<usize>().unwrap();

    let mut trunk = vec![Vec::new(); n + 1];

    for _ in 0..m {
        let a = input.next().unwrap().parse::<usize>().unwrap();
        let b = input.next().unwrap().parse::<usize>().unwrap();
        trunk[b].push(a);
    }

    let mut max_cnt = 0;
    let mut cnt_vec = vec![0; n + 1];

    for i in 1..=n {
        let result = bfs(&trunk, i);
        cnt_vec[i] = result;
        max_cnt = std::cmp::max(max_cnt, result);
    }

    let mut output = String::new();
    for (i, &cnt) in cnt_vec.iter().enumerate() {
        if cnt == max_cnt {
            writeln!(output, "{}", i).unwrap();
        }
    }
    print!("{}", output);
}

fn bfs(trunk: &Vec<Vec<usize>>, start: usize) -> usize {
    let mut queue = VecDeque::new();
    let mut visited = vec![false; trunk.len()];
    let mut cnt = 0;

    visited[start] = true;
    queue.push_back(start);

    while let Some(cur) = queue.pop_front() {
        cnt += 1;
        for &next in &trunk[cur] {
            if !visited[next] {
                visited[next] = true;
                queue.push_back(next);
            }
        }
    }

    cnt
}
