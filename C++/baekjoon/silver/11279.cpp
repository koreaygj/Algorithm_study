#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//시간초과 버전, max_heap 구현해보기
vector<int> heap;
int sz;
void addNode(int cur){
    if(cur == 1)
        return;
    int parent = cur / 2;
    if(heap[cur] > heap[parent]){
        swap(heap[cur], heap[parent]);
        addNode(cur / 2);
    }
}
void delNode(int cur){
    int left, right, child;
    left = (cur * 2 <= sz ? cur * 2 : -1);
    right = (cur * 2 + 1 <= sz ? cur % 2 + 1: -1);
    if(left == -1 && right == -1) 
        child = -1;
    else if(left != -1 && right == -1)
        child = left;
    else
        child = (heap[left] > heap[right] ? left : right);
    if(child == -1)
        return;
    if(heap[child] > heap[cur]) {
        swap(heap[child], heap[cur]);
        delNode(child);
    }
}
int main(void){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    heap.push_back(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(input == 0){
            if(sz == 0)
                cout << "0\n";
            else{
                cout << heap[1] << "\n";
                heap[1] = heap[sz];
                heap.pop_back();
                sz--;
                delNode(1);
            }
        }
        else{
            sz++;
            heap.push_back(input);
            addNode(sz);
        }
    }
}