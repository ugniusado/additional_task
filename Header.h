#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <regex>
#include <exception>
#include <string>
#include <vector>
#include <sstream>
using std::vector;
using std::map;
typedef map<std::string, vector<unsigned int>> MSI;
typedef MSI::iterator IMSI;
std::string line;
std::string word;
std::ifstream fin;
MSI read();
bool check(MSI& msg, std::string& w);
MSI read()
{   MSI PG;
    fin.open("notepad.txt");
    for(unsigned int i=0; !fin.eof(); i++)
    {
        std::getline(fin,line,'\n');
		
        std::regex self_regex("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
        line = std::regex_replace(line, self_regex," ");
        std::transform(line.begin(),line.end(),line.begin(),::tolower);
        MSI::iterator IMSI = PG.begin();
        while (IMSI != PG.end())
        {
            if (IMSI->first == word)
            {
                IMSI->second.push_back(i + 1);
                break;
            }
		++IMSI;
        }
        std::regex regx("\\W");
        line = std::regex_replace(line,regx," ");
        std::stringstream StringBuffer(line);
        while(StringBuffer >> word)
        {
            if(!check(PG,word))
            {
                vector<unsigned int> init{1};
                PG.insert(MSI::value_type(word,init));
            }
            else
            {
            	MSI::iterator IMSI = PG.begin();
                while (IMSI != PG.end())
                {
                    if (IMSI->first == word)
                    {
                    IMSI->second.push_back(i + i);
                    break;
                    }
                IMSI++;
                }
            }
        }
        line.clear();
    }
	fin.close();
    return PG;
}
bool check(MSI& msg, std::string& w)
{
	MSI::iterator IMSI = msg.begin();
	while (IMSI != msg.end())
	{
		if (IMSI->first == w)
			return true;
		IMSI++;
	}
	return false;
}