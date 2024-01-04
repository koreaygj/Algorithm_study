#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
class AC
{
    public:
    int size;
    deque<int> dq;
    int fun_R;
    void input()
    {
        string str;
        cin >> str;
        string a = "";
        if(size == 0)
            return;
        for(int i = 0;i < str.size(); i++)
        {
            if(str[i] == '[')
                continue;
            else if(str[i] == ',' || str[i] == ']')
            {
                dq.push_back(stoi(a));
                a = "";
                continue;
            }
            a += str[i];
        }
    }

    int fun_D()
    {
        if(dq.empty() || size == 0)
        {
            cout << "error\n";
            return 1;
        }
        else
        {
            if(fun_R % 2 != 0)
                dq.pop_back();
            else
                dq.pop_front();
            size--;
            return 0;
        }
    }

    void print(deque<int> a)
    {
        if(fun_R %2 != 0)
            reverse(a.begin(), a.end());
        cout << "[";
        for(int i = 0;i < a.size(); i++)
        {
            if(i == a.size()-1)
            {
                cout << a[i];
                continue;
           }
            cout << a[i] << ",";
        }
        cout << "]" << endl;
    }
};
int main(void)
{
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        string p;
        int n;
        int check;
        cin >> p;
        cin >> n;
        AC ac;
        ac.size = n;
        ac.fun_R = 0;
        ac.input();
        for(int j = 0; j < p.size(); j++)
        {
            if(p[j] == 'R')
                ac.fun_R++;
            else
            {
                if(ac.fun_D()== 1)
                    break;
            } 
            if(j == p.size()-1)
                ac.print(ac.dq);
        }
    }
    return 0;
}