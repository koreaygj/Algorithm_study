#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> arr(1000005 * 2 + 1, 0);
class deque
{
    public:
        int head;
        int tail;
        void push_front(int num)
        {
            arr[--head] = num;
        }
        void push_back(int num)
        {
            arr[tail++] = num;
        }
        int pop_front()
        {
            if(empty())
                return -1;
            return arr[head++];
        }
        int pop_back()
        {
            if(empty())
                return -1;
            return arr[--tail] ;
        }
        int size()
        {
            return tail - head;
        }
        int empty()
        {
            if(size() == 0)
                return 1;
            else
                return 0;
        }
        int front(){
            if(empty())
                return -1;
            return arr[head];
        }
        int back(){
            if(empty())
                return -1;
            return arr[tail-1];
        }
};
int main(void)
{
    int n;
    cin >> n;
    deque dq;
    dq.head = dq.tail = 1000005;
    for(int i = 1 ;i <= n; i++)
    {
        string input;
        int num;
        cin >> input;
        if(input[1] == 'u')
        cin >> num;
        if(input == "push_front")
                dq.push_front(num);
        else if(input == "push_back")
                dq.push_back(num);
        else if(input == "pop_front")
            cout << dq.pop_front() << "\n";
        else if(input == "pop_back")
            cout << dq.pop_back() << "\n";
        else if(input == "size")
            cout << dq.size() << "\n";
        else if(input == "empty")
            cout << dq.empty() << "\n";
        else if(input == "front")
            cout << dq.front() << "\n";
        else if(input == "back")
            cout << dq.back() << "\n";
    }
    return 0;
}