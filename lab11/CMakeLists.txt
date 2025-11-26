cmake_minimum_required(VERSION 3.30)

project(lab11)

set(CMAKE_CXX_STANDARD 26)

add_executable(lab11 main_11.cpp
        Settlement.cpp
        Settlement.h
        SettlementStatistics.cpp
        SettlementStatistics.h
        SettlementStatisticsImpl.cpp
        SettlementStatisticsImpl.h
)


