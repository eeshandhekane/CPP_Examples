// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <numeric>
# include <cmath>
# include <ctime>


// Declare the function to generate a vector of random values
std::vector<int>
GetRangedRandomIntegers(int n_min, int n_max, int n_count);


// Declare the in-place bubble sort function
void
BubbleSort(std::vector<int>& vec_n_num, bool b_increasing); // This means that vec_n_num is passed, but by reference!! This is not entire description, but good enough for now


// Declare recursive factorial function
long long int
RecursiveFactorial(int n_num);


// Declare a function to print an array in a good-looking format
void
DrawArray(std::vector<int> vec_n_num);


// Declare a function to compute the n-th Fibonacci number in a recursive manner
long long int 
RecursiveFibonacci(int n_ind);


// Declare a function to compute the area of a circle
double
GetArea(double d_rad);


// Declare a function to compute the area of a circle
double
GetArea(double d_length, double d_breadth); // Overloaded function with different inputs but the same name and possibly the same output type


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


// Declare the in-place bubble sort function
void
BubbleSort(std::vector<int>& vec_n_num, bool b_increasing) {

	 /*
	inputs--

	vec_n_num (by reference) :
		The vector to be sorted
	b_increasing :
		true if increasing order, else false
	 */

	/*
	outputs--
	*/

	int n_size = vec_n_num.size();
	int n_temp;

	for (int i = n_size - 1; i > 0 ; i --) {
		
		// std::cout << "####################################################################################################" << std::endl;
		// std::cout << "[DEBUG] Checking for maximum at " << i + 1 << "-th location : " << std::endl;
		// std::cout << "####################################################################################################" << std::endl;
		for (int j = 0; j < i; j ++) {
		
			// std::cout << "[DEBUG] Compare : " << vec_n_num[j] << " and " << vec_n_num[j + 1] << std::endl; 
		
			// Cater for increasing sort
			if (b_increasing) {
				if (vec_n_num[j] > vec_n_num[j + 1]) {
					// std::cout << "[DEBUG] Swap : " << vec_n_num[j] << " and " << vec_n_num[j + 1] << std::endl;
					n_temp = vec_n_num[j];
					vec_n_num[j] = vec_n_num[j + 1];
					vec_n_num[j + 1] = n_temp;
				}
				else {
					// std::cout << "[DEBUG] DON'T Swap : " << vec_n_num[j] << " and " << vec_n_num[j + 1] << std::endl;
				}
			}
		
			// Cater for decreasing sort
			else {
				if (vec_n_num[j] < vec_n_num[j + 1]) {
					// std::cout << "[DEBUG] Swap : " << vec_n_num[j] << " and " << vec_n_num[j + 1] << std::endl;
					n_temp = vec_n_num[j];
					vec_n_num[j] = vec_n_num[j + 1];
					vec_n_num[j + 1] = n_temp;
				}
			else {
					// std::cout << "[DEBUG] DON'T Swap : " << vec_n_num[j] << " and " << vec_n_num[j + 1] << std::endl;
				}
			}
		
			// // Display partial progress
			// std::cout << "[DEBUG] Partial Sort : " << std::endl;
			// for (auto x : vec_n_num ) {
			// 	std::cout << x << " " ;
			// }
			// std::cout << std::endl;

		}
	}

}


// Define recursive factorial function
long long int
RecursiveFactorial(int n_num) {
	
	/*
	inputs--

	n_num :
		The number whose factorial needs to be evaluated
	*/

	/*
	outputs--

	lln_factorial :
		The factorial of n_num
	*/

	/*
	Recursive definition :
	RecursiveFactorial(n) = 1 if n <= 1
	RecursiveFactorial(n) = n*RecursiveFactorial(n - 1) otherwise
	*/

	if (n_num < 2) {
		return 1;
	}
	else {
		return n_num*RecursiveFactorial(n_num - 1);
	}

}


