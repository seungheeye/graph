#include<vector>
#include<string>
#include <algorithm>
#include "node_data.h"

bool node_data::push_back(std::string &timestamp, double &price){
    //TODO make a compare function, make sure this is a "new" data.
    //return false if not new
    timestamps.push_back(timestamp);
    prices.push_back(price);
    return true;
};

bool node_data::update_data(std::vector<std::string> &t, std::vector<double> &p){
    if (t.size() != p.size()){ return false;}
    timestamps = t;
    prices = p;
    return true;
};

std::vector<std::string> node_data::get_timestamps(int length=-1){
    if (length == -1 || length > timestamps.size()) {length = timestamps.size();}
    std::vector<std::string> ret(timestamps.end() - length, timestamps.end());
    return ret;
};

size_t node_data::size(){
    return prices.size();
};

std::vector<double> node_data::get_prices(int length=-1){
    if (length == -1 || length > prices.size()) {length = prices.size();}
    std::vector<double> ret(prices.end() - length, prices.end());
    return ret;
};

bool node_data::recorded(std::string &timestamp){
    return find(timestamps.begin(), timestamps.end(), timestamp) != timestamps.end();
};

std::string& node_data::current_time(){
    return *(timestamps.end() - 1);
};

double& node_data::current_price(){
    return *(prices.end() - 1);
};

double& node_data::get_price(const std::string &timestamp){
    auto it = find(timestamps.begin(), timestamps.end(), timestamp);
    return prices[it - timestamps.begin()];
};

double& node_data::operator[](const std::string &timestamp){
    return get_price(timestamp);
};
