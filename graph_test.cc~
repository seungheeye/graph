#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<map>
#include "graph_structure.h"
int main(){
    int counter{0};
    graph a;
    std::map<std::string, int> mo;
    mo["a"] = 1;
    mo["b"] = 2;
    node_data_T<int> b{mo};

    a.add_node("a", b);
    a.add_node("b", b);
    a.add_node("c", b);
    a.add_node("d", b);
    a.add_node("d", b);
    a.add_node("e",b);
    a.add_node("f",b);
    a.add_node("g",b);
    a.add_node("h",b);



    auto *ndt= node::child<int>(a.nodes["c"]->data);
    if ((*ndt)["a"] == 1){ std::cout << "PASSED TEST " << counter++ << std::endl;}
    else { std::cout << "FAILED TEST " << counter++ << std::endl;}

    auto *mdt = a.nodes["a"]->get_data<int>();
    if ((*mdt)["b"] == 2){ std::cout << "PASSED TEST " << counter++ << std::endl;}
    else { std::cout << "FAILED TEST " << counter++ << std::endl;}

    edge_data c(3);
    a.add_edge("a","b",c);
    a.add_edge("b","c",c);
    a.add_edge("c","a",c);
    a.add_edge("a","d",c);
    a.add_edge("e","d",c);
    a.add_edge("f","g",c);
    for (auto x : a.nodes){
        std::cout<< x.first<< " In: ";
        for (auto u: a.In(x.first)){std::cout<<u << " " ;}
        std::cout<<  " Out: ";
        for (auto u: a.Out(x.first)){std::cout<<u << " " ;}
        std::cout<< "\n";

    }

    std::cout<< "\n";

    for (auto x : a.invariant_measure(0.0000015)){std::cout<< x.first<<" " << x.second << "\n";}

}



