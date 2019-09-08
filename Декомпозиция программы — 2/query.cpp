#include "query.h"
#include <iostream>

using namespace std;

istream& operator >> (istream& is, Query& q) {
	string key;
	is >> key;
	if (key == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stops_count;
		is >> stops_count;
		q.stops.resize(stops_count);
		for (auto& item : q.stops) {
			cin >> item;
		}
	}
	else if (key == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (key == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (key == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}

	return is;
}