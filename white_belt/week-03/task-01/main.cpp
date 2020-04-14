#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

bool myfunction (int i,int j) { return (abs(i)  < abs(j)); }

int main(){
  int n;
  cin >> n;

  vector<int> v(n);

  for (int& s : v) {
      cin >> s;
  }

  sort(v.begin(), v.end(), myfunction);
    
  for(const auto& i:v){
      cout << i << " ";
  }
  return 0;
}
