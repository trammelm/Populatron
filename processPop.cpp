
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "processPop.h"

using namespace std;

Populatron::Populatron()
{
    

}

Populatron::~Populatron()
{
}

int Populatron::processPopulationFile(CSVTron csvtron)
{
    long sum = 0;
    size_t rowSize = csvtron.rows.size();

    for (int i = 0; i < rowSize; i++)
    {
        vector<string> strd = csvtron.rows[i];
        string substring = strd[4];
        long pop = 0;
        if (substring.length() > 0) 
        {
            pop = stoi(substring);
            sum += pop;
        }
    }
    
    return sum;
}

//int processPopulationFile(string fileName) {
//    
//    
//    long sum = 0;
//    vector<string> lines;
//    vector<string> lineItems;
//    string line;
//    string substring;
//    ifstream cityFile(fileName);
//
//    if (!cityFile) //Always test the file open.
//    {
//        std::cout << "Error opening output file" << std::endl;
//        system("pause");
//        return -1;
//    }
//    while (std::getline(cityFile, line))
//    {
//        lines.push_back(line);
//    }
//    stringstream* token_ptr;
//    for (int i = 1; i < lines.size(); i++) {
//        vector<string> lineItems;
//        token_ptr = new stringstream(lines[i]);
//        while ((*token_ptr).good()) {
//            getline(*token_ptr, substring, ',');
//            lineItems.push_back(substring);
//        }
//        substring = lineItems[4];
//        long pop = 0;
//        if (substring.length() > 0) {
//            pop = stoi(substring);
//        }
//        sum += pop;
//        delete token_ptr;
//    }
//    stringstream ss;
//    ss.imbue(std::locale(""));
//    ss << std::fixed << sum;
//    string num = ss.str();
//
//    cout << "World population is: " << num << "." << endl;
//    return 0;
//}
//
//
