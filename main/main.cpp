#include <iostream>
#include <string>
#include <windows.h>

const int DICT_SIZE = 5;

struct Translate {
	std::string word;
	std::string translation;
};

std::string translator(std::string word, Translate dict[])
{
	for (int i = 0; i < DICT_SIZE; i++) {
		if (word == dict[i].word)
			return dict[i].translation;
	}
	return word;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Translate dict[DICT_SIZE] = {{"THIS", "ÝÒÎ"}, {"IS", ""}, {"A", ""}, {"TABLE", "ÑÒÎË"}};
	std::string message, result, tmp;
	std::getline(std::cin, message);
	int start = 0;
	for (int end = 1; end <= message.length(); end++) {
		if ((message[end] == '_') || (end == message.length())) {
			tmp = translator(message.substr(start, end - start), dict);
            std::cout << message.substr(start, end - start) << std::endl;
			if (tmp != "")
				result += (tmp + "_");
			start = end+1;
            end++;
		}
	}
	std::cout << result << "\b \b"<< std::endl;
	return 0;
}