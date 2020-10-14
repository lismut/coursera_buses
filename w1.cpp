#include <iostream>
#include <string>
#include <vector>
#include <map>

const std::string new_bus = "NEW_BUS"; // bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
const std::string buses_for_stop = "BUSES_FOR_STOP"; // stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
const std::string stops_for_bus = "STOPS_FOR_BUS"; // bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
const std::string all_buses = "ALL_BUSES"; // — вывести список всех маршрутов с остановками.

const std::string no_stop = "No stop";
const std::string no_bus = "No bus";
const std::string no_buses = "No buses";

int main() {
    std::map<std::string, std::vector<std::string>> bus_stop;
    std::map<std::string, std::vector<std::string>> stop_bus;
    size_t Q;
    std::cin >> Q;
    for(size_t i = 0; i < Q; ++i) {
        std::string comm;
        std::cin >> comm;
        if (comm == new_bus) {
            std::string bus;
            size_t stop_count;
            std::string stop;

            std::cin >> bus;
            std::cin >> stop_count;
            bus_stop[bus];
            for(int i = 0; i < stop_count; ++i) {
                std::cin >> stop;
                bus_stop[bus].push_back(stop);
                stop_bus[stop].push_back(bus);
            }
        } else if (comm == buses_for_stop) {
            std::string stop;
            std::cin >> stop;

            if (stop_bus.find(stop) != stop_bus.end()) {
                if (stop_bus[stop].size() == 0) {
                    std::cout << no_buses << std::endl;
                } else {
                    std::cout << "Stop " << stop << ": ";
                    for(const auto& a : stop_bus[stop])
                        std::cout << a << " ";
                    std::cout << std::endl;
                }
            }

        } else if (comm == stops_for_bus) {
            std::string bus;
            std::cin >> bus;
            if (bus_stop.find(bus) != bus_stop.end()) {

            } else {
                std::cout << no_stop << std::endl;
            }
        }
    }
    return 0;
}