// Define a function to print an array in a good-looking format
void
DrawArray(std::vector<int> vec_n_num) {

	/*
	inputs--

	vec_n_num :
		The vector which needs to be printed in a good-looking manner
	*/

	/*
	outupts--
	*/

	int n_size = vec_n_num.size();

	// Get the number of places each of the ints needs to consume
	int n_max_digits = 0;
	for (int n_x : vec_n_num) {

		// Get absolute
		if (n_x < 0) {
			n_x *= -1;
		}

		int n_digit = 1;
		int n_upper_limit = 10;
		while (n_x >= n_upper_limit) {
			n_digit += 1;
			n_upper_limit *= 10;
		}

		if (n_digit > n_max_digits) {
			n_max_digits = n_digit;
		}

	}

	// (n + 1) walls + n*(n_max_digits + 2) locations for #
	for (int i = 0; i < (n_size + 1) + n_size*(n_max_digits + 2); i ++) {
		std::cout << "-";
	}
	std::cout << std::endl;

	// Print the row of indices
	for (int i = 0; i < n_size; i ++) {

		std::cout << "| " ; // The starting column

		// Get number of digits of i
		int n_digit = 1;
		int n_upper_limit = 10;
		while (i >= n_upper_limit) {
			n_digit += 1;
			n_upper_limit *= 10;
		}

		for (int j = 0; j < n_max_digits - n_digit; j ++) {
			std::cout << " " ; // The white spaces
		}
		std::cout << i << " " ;
	}
	std::cout << "|\n";

	// (n + 1) walls + n*(n_max_digits + 2) locations for #
	for (int i = 0; i < (n_size + 1) + n_size*(n_max_digits + 2); i ++) {
		std::cout << "-";
	}
	std::cout << std::endl;

	// Print the row of values
	for (int i = 0; i < n_size; i ++) {

		std::cout << "| " ; // The starting column

		// Get number of digits of i
		int n_digit = 1;
		int n_upper_limit = 10;
		while (vec_n_num[i] >= n_upper_limit) {
			n_digit += 1;
			n_upper_limit *= 10;
		}

		for (int j = 0; j < n_max_digits - n_digit; j ++) {
			std::cout << " " ; // The white spaces
		}
		std::cout << vec_n_num[i] << " " ;
	}
	std::cout << "|\n";

	// (n + 1) walls + n*(n_max_digits + 2) locations for #
	for (int i = 0; i < (n_size + 1) + n_size*(n_max_digits + 2); i ++) {
		std::cout << "-";
	}
	std::cout << std::endl;

}


// Define a function to compute the n-th Fibonacci number in a recursive manner
long long int 
RecursiveFibonacci(int n_ind) {

	/*
	inputs--

	n_ind :
		Index of the desired Fibonacci number
	*/

	/*
	outputs--

	lld_fib :
		The Fibonacci number
	*/

	long long int lld_fib;

	if ((n_ind == 1) || (n_ind == 2)) {
		return (long long int)1;
	}
	else {
		return RecursiveFibonacci(n_ind - 1) + RecursiveFibonacci(n_ind - 2);
	}

	return lld_fib;

}


// Define a function to compute the area of a circle
double
GetArea(double d_rad) {

	/*
	inputs--

	d_rad :
		The radius of the circle
	*/

	/*
	outputs--

	d_area (computed implicitly) : 
		Area of the circle
	*/

	return 3.14159265358979323846*std::pow(d_rad, 2);
}


// Define a function to compute the area of a circle
double
GetArea(double d_length, double d_breadth) {

	/*
	inputs--

	d_length :
		The length of the rectangle
	d_breadth :
		The breadth of the rectangle
	*/

	/*
	outputs--

	d_area (computed implicitly) :
		Area of the rectangle
	*/	

	return d_length*d_breadth;
}


// Main
int 
main(int argc, char const *argv[])
{
	
	// Test : BubbleSort
	std::vector<int> vec_n_num = GetRangedRandomIntegers(0, 10, 30);
	std::cout << "Original vector : \n";
	for (auto x: vec_n_num) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;
	BubbleSort(vec_n_num, false);
	// Print the sorted vector (in-place sorted)
	std::cout << "Sorted (Decreasing) vector : \n";
	for (auto x: vec_n_num) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;
	BubbleSort(vec_n_num, true);
	// Print the sorted vector (in-place sorted)
	std::cout << "Sorted (Increasing) vector : \n";
	for (auto x: vec_n_num) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;

	// Test : RecursiveFactorial
	int n_test = 10;
	// std::string st_q_1("Please enter an integer whose factorial needs to be evaluated : \n");
	// std::cout << st_q_1;
	// std::cin >> n_test;
	std::cout << "The factorial of " << n_test << " is : " << RecursiveFactorial(n_test) << std::endl;

	// Test : DrawArray
	std::vector<int> vec_n_arr = GetRangedRandomIntegers(0, 10, 25);
	DrawArray(vec_n_arr);

	// Test : RecursiveFibonacci
	int n_fib = 20;
	// std::string st_q_2("Please enter the index of Fibonacci number : \n");
	// std::cout << st_q_2;
	// std::cin >> n_fib;
	std::cout << "The " << n_fib << "-th Fibonacci number is : " << RecursiveFibonacci(n_fib) << std::endl; 

	// Test : GetArea
	char ch_fig;
	std::cout << "Please enter (R/r) to compute the area of a rectangle and (C/c) to compute that of a circle : \n";
	std::cin >> ch_fig;

	switch (ch_fig) {

		case 'R' :
		case 'r' :
			std::cout << "Please enter the length of the rectangle : \n";
			double d_l;
			std::cin >> d_l;
			std::cout << "Please enter the breadth of the rectangle : \n";
			double d_b;
			std::cin >> d_b;
			std::cout << "The area of the rectangle is : " << GetArea(d_l, d_b) << std::endl;
			break;

		case 'C' :
		case 'c' :
			std::cout << "Please enter the radius of the circle : \n";
			double d_r;
			std::cin >> d_r;
			std::cout << "The area of the circle is : " << GetArea(d_r) << std::endl;
			break;

		default :
			std::cout << "You have entered the wrong key.\nTerminating the program ...\n";
			break;
	}


	return 0;
}