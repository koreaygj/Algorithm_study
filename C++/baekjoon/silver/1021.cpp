#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main(void)
{
    int n, m;
    int answer = 0;
    deque<int> que; 
    deque<int> input;
    cin >> n >> m;
    for(int i = 0; i< m; i++)
    {       
        int num;
        cin >> num;
        input.push_back(num);
    }
    for(int i = 1; i <= n; i++)
        que.push_back(i);
    for(int i = 0;i < m; i++)
    {
        if(que.front() == input[i])
        {
            que.erase(que.begin());
            continue;
        }
        if(find(que.begin(), que.end(), input[i]) - que.begin() <= que.size()/2)
        {
            while(que.front() != input[i])
            {
                que.push_back(que.front());
                que.erase(que.begin());
                answer++;
            }
        }
        else
        {
            while(que.front() != input[i])
            {
                que.push_front(que.back());
                que.pop_back();
                answer++;
            }
        }
            que.erase(que.begin());
    }
    cout << answer << endl;
}