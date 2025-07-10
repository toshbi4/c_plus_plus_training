#include <iostream>

// C - string
#include <cstring>
// C++ - string
#include <string>
// algorithms
#include <algorithm>
// sstream
#include <sstream>

void c_string()
{
	// C - string
	const char* msg1 = "Hello";
	const char* msg2 = "Hello";
	char msg[std::strlen(msg1) + 1] = {};

	std::cout << msg1 << " len: " << std::strlen(msg1) << std::endl;
	bool equal = std::strcmp(msg1, msg2) == 0;
	std::cout << msg1 << " equal " << msg2 << " " << equal << std::endl;
	std::strcpy(msg, msg1);
	std::cout << "After copy msg1 into msg: " << msg1 << " " << msg << std::endl;
}

void c_plus_plus()
{
	// C++ - string
	std::string str = "NewWorld!";
	std::string str2 = str.substr(3, 3);
	std::cout << "substr 3,3 from " << str << " is " << str2 << std::endl;

	size_t pos = str.find("World");
	if (pos != std::string::npos) {
		std::cout << "Found \"World\" in " << str << " in " << pos << std::endl;
	} else {
		std::cout << "Not found \"World\" in " << str << std::endl;
	}

	str.erase(1, 2);
	std::cout << "After erase " << str << std::endl;
	str.insert(6, "Test");
	std::cout << "After insert " << str << std::endl;

	// String to integer and back
	std::string str_num = std::to_string(34);
	int num = stoi(str_num);
	std::cout << "str: " << str_num << " num: " << num << std::endl;
}

void algorithms()
{
	// Algorithms
	std::string str = "NewWorld!";
	std::cout << "==> str: " << str << std::endl;
	std::reverse(str.begin(), str.end());
	std::cout << "==> reverse: " << str << std::endl;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << "==> toupper: " << str << std::endl;
}

void sstream()
{
	// sstream
	std::string ss_string = "123 3.12	123	2Hi!";
	std::istringstream iss {ss_string};
	int i1 {0};
	double d1 {0};
	int i2 {0};
	int i3 {0};
	std::string str1 {};
	iss >> i1 >> d1 >> i2 >> i3 >> str1;

	std::cout << "int 1:    " << i1   << std::endl;
	std::cout << "int 2:    " << i2   << std::endl;
	std::cout << "int 3:    " << i3   << std::endl;
	std::cout << "double 1: " << d1   << std::endl;
	std::cout << "string 1: " << str1 << std::endl;

	std::string text = "This is a test";
	std::istringstream ss(text);

	std::string word;
	while (ss >> word) {
	    std::cout << "Word: " << word << "\n";
	}
}

void test_get_line()
{
	std::string line = "foo,bar,baz";
	std::istringstream ss(line);

	std::string token;
	while (std::getline(ss, token, ',')) {
	    std::cout << "==> Token: " << token << "\n";
	}
}

int main() {

	c_string();
	c_plus_plus();
	algorithms();
	sstream();
	test_get_line();

	return 0;
}
