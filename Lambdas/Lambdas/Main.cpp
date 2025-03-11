#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int>& vals, const std::function<void(int)>& func)
{
	for (int val : vals)
		func(val);
}

int main()
{
	std::vector<int> vals = { 3, 5, 7, 1, 9 };
	int a = 2;

	// in the [] we capture the value outside of the lambda
	// "=" for capturing by value, "&" by reference, etc
	auto lambda = [&](int val) {std::cout << "Val: " << val << a << std::endl; };

	// when passing by value if we want to mutate the value, the syntax is
	auto lambda2 = [=](int val) mutable { a = 4; std::cout << "Val: " << val << a << std::endl; };
	
	// a practical application of using lambdas
	auto it = std::find_if(vals.begin(), vals.end(), [](int val) {return val > 3;}); // getting the first value greater than 3
	std::cout << *it << std::endl;

	ForEach(vals, lambda);
	std::cin.get();
}