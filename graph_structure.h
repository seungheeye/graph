#ifndef GRAPH_STRUCTURE_H_
#define GRAPH_STRUCTURE_H_

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>

class node_data{
    protected:
        std::string data_type;

    public:
        virtual ~node_data(){};
};

template <class T>
class node_data_T: public node_data{
    //TODO
    std::map<std::string,T> data;

    public:
    T& operator[] (std::string key) {return data[key];}
    void remove_key(std::string key){data.erase(key);}
    std::map<std::string, T> get_data() {return data;}
    const std::map<std::string,T> get_const_data() const {return data;}
    node_data_T(const node_data_T & old_one): data(old_one.data){}
    node_data_T(std::map<std::string, T> x):data{x}{}
    node_data_T(){}
};

class edge_data{
    //TODO
    int a;
    public:
    edge_data(int x): a{x}{};
    int get_data() const {return a;}
};

struct node;
struct edge;

struct edge{
    edge_data *data=nullptr;
    node *start=nullptr;
    node *end=nullptr;
    edge *next_edge_start=nullptr;
    edge *next_edge_end=nullptr;	
    edge *prev_edge_start=nullptr;
    edge *prev_edge_end=nullptr;	
    ~edge();
    edge(node*,node*,const edge_data&);
};

class node{
    public:
        std::string unique_id;
        node_data *data=nullptr;
        edge *first_edge_in=nullptr;
        edge *last_edge_in=nullptr;
        edge *last_edge_out=nullptr;
        edge *first_edge_out=nullptr;
        template <class T> static node_data_T<T>* child (node_data * x){
            return dynamic_cast <node_data_T<T>*> (x);
        }
        template <class T> node_data_T<T>* get_data(){
            return dynamic_cast <node_data_T<T>*> (data);
        }
        ~node();
        template <class T> node(std::string id,node_data_T<T> old_data){
            data=new node_data_T<T>{old_data};
            unique_id = id;
        } 
};


class graph{
    public:
        std::unordered_map<std::string,node*> nodes;
        template <class T> void add_node(std::string id,node_data_T<T>& data){
            nodes[id] = new node(id, data);
        }
        void add_edge(std::string start,std::string end,edge_data & data){
            new edge(nodes[start],nodes[end] ,data);
        }
        void remove_node(std::string id){delete nodes[id];nodes.erase(id);}

        std::vector<std::string> In(std::string node);
        std::vector<std::string> Out(std::string node);

        std::unordered_map<std::string,double> invariant_measure(double);
};



#endif
