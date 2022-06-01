#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    int n;
    int result = 0;
    vector<int> num = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> alphabet(27, 0);
    cin >> n;
    for(int i = 0 ;i < n; i++)
    {
        string input;
        cin >> input;
        int count = 1;
        for(int j = 0; j < input.size(); j++)
        {
            alphabet[input[j] - 'A'] += pow(10, input.size() - count);
            count++;
        }
    }
    sort(alphabet.begin(), alphabet.end(), greater<>());
    for(int i = 0; i < alphabet.size(); i++)
    {
        result += alphabet[i] * num[i];
    }
    cout << result << "\n";
}
