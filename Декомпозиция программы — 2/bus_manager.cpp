#include "bus_manager.h"

using namespace std;

	void BusManager::AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
		BusesForStopResponse r;
		if (stops_to_buses.count(stop) == 0) {
			r.no_stop = true;
		}
		else {
			r.in = stops_to_buses.at(stop);
			r.no_stop = false;
		}
		return r;
	}

	StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
		StopsForBusResponse r;
		if (buses_to_stops.count(bus) == 0) {
			r.no_bus = true;
		}
		else {
			r.no_bus = false;
			for (const string& stop : buses_to_stops.at(bus)) {
				pair <string, vector<string>> input;
				input.first = stop;
				if (stops_to_buses.at(stop).size() == 1) {
					string no_interchange = "no interchange";
					input.second.push_back(no_interchange);
				}
				else {

					for (const string& other_bus : stops_to_buses.at(stop)) {
						if (bus != other_bus) {
							input.second.push_back(other_bus);
						}
					}
				}
				r.in.push_back(input);
			}
		}
		return r;
	}

	AllBusesResponse BusManager::GetAllBuses() const {
		AllBusesResponse r;
		if (buses_to_stops.empty()) {
			r.no_buses = true;
		}
		else {
			r.no_buses = false;
			r.in = buses_to_stops;
		}
		return r;
	}
