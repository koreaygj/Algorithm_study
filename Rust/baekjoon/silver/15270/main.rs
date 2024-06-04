use std::io::{self, Read};
use std::sync::Mutex;

static MAX_PAIRS: Mutex<usize> = Mutex::new(0);

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.trim().split_ascii_whitespace();

    let n = input.next().unwrap().parse::<usize>().unwrap();
    let m = input.next().unwrap().parse::<usize>().unwrap();

    let mut friendships = vec![Vec::new(); m];
    for i in 0..m {
        let a = input.next().unwrap().parse::<usize>().unwrap();
        let b = input.next().unwrap().parse::<usize>().unwrap();
        friendships[i].push(a);
        friendships[i].push(b);
    }

    let mut visited = vec![false; n + 1];
    find_pair(&friendships, &mut visited, 0, 0);
    let max_pairs = MAX_PAIRS.lock().unwrap();
    let answer = if *max_pairs * 2 < n {
        *max_pairs * 2 + 1
    } else {
        *max_pairs * 2
    };
    println!("{}", answer);
}

fn find_pair(friendships: &Vec<Vec<usize>>, visited: &mut Vec<bool>, index: usize, cnt: usize) {
    let m = friendships.len();
    if index >= m {
        let mut max_pairs = MAX_PAIRS.lock().unwrap();
        *max_pairs = std::cmp::max(*max_pairs, cnt);
        return;
    }
    let student_a = friendships[index][0];
    let student_b = friendships[index][1];
    if visited[student_a] || visited[student_b] {
        find_pair(friendships, visited, index + 1, cnt);
    } else {
        visited[student_a] = true;
        visited[student_b] = true;
        find_pair(friendships, visited, index + 1, cnt + 1);
        visited[student_a] = false;
        visited[student_b] = false;
        find_pair(friendships, visited, index + 1, cnt);
    }
}
