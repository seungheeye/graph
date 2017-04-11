#ifndef NODE_DATA_H_
#define NODE_DATA_H_
#include<vector>
#include<string>

class node_data{
    private:
        std::vector<std::string> timestamps;
        std::vector<double> prices;

    public:
        bool push_back(std::string&, double&);
        bool update_data(std::vector<std:: string>&, std::vector<double>&);
        size_t size();
        std::vector<std::string> get_timestamps(int);
        std::vector<double> get_prices(int);
        bool recorded(std::string&);
        std::string& current_time();
        double& current_price();
        double& get_price(const std::string&); //Exception handling in case wrong timestamp?
        double& operator[](const std::string&); //Same as get_price
};


#endif