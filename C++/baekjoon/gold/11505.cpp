#include <iostream>
#include <algorithm>
#include <vector>
#define div_num 1000000007
using namespace std;
vector<long long int> tree(1000005 * 4, 0);
vector<int> arr(1000005, 0);
long long int init(int start, int end, int node)
{
    if(start == end)
        return tree[node] = arr[start] % div_num;
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2)* init(mid + 1, end, node * 2 + 1)) % div_num;
}
long long int multiplex(int start, int end, int node, int left, int right)
{
    if(left > end || right < start)
        return 1;
    if(left <= start && end <= right)
        return tree[node] % div_num;
    int mid = (start + end) / 2;
    return (multiplex(start, mid, node * 2, left, right) * multiplex(mid + 1, end, node * 2 + 1, left, right)) % div_num;
}
void update(int start, int end, int node, int index, long long int change)
{
    if(index < start || index > end)
        return;
    if(start == end)
    {
        tree[node] = change;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, change);
    update(mid + 1, end, node * 2 + 1, index, change);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % div_num;
}
int main(void)
{
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
        int a;
        cin >> a;
        if(a == 1)
        {
            int b;
            long long int c;
            cin >> b >> c;
            update(1, n, 1, b, c);
        }
        else if(a == 2)
        {
            int b, c;
            cin >> b >> c;
            cout << multiplex(1, n, 1, b, c) << "\n";
        }
    }
}