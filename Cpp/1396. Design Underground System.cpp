/*
Author: Tony Hsiao
Date: 2021/04/24
Topic: 1396. Design Underground System
Speed: 128 ms, 57.4 MB
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

struct TimeRecord{
  int nums = 0;
  int time = 0;
  TimeRecord() {}
  TimeRecord(int n, int t) : nums(n), time(t) {}
};

class UndergroundSystem {
public:
  UndergroundSystem() {

  }

  void checkIn(int id, string stationName, int t) {
    check_in_[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto time_diff = t - check_in_[id].second;
    auto in_station = check_in_[id].first;
    if (station_time_.find (in_station) == station_time_.end() ||
        station_time_[in_station].find(stationName) == station_time_[in_station].end()) {
      station_time_[in_station][stationName] = TimeRecord(1, time_diff);
    } else {
      auto &time_record =  station_time_[in_station][stationName];
      time_record.nums += 1;
      time_record.time += time_diff;
    }
    check_in_.erase (id);
  }

  double getAverageTime(string startStation, string endStation) {
    return station_time_[startStation][endStation].time * 1.0 / station_time_[startStation][endStation].nums;
  }

private:
  /// <people id, <station, check in time>>
  std::unordered_map<int, std::pair<std::string, int>> check_in_;
  /// <check in station, <check out station, time record>>>
  std::unordered_map<std::string, std::unordered_map<std::string, TimeRecord>> station_time_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */