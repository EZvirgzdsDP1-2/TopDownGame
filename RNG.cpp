#include <random>
#include <ctime>


inline namespace randomNGenerator
{
	std::mt19937 rn{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}


int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution nb{ min, max };
	return nb(randomNGenerator::rn);
}
