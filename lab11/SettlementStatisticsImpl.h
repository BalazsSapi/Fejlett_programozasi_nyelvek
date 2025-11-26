//
// Created by domokos.balazs on 26.11.2025.
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H
#include <map>

#include "SettlementStatistics.h"

using namespace std;

class SettlementStatisticsImpl : public SettlementStatistics{
private:
    multimap<string, Settlement> settlements;
public:

    SettlementStatisticsImpl() = default;

    int numSettlements() const override {
        return settlements.size();
    }

    int numCounties() const override ;

    int numSettlementsByCounty(const string &county) const override {
        return settlements.count(county);
    }

    vector<Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulationBySettlement() const override;

    Settlement minPopulationBySettlement() const override;

    vector<Settlement> findSettlementsByName(const string &name) override;

    void readFromFile(string filename);
};


#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H