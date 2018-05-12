// Dependencies
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <vector>
# include <numeric>
# include <ctime>
# include <cmath>


// Declare a function to perform multiplication
double
MultiplyBy2(double d_test);


// Define a function to perform multiplication
double
MultiplyBy2(double d_test) {

	/*
	inputs--

	d_test :
		The input to be mult by 2
	*/

	/*
	outputs--

	d_ans (implicit) :
		The output of multiplication
	*/

	return 2*d_test;

}


// Declare a function to perform multiplication
double
MultiplyBy3(double d_test);


// Define a function to perform multiplication
double
MultiplyBy3(double d_test) {

	/*
	inputs--

	d_test :
		The input to be mult by 3
	*/

	/*
	outputs--

	d_ans (implicit) :
		The output of multiplication
	*/

	return 3*d_test;

}


// Declare a function to perform maths
double
DoMathematicalOperation(std::function<double(double)> fn_, double d_); // This is the datatype of the function which is to be sent to the input


// Define a function to perform maths
double
DoMathematicalOperation(std::function<double(double)> fn_, double d_) { // This is the datatype of the function which is to be sent to the input

	/*
	inputs--

	fn_ :
		The function with inputs as single double argument and producing single double output
	d_ :
		The double operand
	*/

	/*
	outputs--

	d_ans (implicit) :
		The application of the function onto the input : fn_(d_)
	*/

	return fn_(d_);

} 


// Declare a simple function that tells if an integer is odd or not
bool
IsOdd(int n_);


// Define a simple function that tells if an integer is odd or not
bool
IsOdd(int n_) {

	/*
	inputs--

	n_ :
		The integer to be tested
	*/

	/*
	outputs--

	b_ (implicit) :
		true/false as per n_ is odd/even
	*/

	return (n_%2 == 1);

}


// Declare a function that retains odd entries
std::vector<int>
GetVectorOfEntriesFromInputVectorByFunction(std::vector<int> vec_n_, std::function<bool(int)> fn_);


// Define a function that retains odd entries
std::vector<int>
GetVectorOfEntriesFromInputVectorByFunction(std::vector<int> vec_n_, std::function<bool(int)> fn_) {

	/*
	inputs--

	vec_n_ :
		The input vector
	*/

	/*
	outputs--

	vec_n_out :
		The output vector of filtered entries
	*/

	std::vector<int> vec_n_out;

	for (auto x : vec_n_) {
		if(fn_(x)) { // Apply filter
			vec_n_out.push_back(x);
		}	
	}

	return vec_n_out;

}


// Declare a function that checks instance of a char input and increments a variable
void
GetCoinTossCount(char ch_, int& n_count_H, int& n_count_T);


// Define a function that checks instance of a char input and increments a variable
void
GetCoinTossCount(char ch_, int& n_count_H, int& n_count_T) {

	/*
	inputs--

	ch_ :
		The character 'H' or 'T'
	*/

	switch (ch_) {

		case 'H' : 
		case 'h' :
			n_count_H++;
			break;

		case 'T' : 
		case 't' :
			n_count_T++;
			break;

		default :
			std::cout << "[ERROR] Unexpected character input." << std::endl;

	}

}


// Main
int 
main(int argc, char const *argv[]) {

	// Use function as variables
	auto fn_multiply_by_2 = MultiplyBy2;
	auto fn_multiply_by_3 = MultiplyBy3;
	std::cout << "10*2 = " << fn_multiply_by_2(10) << std::endl;
	std::cout << "10*2 = " << DoMathematicalOperation(fn_multiply_by_2, 10) << std::endl;

	// Vector of functions
	std::vector<std::function<double(double)> > vec_fn_; // The space in the closing triangular braces is compulsory!!
	vec_fn_.push_back(fn_multiply_by_3);
	vec_fn_.push_back(fn_multiply_by_2);
	std::cout << "10*3 = " << vec_fn_[0](10) << std::endl;
	std::cout << "(10*2)*2 = " << vec_fn_[1](vec_fn_[1](10)) << std::endl;
	
	/*
	This approach allows to filter a list based on a boolean generator function
	*/
	// Filter a list by passing a generic function
	std::function<bool(int)> fn_ = IsOdd;
	std::vector<int> vec_n_1;
	// for (int n_i = 0; n_i < 10; n_i ++) {
	// 	vec_n_1.push_back(n_i);
	// }
	// Set seed
	srand(time(NULL));
	for (int n_i = 0; n_i < 10; n_i ++) {
		vec_n_1.push_back(std::rand()%(10000 + 1));
	}
	std::cout << "Original Vector : \n";
	for (auto x : vec_n_1) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;
	vec_n_1 = GetVectorOfEntriesFromInputVectorByFunction(vec_n_1, fn_);
	std::cout << "Filtered Vector : \n";
	for (auto x : vec_n_1) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;

	// Generate 100 heads or tails
	std::vector<char> vec_ch_;
	for (int n_i = 0; n_i < 88; n_i ++) {
		vec_ch_.push_back((std::rand()%2 == 0) ? 'H' : 'T');
	}
	int n_count_H = 0, n_count_T = 0;
	std::function<void(char, int&, int&)> fn_1;
	for (auto x : vec_ch_) {
		GetCoinTossCount(x, n_count_H, n_count_T);
	}
	std::cout << "Original H/T Vector : \n";
	for (auto x : vec_ch_) {
		std::cout << x <<  " ";
	}
	std::cout << std::endl;
	std::cout << "Number of H : " << n_count_H << std::endl;
	std::cout << "Number of T : " << n_count_T << std::endl;




	return 0;
}