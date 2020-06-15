#include "Header.h"

int main()
{
	
		MSI PG = read();
		MSI::iterator IMSI = PG.begin();
		if (IMSI->first.size() == 0)
			throw std::runtime_error("empty, change the file");
		bool tus = true;
		std::cout << "ZODIS              | PASIKARTOJA" << std::endl;
		for (const auto& x : PG)
		{
			tus = false;
			std::cout << x.first;
			for (int i = 0; i < 20 - x.first.size(); i++)
			{
				std::cout << " ";
			}
			std::cout <<x.second.size() << " kartus eilutese ";
			for (const auto& a : x.second)
			{
				std::cout << a << " ";
			}
			std::cout << std::endl;
			
		}
		
		std::cout << "URL: " << std::endl;
		vector<std::string> URL;
		std::ifstream fin("notepad.txt");
		std::string lin;
		for (unsigned int i = 0; !fin.eof(); i++)
		{
			std::getline(fin, lin, '\n');
				std::regex self_regex("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
				std::sregex_iterator regex_it(lin.begin(), lin.end(), self_regex);
				std::sregex_iterator regex_end;
				while (regex_it != regex_end)
				{
					std::smatch match = *regex_it;
					if (match.str() != "")
						URL.push_back(match.str());
					regex_it++;
				}	
		}
		if (URL.empty())
		{
			std::cout << "no URL" << std::endl;
		}
		else
		{
			for (const auto& url : URL)
			{
				std::cout << url << std::endl;
			}
		}
	
}
