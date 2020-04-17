#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

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
    // получить все имена и фамилии по состоянию на конец года year
  }
private:
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
