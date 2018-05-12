// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <cmath>
# include <ctime>
# include <numeric>


// Declare the function to generate a vector of random values
std::vector<int>
GetRangedRandomIntegers(int n_min, int n_max, int n_count);


// Declare a function to generate the list of first n Fibonacci numbers
std::vector<long long int>
GetFibonacciNumberVetor(int n_range);


// Define the function to generate a vector of random values
std::vector<int>
GetRangedRandomIntegers(int n_min, int n_max, int n_count) {

	/*
	inputs--

	n_min :
		The inclusive min number
	n_max :
		The inclusive max number
	n_count :
		The count of numbers
	*/

	/*
	outputs--

	vec_n_rand :
		The vector of appropriate random numbers
	*/

	std::vector<int> vec_n_rand;
	if (n_min > n_max) {
		return vec_n_rand; 
	}

	int n_rand;

	// Set seed
	srand(time(NULL));

	// Get random numbers one by one
	for (int i = 0; i < n_count ; i++) {
		vec_n_rand.push_back(n_min + (std::rand())%(n_max - n_min + 1));
	}

	return vec_n_rand;
}


// Define a function to generate the list of first n Fibonacci numbers
std::vector<long long int>
GetFibonacciNumberVetor(int n_range) {

	/*
	inputs--

	n_range :
		The number of Fibonacci numbers required
	*/

	/*
	outputs--
	
	vec_lln_fib :
		The vector of first n_range Fibonacci numbers
	*/

	std::vector<long long int> vec_lln_fib;
	if (n_range < 1) {
		return vec_lln_fib;
	}

	int n_f_n_1 = 1;
	vec_lln_fib.push_back(n_f_n_1);
	
	if (n_range == 1) {
		return vec_lln_fib;
	}

	int n_f_n_2 = 1;
	vec_lln_fib.push_back(n_f_n_2);

	if (n_range == 2) {
		return vec_lln_fib;
	}

	int n_ind = 3;
	int n_temp;
	while (n_ind <= n_range) {
		n_temp = n_f_n_2;
		n_f_n_2 = n_f_n_2 + n_f_n_1;
		n_f_n_1 = n_temp;
		vec_lln_fib.push_back(n_f_n_2); // Add updated entry
		n_ind += 1;
	}
	return vec_lln_fib;

}


// Main
int 
main(int argc, char const *argv[])
{

	// Test : std::sort
	std::vector<int> vec_n_1 = GetRangedRandomIntegers(0, 10, 10);
	std::cout << "The original vector : \n"; 
	for (int n_x : vec_n_1) {
		std::cout << n_x << " ";
	}
	std::cout << std::endl;
	// // Sort! 1st arg is reference to begin and 2ndi is the same to the end. The next is the [], which designates a lambda expression (function with no name)
	// std::sort(vec_n_1.begin(), vec_n_1.end(), [](int x, int y){return x < y;}); // Increasing sort. [](<argument_list>){return <bool_processing>}
	// std::sort(vec_n_1.begin(), vec_n_1.end(), [](int x, int y){return x > y;}); // Decreasing sort
	// /*
	// The lambda expressions are introduced in C++11 onwards. If not, you receive error-- "error: expected expression "
	// */
	// std::cout << "The sorted vector : \n"; 
	// for (int n_x : vec_n_1) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;

	// // Test : std::copy_if
	// std::vector<int> vec_n_2 = GetRangedRandomIntegers(0, 10, 10), vec_n_3;
	// std::copy_if(vec_n_2.begin(), vec_n_2.end(), std::back_inserter(vec_n_3), [](int x){return (x%2) == 0;}); 
	// std::cout << "The original vector : \n"; 
	// for (int n_x : vec_n_2) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "The even value vector : \n"; 
	// for (int n_x : vec_n_3) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;

	// // Test : std::for_each
	// int sum = 0;
	// std::for_each(vec_n_2.begin(), vec_n_2.end(), [&](int x){sum += x;}); // & allows for capturing all variables by reference in the body of lanbda expression
	// std::cout << "The sum of the entries in vec_n_2 : " << sum << std::endl;

	// // Example : Get entries that are divisible by a fixed divisor
	// int n_divisor;
	// std::string st_q_1("Please enter the divisor that should be used to generate prunned list : \n");
	// std::cout << st_q_1;
	// std::cin >> n_divisor;
	// std::vector<int> vec_n_4 = GetRangedRandomIntegers(0, 10, 10), vec_n_divisor;
	// std::copy_if(vec_n_4.begin(), vec_n_4.end(), std::back_inserter(vec_n_divisor), [n_divisor](int x){return (x%n_divisor == 0;)}); // [n_divisor] is the capture list, allows to bring in outside values to inside the lambda expression
	// std::cout << "The original vector : \n"; 
	// for (int n_x : vec_n_4) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "The vector with entries divisible by divisor = " << n_divisor <<  ": \n"; 
	// for (int n_x : vec_n_divisor) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;

	// // Test : in-place update with for_each
	// std::vector<int> vec_n_5 = GetRangedRandomIntegers(0, 10, 5), vec_n_6;
	// std::for_each(vec_n_5.begin(), vec_n_5.end(), [&](int x){vec_n_6.push_back(2*x)});
	// std::cout << "The original vector : \n"; 
	// for (int n_x : vec_n_5) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "The vector with multiplied entries : \n"; 
	// for (int n_x : vec_n_6) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;

	// // Test : Multiple inputs
	// std::vector<int> vec_n_7 = {1, 23, 5432, 1, 0};
	// std::vector<int> vec_n_8 = {-1324, -3, -5, 41, -0};
	// // This kind of array-like initialization requires c++11. Otherwise, we get an error--
	// // "error: non-aggregate type 'std::vector<int>' cannot be initialized with an initializer list"
	// std::vector<int> vec_n_9;
	// transform(vec_n_7.begin(), vec_n_7.end(), vec_n_8.begin(), vec_n_9.begin(), [](int x, int y){return x + y;});
	// std::cout << "The sum vector : \n"; 
	// for (int n_x : vec_n_9) {
	// 	std::cout << n_x << " ";
	// }
	// std::cout << std::endl;

	// Ternary expressions
	bool b_is_even;
	long long int n_1 = 43525321;
	b_is_even = (n_1%2 == 0) ? true : false;
	std::cout.setf(std::ios::boolalpha); // true/false rather than 1/0
	std::cout << "The integer " << n_1 << " is even : " << b_is_even << std::endl;
	n_1 = 5892532;
	b_is_even = (n_1%2 == 0) ? true : false;
	std::cout.setf(std::ios::boolalpha); // true/false rather than 1/0
	std::cout << "The integer " << n_1 << " is even : " << b_is_even << std::endl;

	// // Fibonacci with lambdas!
	// std::function<int(int)> fn_fib = [&fn_fib](int n){return n < 2 ? n : fn_fib(n - 1) + fn_fib(n - 2);}; // Recursive lambda function
	// std::cout << "10-th Fibonacci number is : " << fn_fib(10) << std::endl;

	// Example : Fibonacci with updating lists
	std::vector<long long int> vec_lln_fib = GetFibonacciNumberVetor(10); // 10 is assumed
	int n_index = 1;
	for (auto x : vec_lln_fib) {
		std::cout << n_index << "-th Fibonacci number : "<< x << "\n" ;
		n_index += 1;
	}

	return 0;

}