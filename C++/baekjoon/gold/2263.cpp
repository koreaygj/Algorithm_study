#include <bits/stdc++.h>
using namespace std;
int inorder[100001];
int postorder[100001];
void preorder(int a, int b, int c, int d){
    cout << postorder[d] << " ";
    if(c == d)
        return;
    int mid = 0;
    for(int i = a; i <= b; i++){
        if(inorder[i] == postorder[d])
            mid = i;
    }
    int l_size = mid - a - 1;
    if(l_size >= 0)
        preorder(a, mid - 1, c, c + l_size);
    if(d - 1 >= c + l_size + 1)
        preorder(mid + 1, b, c + l_size + 1, d - 1);
}
int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }
    for(int i = 0; i < n; i++){
        cin >> postorder[i];
    }
    preorder(0, n - 1, 0, n - 1);
    cout << "\n";
}