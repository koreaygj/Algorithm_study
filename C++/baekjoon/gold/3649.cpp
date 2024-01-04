#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  long long n;
  int m;
  while(cin >> n >> m){
    n *= 10000000;
    long long a;
    vector<long long> v;
    for(int i = 0; i< m; i++){
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    int stIndex = 0, endIndex = m -1;
    bool isFind = false;
    long long sum = 0;
    while(stIndex < endIndex){
      sum = v[stIndex] + v[endIndex];
      if(sum == n){
        isFind = true;
        break;
      }
      else if(sum < n){
        stIndex++;
      }else{
        endIndex--;
      }
    }
    if(isFind)
      cout << "yes " << v[stIndex] << " " << v[endIndex] << "\n";
    else
      cout << "danger\n";
  }
  return 0;
}