//
// Created by domokos.balazs on 26.11.2025.
//

#ifndef LAB11_SETTLEMENTSTATISTICS_H
#define LAB11_SETTLEMENTSTATISTICS_H
#include <string>
#include <vector>
#include "Settlement.h"

using namespace std;

struct SettlementStatistics {
    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector<Settlement> findSettlementsByCounty(const string &county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const = 0;

    virtual Settlement maxPopulationBySettlement() const = 0;

    virtual Settlement minPopulationBySettlement() const = 0;

    virtual vector<Settlement> findSettlementsByName(const string &name) = 0;
};

#endif //LAB11_SETTLEMENTSTATISTICS_H
