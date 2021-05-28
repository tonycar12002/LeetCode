/*
Author: Tony Hsiao
Date: 2021/05/23
Topic: 690. Employee Importance
Speed: 28 ms, 14.1 MB
Note:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
  int DFS(const std::map<int, Employee*>& table, int id) {
    int sum = table.at(id)->importance;
    for (const auto& i : table.at(id)->subordinates) {
      sum += DFS(table, i);
    }
    return sum;
  }

  int getImportance(vector<Employee*> employees, int id) {
    // id to employee
    std::map<int, Employee*> table;
    for (size_t i = 0; i < employees.size(); ++i) {
      table[employees[i]->id] = employees[i];
    }
    return DFS(table, id);
  }
};