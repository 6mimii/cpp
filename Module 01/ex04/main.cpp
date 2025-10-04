#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char *av[])
{
	if (ac != 4) {
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile)
	{
		std::cerr << "Error: cannot open file " << av[1] << std::endl;
		return 1;
	}
	std::string content;
	std::string line;
	while(std::getline(infile, line))
	{
		content += line;
		content += '\n';
	}
	infile.close();

	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string result;
	size_t pos = 0;
	size_t found;
	while((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	std::string outfilename = std::string(av[1]) + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile)
	{
		std::cerr << "Error: cannot create file " << outfilename << std::endl;
		return 1;
	}
	outfile << result;
	outfile.close();
}
