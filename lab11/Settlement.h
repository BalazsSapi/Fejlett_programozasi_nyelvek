//
// Created by domokos.balazs on 26.11.2025.
//

#ifndef LAB11_SATTLEMENT_H
#define LAB11_SATTLEMENT_H
#include <ostream>
#include <string>

using namespace std;

class Settlement {
private:
    string name = "";
    string county = "";
    int population = 0;

public:
    Settlement(const string &name, const string &county, int population) : name(name), county(county), population(population) {}

    [[nodiscard]] string getName() const {
        return name;
    }

    void set_name(const string &name) {
        this->name = name;
    }

    string getCounty() const {
        return county;
    }

    void set_coutry(const string &county) {
        this->county = county;
    }

    int getPopulation() const {
        return population;
    }

    void set_population(int population) {
        this->population = population;
    }

    friend ostream & operator<<(std::ostream &os, const Settlement &obj) {
        return os
                << obj.name <<": "
                << obj.county << " county, "
                << " population: " << obj.population;
    }
};


#endif //LAB11_SATTLEMENT_H
