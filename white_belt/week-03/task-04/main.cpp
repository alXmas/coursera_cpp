#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    data.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(data), end(data));
    return data;
  }
private:
  vector<string> data;
};

int main(){
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  strings.GetSortedStrings();
  
  strings.AddString("second");
  strings.GetSortedStrings();

  return 0;
}
