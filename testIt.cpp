
#include <stdio.h>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "processPop.h" 

using namespace std;


//TEST(processPopulation, outputTest) {
//    //setup
//  
//    string expected = "World population is: 1,347,982,728.\n";
//    //redirect standard out
//    ostringstream strCout;
//    streambuf* oldCout = cout.rdbuf(strCout.rdbuf());
//
//    processPopulationFile("./data/worldcitiespop.csv");
//    string actual = strCout.str();
//    EXPECT_EQ(actual, expected);
//
//    cout.rdbuf(oldCout);
//
//}

TEST(processPopulation, outputTest_Mock) {

    //SETUP
    Populatron poppy = {};
    CSVTronFake csvtron = {};
    string cityFile("./data/worldcitiespop_test.csv");
    //ACT
    csvtron.load(cityFile);

    //ASSERT
    int expected = 15;
    int actual = poppy.processPopulationFile(csvtron);
    EXPECT_EQ(actual, expected);


}

TEST(processPopulation, outputTest_FullMock) {

    //SETUP
    Populatron poppy = {};
    CSVTronFake csvtron = {};
    string cityFile("./data/worldcitiespop.csv");
    //ACT
    csvtron.load(cityFile);

    //ASSERT
    int expected = 1347982728;
    int actual = poppy.processPopulationFile(csvtron);
    EXPECT_EQ(actual, expected);


}


//TEST(processCSVTron, CSV_Mock_create)
//{
//    CSVTron csvtron;
//}



int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
