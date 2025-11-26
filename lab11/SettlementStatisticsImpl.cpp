//
// Created by domokos.balazs on 26.11.2025.
//

#include "SettlementStatisticsImpl.h"

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int SettlementStatisticsImpl::numCounties() const {
    int count=0;
    string previous="";
    for (auto &p :settlements) {
        if (p.first!=previous) {
            count++;
            previous=p.first;
        }
    }
    return count;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> s;
    auto it=settlements.equal_range(county);
    while (it.first!=it.second) {
        s.push_back(it.first->second);
        it.first++;
    }
    if (s.empty()==true) {
        throw out_of_range("Invalid county code!");
    }
    return s;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto result=findSettlementsByCounty(county);
    for (auto &r :result) {
        if (r.getName()==name) {
            return r;
        }
    }
    throw out_of_range("Name not found!");
}

Settlement SettlementStatisticsImpl::maxPopulationBySettlement() const {
    int maxi=INT_MIN;

    multimap<string, Settlement>::const_iterator maxSettlement = settlements.cbegin();
    for (auto it = settlements.cbegin(); it != settlements.cend(); ++it) {
        if ( it->second.getPopulation() > maxi ) {
            maxSettlement = it;
            maxi = it->second.getPopulation();
        }
    }
    return maxSettlement->second;
}

Settlement SettlementStatisticsImpl::minPopulationBySettlement() const {
    int mini=INT_MAX;

    multimap<string, Settlement>::const_iterator minSettlement = settlements.cbegin();
    for (auto it = settlements.cbegin(); it != settlements.cend(); ++it) {
        if ( it->second.getPopulation() < mini ) {
            minSettlement = it;
            mini = it->second.getPopulation();
        }
    }
    return minSettlement->second;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> s;
    for (auto &p : settlements) {
        if (p.second.getName()==name) {
            s.push_back(p.second);
        }
    }
    return s;
}

void SettlementStatisticsImpl::readFromFile(string filename) {
    ifstream in(filename);
    if (!in) {
        cout<<"Error! File not found!"<<endl;
        exit(-1);
    }
    string line;
    while (getline(in,line)) {
        istringstream stringStreamLine=istringstream(line);
        string name,countyCode;
        int population;
        getline(stringStreamLine,name,',');
        getline(stringStreamLine,countyCode,',');
        stringStreamLine>>population;
        settlements.insert({countyCode,Settlement(name,countyCode,population)});
    }

}
