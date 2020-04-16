#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

string transform(string& str) {
  string result = "";
  for (char i : str) {
      result += tolower(i);
  }
  return result;
}

bool myfunction(string i, string j) {
  return transform(i) < transform(j);
}

int main(){
  int n;
  cin >> n;

  vector<string> v(n);

  for (string& s : v) {
      cin >> s;
  }
  sort(v.begin(), v.end(), myfunction);

  for (string x : v) {
    cout << x << " ";
  }
  return 0;
}
