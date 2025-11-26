#include <iostream>

#include "Settlement.h"
#include "SettlementStatisticsImpl.h"

int main() {
    /*Settlement Settlement= Settlement("Szentgyorgy","Maros",10);
    cout<<Settlement;*/

    SettlementStatisticsImpl settlementStatisticsImpl;
    settlementStatisticsImpl.readFromFile("data/telepulesek.csv");
    cout<<settlementStatisticsImpl.numSettlements()<<endl;
    cout<<settlementStatisticsImpl.numCounties()<<endl;
    cout<<settlementStatisticsImpl.numSettlementsByCounty("MS")<<endl;
    /*auto result=settlementStatisticsImpl.findSettlementsByCounty("MS");
    for (auto &r :result) {
        cout<<r<<endl;
    }*/
    cout<<settlementStatisticsImpl.findSettlementsByNameAndCounty("Sangeorgiu de Mures", "MS")<<endl;
    /*auto result=settlementStatisticsImpl.findSettlementsByName("Madaras");
    for (auto &r :result) {
        cout<<r<<endl;
    }*/
    cout<<settlementStatisticsImpl.maxPopulationBySettlement()<<endl;
    cout<<settlementStatisticsImpl.minPopulationBySettlement()<<endl;
    return 0;
}
