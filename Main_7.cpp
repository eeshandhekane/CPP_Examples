// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <numeric>
# include <cmath>
# include <ctime> // To generate random numbers


/*
Set default boolean to true or false rather than 0 or 1 :
std::cout.setf(std::ios::boolalpha);
*/


// Declare a function to solve simple linear equations
void
LinearEquationSolver(std::string st_input);


// Declare a function to test if an input number is prime or not
bool
PrimalityTesting(int n_test);


// Declare a function to test if an input number is prime or not
std::vector<int>
GetPrimesUpto(int n_max);


// Declare a function to generate ranged random numbers
std::vector<int> 
GenerateRangedRandomNumbers(int n_min, int n_max, int n_count);


// Define a function to solve simple linear equations
void
LinearEquationSolver(std::string st_input) {

	/*
	inputs--
	
	st_input :
		A string of the form "x + b = c", where b, c are allowed to be any VALID real number
	*/

	/*
	outputs--
	*/

	std::stringstream ss_1(st_input);
	std::string st_a_word = "";
	std::vector<std::string> vec_st_fields;
	char ch_ = ' ';
	while(getline(ss_1, st_a_word, ch_)) {
		vec_st_fields.push_back(st_a_word);
	}

	double n_1 = std::stod(vec_st_fields[2]);
	double n_2 = std::stod(vec_st_fields[4]);

	std::cout << vec_st_fields[0] << " = " << n_2 - n_1 << std::endl;

}


// Define a function to test if an input number is prime or not
bool
PrimalityTesting(int n_test) {

	/*
	inputs--

	n_test :
		The input integer for primality testing. MUST be positive
	*/

	/*
	outputs--
	
	b_test :
		The boolean answer of primality testing
	*/

	for (int i = 2; i <= std::sqrt(n_test); i ++) {
		if (n_test % i == 0) {
			return false;
		}
	}

	if (n_test >= 2) {
		return true;
	}
	else {
		return false;
	}
}


// Define a function to test if an input number is prime or not
std::vector<int>
GetPrimesUpto(int n_max) {

	/*
	inputs--

	n_max :
		The range till which we want to get primes
	*/

	/*
	outputs--

	vec_st_primes :
		Vector of primes till n_max
	*/

	std::vector<int> vec_n_primes;
	bool b_test;

	for (int i = 1; i < n_max; i ++) {
		b_test = PrimalityTesting(i);
		if (b_test) {
			vec_n_primes.push_back(i);
		}
	}

	return vec_n_primes;

}


// Define a function to generate ranged random numbers
std::vector<int> 
GenerateRangedRandomNumbers(int n_min, int n_max, int n_count) {

	/*
	inputs--
	
	n_min :
		The minimum allowed number (inclusive)
	n_max :
		The maximum allowed number (inclusive)
	n_count :
		The count of random numbers
	*/

	/*
	outputs--

	vec_n_rand :
		The vector of ranged random numbers
	*/

	std::vector<int> vec_n_rand;

	if (n_min > n_max) {
		return vec_n_rand;
	}

	int n_rand_val;

	// Generate seed
	srand(time(NULL)); // Based on # of seconds since Jan 1, 1970, generate a random number

	for (int i = 0; i < n_count ; i ++) {
		n_rand_val = std::rand();
		n_rand_val = n_min + n_rand_val % ((n_max + 1) - n_min);
		// std::cout << "[DEBUG] The random normalized value : " << n_rand_val << std::endl;
		vec_n_rand.push_back(n_rand_val);
	}

	return vec_n_rand;
}


// Main 
int 
main(int argc, char const *argv[])
{

	// // Test : LinearEquationSolver
	// std::string st_question_1("Please enter a simple linear equation of the form : x + b = c, where b and c are legit doubles : \n");
	// std::cout << st_question_1;
	// std::string st_eq_1;
	// getline(std::cin, st_eq_1);
	// LinearEquationSolver(st_eq_1);

	// // Test : PrimalityTesting
	// bool b_test = false;
	// std::string st_question_2("Please enter a number to check for primality testing : \n");
	// std::cout << st_question_2;
	// int n_test;
	// std::cin >> n_test;
	// b_test = PrimalityTesting(n_test);
	// std::cout.setf(std::ios::boolalpha); // Set default prime as true/false and not 0/1
	// std::cout << "The entered number : " << n_test << " : has primality : " << b_test << std::endl;

	// // Test : GetPrimesUpto
	// std::string st_question_3("Please enter a number till which we want to get primes : \n");
	// std::cout << st_question_3;
	// int n_max;
	// std::cin >> n_max;
	// std::vector<int> vec_n_primes = GetPrimesUpto(n_max);
	// for (int n_i : vec_n_primes) {
	// 	std::cout << "Next prime less than " << n_max << " : " << n_i << std::endl;
	// }

	// Test : GenerateRangedRandomNumbers
	std::string st_question_4("Please enter the lower limit for generating random numbers (inclusive) : \n");
	std::cout << st_question_4;
	int n_min_; 
	std::cin >> n_min_;
	std::string st_question_5("Please enter the upper limit for generating random numbers (inclusive) : \n");
	std::cout << st_question_5;
	int n_max_; 
	std::cin >> n_max_;
	std::string st_question_6("Please enter the number of random numbers to generate : \n");
	std::cout << st_question_6;
	int n_count_; 
	std::cin >> n_count_;
	std::vector<int> vec_n_rand = GenerateRangedRandomNumbers(n_min_, n_max_, n_count_);
	int n_index = 1;
	for (int i : vec_n_rand) {
		std::cout << n_index<<"-th Random Nnumber : " << i << std::endl;
		n_index += 1;
	}

	return 0;

}