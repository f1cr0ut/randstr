#include<iostream>
#include<random>
#include<cstdlib>
#include<string>
#include<cctype>

int main(int argc, char ** argv) {
	if(argc != 2) {
		std::cerr << "argv[1]: input num" << std::endl;
		return EXIT_SUCCESS;
	}

	auto start = 33;
	auto end = 127;
	auto break_num = end - start;

	// check length of argv[1] without using strlen
	for(int i = 0; i < 3; ++i) {
		if(argv[1][i] == '\0') {
			break;
		}
		if(i == 2 || std::isdigit(argv[1][i]) == false) {
			std::cerr << "invalid argument: argv[1] is over than 100" << std::endl;
			return EXIT_FAILURE;
		}
	}

	int num = 0;
	std::sscanf(argv[1], "%2d", &num);
	if(num < 0 || num > break_num) {
		std::cerr << "invalid argument: argv[1] < 0 or length is over " << break_num << std::endl;
		return EXIT_FAILURE;
	}

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<unsigned char> randnum(start, end);
	std::string result;

	int count = 0;
	while(count < num) {
		auto chr = randnum(mt);
		bool retry = false;
		for(auto & i : result) {
			if(i == chr) {
				retry = true;
				break;
			}
		}
		if(retry) {
			continue;
		}
		result += chr;
		++count;
	}
	std::cout << result << std::endl;
	return EXIT_SUCCESS;
}
