#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <istream>
#include <fstream>
using namespace std;
int n;
int max_block;
void left(int count, vector<vector<int>> board);
void right(int count, vector<vector<int>> board);
void up(int count, vector<vector<int>> board);
void down(int count, vector<vector<int>> board);
bool is_end(int count)
{
    if(count == 5)
        return false;
    return true;
}
void left(int count, vector<vector<int>> board)
{
    if(!is_end(count))
        return;
    for(int i = 0; i < n; i++)
    {
        queue<int> row, result;
        int zero = 0;
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] != 0)
            {
                row.push(board[i][j]);
                continue;
            }
            zero++;
        }
        while(!row.empty())
        {
            int temp = row.front();
            row.pop();
            max_block = max(max_block, temp);
            if(row.empty())
            {
                result.push(temp);
                break;
            }
            if(temp != row.front())
            {
                result.push(temp);
            }
            else
            {
                result.push(temp * 2);
                max_block = max(max_block, temp * 2);
                row.pop();
                zero++;
            }
        }
        for(int j = 0; j < zero; j++)
            result.push(0);
        for(int j = 0; j < n; j++)
        {
            board[i][j] = result.front();
            result.pop();
        }
    }
    left(count + 1, board);
    right(count + 1, board);
    up(count + 1, board);
    down(count + 1, board);
}
void right(int count, vector<vector<int>> board)
{
    if(!is_end(count))
        return;
    for(int i = 0; i < n; i++)
    {
        queue<int> row, result;
        int zero = 0;
        for(int j = n - 1; j >= 0; j--)
        {
            if(board[i][j] != 0)
            {
                row.push(board[i][j]);
                continue;
            }
            zero++;
        }
        while(!row.empty())
        {
            int temp = row.front();
            row.pop();
            max_block = max(max_block, temp);
            if(row.empty())
            {
                result.push(temp);                
                break;
            }
            if(temp != row.front())
            {
                result.push(temp);
            }
            else
            {
                result.push(temp * 2);
                max_block = max(max_block, temp * 2);
                row.pop();
                zero++;
            }
        }
        for(int j = 0; j < zero; j++)
            result.push(0);
        for(int j = n - 1; j >= 0; j--)
        {
            board[i][j] = result.front();
            result.pop();
        }
    }
    left(count + 1, board);
    right(count + 1, board);
    up(count + 1, board);
    down(count + 1, board);
}
void up(int count, vector<vector<int>> board)
{   
    if(!is_end(count))
        return;
    for(int i = 0; i < n; i++)
    {
        queue<int> row, result;
        int zero = 0;
        for(int j = 0; j < n; j++)
        {
            if(board[j][i] != 0)
            {
                row.push(board[j][i]);
                continue;
            }
            zero++;
        }
        while(!row.empty())
        {
            int temp = row.front();
            row.pop();
            max_block = max(max_block, temp);
            if(row.empty())
            {
                result.push(temp);                
                break;
            }
            if(temp != row.front())
            {
                result.push(temp);
            }
            else
            {
                result.push(temp * 2);
                max_block = max(max_block, temp * 2);
                row.pop();
                zero++;
            }
        }
        for(int j = 0; j < zero; j++)
            result.push(0);
        for(int j = 0; j < n; j++)
        {
            board[j][i] = result.front();
            result.pop();
        }
    }
    left(count + 1, board);
    right(count + 1, board);
    up(count + 1, board);
    down(count + 1, board);
}
void down(int count, vector<vector<int>> board)
{
    if(!is_end(count))
        return;
    for(int i = 0; i < n; i++)
    {
        queue<int> row, result;
        int zero = 0;
        for(int j = n - 1; j >= 0; j--)
        {
            if(board[j][i] != 0)
            {
                row.push(board[j][i]);
                continue;
            }
            zero++;
        }
        while(!row.empty())
        {
            int temp = row.front();
            row.pop();
            max_block = max(max_block, temp);
            if(row.empty())
            {
                result.push(temp);                
                break;
            }
            if(temp != row.front())
            {
                result.push(temp);
            }
            else
            {
                result.push(temp * 2);
                max_block = max(max_block, temp * 2);
                row.pop();
                zero++;
            }
        }
        for(int j = 0; j < zero; j++)
            result.push(0);
        for(int j = n - 1; j >= 0; j--)
        {
            board[j][i] = result.front();
            result.pop();
        }
    }
    left(count + 1, board);
    right(count + 1, board);
    up(count + 1, board);
    down(count + 1, board);
}
void dfs(vector<vector<int>> board)
{
    left(0, board);
    right(0, board);
    up(0, board);
    down(0, board);
}
int main(void)
{
    cin >> n;
    vector<vector<int>> board(21, vector<int> (21, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    dfs(board);
    cout << max_block << "\n";
}