
#ifndef processPop_h
#define processPop_h

#include <stdio.h>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

class CSVTron
{
public:

    CSVTron() {};
    ~CSVTron() {};

    vector<string> lines;
    vector<string> row;
    vector<vector<string>> rows;
    string line;
    string substring;


    void load(std::string filepath)
    {
        stringstream* token_ptr;
        ifstream file(filepath);

        if (!file) //Always test the file open.
        {
            //std::cout << "Error opening output file" << std::endl;
            //system("pause");
            //return -1;
        }
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        size_t lineSize = lines.size();
        for (int i = 1; i < lineSize; i++)
        {
            token_ptr = new stringstream(lines[i]);
            while ((*token_ptr).good())
            {
                getline(*token_ptr, substring, ',');
                row.push_back(substring);
            }
            rows.push_back(row);
            delete token_ptr;
            row.clear();
        }

    }


};

class CSVTronFake : public CSVTron
{

public:
    void load(std::string filepath)
    {
        if (filepath == "./data/worldcitiespop_test.csv")
        {
            vector<string> row1 = { "ad","aixas","Aixàs","6","","42.4833333", "1.4666667" };
            vector<string> row2 = { "ad","aixas","Aixàs","6","5","42.4833333", "1.4666667" };
            vector<string> row3 = { "ad","aixas","Aixàs","6","10","42.4833333", "1.4666667" };

            rows.push_back(row1);
            rows.push_back(row2);
            rows.push_back(row3);
        }
        else if(filepath == "./data/worldcitiespop.csv")
        {
            vector<string> row1 = { "ad","aixas","Aixàs","6","","42.4833333", "1.4666667" };
            vector<string> row2 = { "ad","aixas","Aixàs","6","","42.4833333", "1.4666667" };
            vector<string> row3 = { "ad","aixas","Aixàs","6","1347982728","42.4833333", "1.4666667" };

            rows.push_back(row1);
            rows.push_back(row2);
            rows.push_back(row3);
        }
           
    }

};

// old method
//int processPopulationFile(string fileName);

class Populatron
{
public:
	Populatron();
	~Populatron();

    int processPopulationFile(CSVTron csvtron);
};




#endif /* processPop_h */
