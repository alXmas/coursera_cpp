#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, set<string>> words;

    for (int i = 0; i < n; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            set<string> s1 = {word1};
            set<string> s2 = {word2};
            words[word1].insert(word2);
            words[word2].insert(word1);
        } else if (operation_code == "COUNT") {
            string word;
            cin >> word;
            cout << words[word].size() << endl;
        } else if (operation_code == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (words[word1].count(word2) > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
