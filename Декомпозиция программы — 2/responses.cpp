#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (!r.no_stop) {
		for (const auto& item : r.in) {
			os << item << " ";
		}
		os << endl;
	}
	else {
		os << "No stop" << endl;
	}
	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (!r.no_bus) {
		for (const pair<string, vector<string>>& item : r.in) {
			os << "Stop " << item.first << ": ";
			for (const string& stop : item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	else {
		os << "No bus" << endl;
	}
	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (!r.no_buses) {
		for (const auto& bus_item : r.in) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	else {
		os << "No buses" << endl;
	}

	return os;
}