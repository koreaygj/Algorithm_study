#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> max_tree(100005 * 4, 0);
vector<int> min_tree(100005 * 4, 0);
vector<int> arr(1000005, 0);
int init_max(int start, int end, int node)
{
    if(start == end)
        return max_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return max_tree[node] = max(init_max(start, mid, node * 2) , init_max(mid + 1, end, node * 2 + 1));
}
int init_min(int start, int end, int node)
{
    if(start == end)
        return min_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return min_tree[node] = min(init_min(start, mid, node * 2) , init_min(mid + 1, end, node * 2 + 1));
}
int find_max(int start, int end, int node, int left, int right)
{
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return max_tree[node];
    int mid = (start + end) / 2;
    return max(find_max(start, mid, node * 2, left, right), find_max(mid + 1, end, node * 2 + 1, left, right));
}
int find_min(int start, int end, int node, int left, int right)
{
    if(left > end || right < start)
        return 1000000005;
    if(left <= start && end <= right)
        return min_tree[node];
    int mid = (start + end) / 2;
    return min(find_min(start, mid, node * 2, left, right), find_min(mid + 1, end, node * 2 + 1, left, right));
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    vector<pair<int, int>> input;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    init_max(1, n, 1);
    init_min(1, n, 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        input.push_back({a, b});
    }
    for(int i = 0; i < m; i++)
    {
        cout << find_min(1, n, 1, input[i].first, input[i].second) << " " << find_max(1, n, 1, input[i].first, input[i].second) << "\n";
    }
}