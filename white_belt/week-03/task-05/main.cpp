#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string FindNameByYear(int year, const map<int, string>& names) {
    string name;

    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        } else {
            break;
        }
    }

    return name;
}

string GetHistory(int year, const map<int, string>& names) {
    vector<string> names_history;
    string current_name = "";
    
    for (const auto& item : names) {
        if (item.first <= year) {
            if (item.second != current_name) {
                vector<string> v = {item.second};
                names_history.insert(begin(names_history), begin(v), end(v));
                current_name = item.second;
            }
        } else {
            break;
        }
    }
    
    string history = "";
    
    for (int i = 1; i < names_history.size(); ++i) {
        if (history.size() == 0) {
            history += names_history[i];
        } else {
            history = history + ", " + names_history[i];
        }
    }
    
    return history;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    firstname[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    lastname[year] = last_name;
  }
  string GetFullName(int year) {
      string first_name = GetFirstName(year, firstname);
      string last_name = GetLastName(year, lastname);
      string full_name = first_name + " " + last_name;
      if (first_name.size() == 0 && last_name.size() == 0) {
          full_name = "Incognito";
          return full_name;
      } else if (first_name.size() == 0) {
          full_name = last_name + " with unknown first name";
          return full_name;
      } else if (last_name.size() == 0) {
          full_name = first_name + " with unknown last name";
          return full_name;
      }
      return full_name;
  }
  string GetFullNameWithHistory(int year) {
    const string first_name = FindNameByYear(year, firstname);
    const string last_name = FindNameByYear(year, lastname);
    const string history_first_name = GetHistory(year, firstname);
    const string history_last_name = GetHistory(year, lastname);
    string full_name = first_name + " (" + history_first_name + ")" + " " + last_name + " (" + history_last_name + ")";
    if (first_name.size() == 0 && last_name.size() == 0) {
        full_name = "Incognito";
        return full_name;
    } else if (first_name.size() == 0) {
        if (history_last_name.size() == 0) {
            full_name = last_name + " with unknown first name";
            return full_name;
        } else {
            full_name = last_name + " (" + history_last_name + ")" + " with unknown first name";
            return full_name;
        }
    } else if (last_name.size() == 0) {
        if (history_first_name.size() == 0) {
            full_name = first_name + " with unknown last name";
            return full_name;
        } else {
            full_name = first_name + " (" + history_first_name + ")" + " with unknown last name";
            return full_name;
        }
    } else if (history_first_name.size() == 0 && history_last_name.size() == 0) {
        full_name = first_name + " " + last_name;
        return full_name;
    } else if (history_first_name.size() == 0) {
        full_name = first_name + " " + last_name + " (" + history_last_name + ")" ;
        return full_name;
    } else if (history_last_name.size() == 0) {
        full_name = first_name + " (" + history_first_name + ") " + last_name;
        return full_name;
    }
    return full_name;
  }
    string GetFirstName(int year, map<int, string>& firstname) {
        while (firstname.count(year) == 0 && year > 0) {
            --year;
        }
        return firstname[year];
    }
    string GetLastName(int year, map<int, string>& lastname) {
        while (lastname.count(year) == 0 && year > 0) {
            --year;
        }
        return lastname[year];
    }
private:
    map<int, string> firstname;
    map<int, string> lastname;
};

int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}
