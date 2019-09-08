#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct BusesForStopResponse {
	vector<string> in;
	bool no_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	vector<pair<string, vector<string>>> in;
	bool no_bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	bool no_buses;
	map<string, vector<string>> in;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);


