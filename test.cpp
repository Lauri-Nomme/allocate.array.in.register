#include <cstdint>
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
	uint8_t a[8];
	uint64_t c = argc;
	(uint64_t&)a = ((((( c) << 16 | c) << 16) | c) << 16) | c;

	++(uint64_t&)a;

	std::cout << std::hex << (uint64_t&)a << std::endl;
}
