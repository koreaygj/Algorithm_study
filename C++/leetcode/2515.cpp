#include<vector>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int size =  words.size();
        for(int i = 0; i <= size / 2; i++){
            string left = words[(startIndex + i) % size];
            string right = words[(startIndex - i + size) % size];
            if(target == left || target == right){
                return i;
            }
        }
        return -1;
    }
};
