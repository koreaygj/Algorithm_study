#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<long long int> tree(1000005 * 4, 0);
vector<long long int> arr(1000005, 0);
long long int init(int start, int end, int node)
{
    if(start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
long long int sum(int start, int end, int node, int left, int right)
{
    if(right < start || left > end)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, long long int change)
{
    if(index < start || index > end)
        return;
    tree[node] += change;
    if(start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, change);
    update(mid + 1, end, node * 2 + 1, index, change);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, n, 1);
    for(int i = 0; i < m + k; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
        {
            long long int diff;
            diff = c - arr[b];
            arr[b] = c;
            update(1, n, 1, b, diff);
        }
        else if(a == 2)
        {
            cout << sum(1, n, 1, b, c) << "\n";
        }
    }
}