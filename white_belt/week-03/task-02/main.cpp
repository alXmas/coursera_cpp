#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<string> v(n);

  for (string& s : v) {
      cin >> s;
  }
  return 0;
}
