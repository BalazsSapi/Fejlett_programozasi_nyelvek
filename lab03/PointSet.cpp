//
// Created by domokos.balazs on 01.10.2025.
//

#include "PointSet.h"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>

using namespace std;


void PointSet::computeDistances() {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

PointSet::PointSet(int n) {
    this->n=n;
    bool mat[M+1][M+1]={false};
    srand(time(nullptr));
    while (points.size()<n) {
        Point p(rand()%(M+1),rand()%(M+1));
        if (mat[p.getX()][p.getY()]==false) {
            mat[p.getX()][p.getY()]=true;
            points.push_back(p);
        }
    }
    computeDistances();
}

double PointSet::maxDistance() const {
    if (distances.empty()) {
        cout<<"Nincs távolság az adathalmazban.";
    }
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    if (distances.empty()) {
        cout<<"Nincs távolság az adathalmazban.";
    }
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (auto p:points) {
        cout<<"("<<p.getX()<<","<<p.getY()<<") ";
    }
    cout<<endl;
}

void PointSet::printDistances() const {
    for (auto d:distances) {
        cout<<d<<" ";
    }
    cout<<endl;
}

bool cmpX(Point a, Point b) {
    return a.getX()<b.getX();
}

void PointSet::sortPointsX() {
    sort(points.begin(),points.end(),cmpX);
}

bool cmpY(Point a, Point b) {
    return a.getY()<b.getY();
}

void PointSet::sortPointsY() {
    sort(points.begin(),points.end(),cmpY);
}

void PointSet::sortDistances() {
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances() {
    this->sortDistances();
    vector<double>::iterator ip = unique(distances.begin(), distances.end());
    return distance(distances.begin(), ip);
}




