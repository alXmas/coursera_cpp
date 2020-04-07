#include <iostream>
#include <set>

using namespace std;

void 
int main() {
    int n;
    set<string> result; 

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        result.insert(str);
    }

    cout << result.size();

    return 0;
}
