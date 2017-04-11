#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include "graph_structure.h"

node::~node() {
    //delete data;
    while (first_edge_in!=nullptr){
        delete first_edge_in;
    }
    while (first_edge_out!=nullptr){
        delete first_edge_out;
    }
}
/*
   node::node(std::string id, const node_data& in_data):unique_id{id}{
   data= new node_data(in_data);
   };
   */

edge::~edge(){
    if (next_edge_start!=nullptr){
        next_edge_start->prev_edge_start=prev_edge_start;}
    else {start->last_edge_out= prev_edge_start;}

    if (prev_edge_start!=nullptr){
        prev_edge_start->next_edge_start=next_edge_start;}	
    else {start->first_edge_out=next_edge_start;}

    if (next_edge_end!=nullptr){
        next_edge_end->prev_edge_end=prev_edge_end;}
    else {end->last_edge_in=prev_edge_end;}

    if (prev_edge_end!=nullptr){
        prev_edge_end->next_edge_end=next_edge_end;}	
    else {end->first_edge_in= next_edge_end;}

}; 

edge::edge(node* ptr_start,node* ptr_end,const edge_data& in_data){
    start=ptr_start;
    end=ptr_end;
    data=new edge_data(in_data);
    prev_edge_start=start->last_edge_out;
    prev_edge_end=end->last_edge_in;
    if (start->last_edge_out!=nullptr){
        start->last_edge_out->next_edge_start= this;
    }
    else {start->first_edge_out=this;}
    if (	end->last_edge_in!=nullptr){
        end->last_edge_in->next_edge_end=this;
    }
    else{end->first_edge_in=this;}

    start->last_edge_out=this;
    end->last_edge_in=this;

}

std::vector<std::string> graph::In(std::string node){
    std::vector<std::string> ret;
    auto temp=nodes[node]->first_edge_in;
    while (temp!=nullptr){ret.push_back(temp->start->unique_id); temp=temp->next_edge_end;}
    return ret;
}

std::vector<std::string> graph::Out(std::string node){
    std::vector<std::string> ret;
    auto temp=nodes[node]->first_edge_out;
    while (temp!=nullptr){ret.push_back(temp->end->unique_id); temp=temp->next_edge_start;}
    return ret;
}

std::unordered_map<std::string,double> graph::invariant_measure(double p){
    std::unordered_map<std::string,double> ret;
    std::unordered_map<std::string,double> temp;

    int length=0;
    for (auto x:nodes){ret[x.first]=1.0;temp[x.first]=0.0;length+=1;}
    for (int i=0;i<50;i++){
        double count=0.0;
        for (auto y : ret){
            auto n=Out(y.first).size();
            if (n==0){count+=ret[y.first];}
            for (auto z: Out(y.first)){
                temp[z]+=ret[y.first]/n;
            }
        }
        for (auto y:ret){ret[y.first]=(1-p)*temp[y.first]+p+(1-p)*count/length;temp[y.first]=0.0; }
    }  

    double sum=0;
    for (auto y : ret){ sum+= ret[y.first];}
    ret["sum"]=sum;

    return ret;
}
