// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <numeric>
# include <sstream>
# include <ctime> // Number of seconds passed since Jan 1, 1970


// Function declaration 
std::vector<int> 
GetRange(int n_start, int n_end, int n_jump);// Can actually be returned


// Function definition
std::vector<int>
GetRange(int n_start, int n_end, int n_jump) {
	
	std::vector<int> vec_n_range;
	
	while(n_start <= n_end) {
		vec_n_range.push_back(n_start);
		n_start += n_jump;
	}
	
	return vec_n_range;
}


// Main function
int 
main(int argc, char const **argv) {
	
	int i_1 = 0; // For while loop, no in-loop variables
	while (i_1 <= 20) {
		if (i_1%2 == 0) {
			i_1 += 1; // Increment is to be incorporated properly
			continue;
		}
		else {
			std::cout << "Next odd number from 0 to 20 : " <<  i_1 << std::endl;
			i_1 += 1;
		}
	}

	i_1 = 0; // If we hit 7, come out of the loop
	while (i_1 <= 20) {
		if (i_1%2 == 0) {
			i_1 += 1; // Increment is to be incorporated properly
			continue;
		}
		else {
			std::cout << "Next odd number from 0 to 20 : " <<  i_1 << std::endl;
			if (i_1 == 7) {
				std::cout << "7 discovered. Coming out of the loop!" << std::endl;
				break; // Comes out of the innermost loop in which the break is sitting
			}
			i_1 += 1;
		}
	}

	// Drawing patterns example
	int n_row = 88, n_curr_row = 88; // Set to maximum value!
	// std::string st_q_1("Please enter the number of rows : \n");
	// std::cout << st_q_1;
	// std::cin >> n_row; // No problem in reading a single int, as it is one word (without spaces)
	n_curr_row = n_row;
	while (n_curr_row > 0) {
		for (int i = 0; i < n_curr_row - 1; i++) {
			std::cout << " ";
		}
		for (int i = 0; i < 2*(n_row - n_curr_row) + 1; i++) {
			std::cout << "*";
		}
		for (int i = 0; i < n_curr_row - 1; i++) {
			std::cout << " ";
		}
		std::cout << std::endl;
		n_curr_row -= 1;
	}

	// // Exception handling
	// double d_num_1, d_num_2;
	// std::cout << "Enter number 1 : \n";
	// std::cin >> d_num_1;
	// std::cout << "Enter number 2 : \n";
	// std::cin >> d_num_2;
	// try {
	// 	if (d_num_2 == 0) {
	// 		throw "[ERROR] The denominator d_num_2 is 0.\n"; // Throw errors as and when they come!
	// 		std::cout << "The control DOES NOT reach here!\n";
	// 	}
	// 	else {
	// 		printf("%0.2f / %0.2f = %0.2f\n", d_num_1, d_num_2, d_num_1/d_num_2);
	// 	}
	// }
	// catch (const char *e){ // Catch the thrown error and do stuff with them. The catch type MUST be const
	// 	std::cout << e;
	// }

	// // Runtime error
	// try {
	// 	std::cout << "Generating an exception : \n";
	// 	throw std::runtime_error("Error is thrown\n");
	// 	std::cout << "The control DOES reach here!\n";
	// }
	// catch (std::exception e) { // std::exception is th standard exception from which all other exceptions are built
	// 	std::cout << "Exception handled : " << e.what() << std::endl;
	// }

	// Do-while loop
	srand(time(NULL)); // Set seed for random number generation
	int n_secret = std::rand() % 11 ; // Get a random number from 0 to 10, both inclusive
	int n_guess = 0;
	std::string st_q_2("Make a guess : \n");
	do {
		std::cout << st_q_2;
		std::cin >> n_guess;
		if (n_guess > n_secret) {
			std::cout << "The guess is way too big!!\n";
		}
		else if (n_guess < n_secret) {
			std::cout << "The guess is way too small!!\n";
		}
	} while(n_guess != n_secret);
	std::cout << "You guessed it correctly!! The secret is : " << n_secret << std::endl;

	// Example to emulate do-while using while. Standard way is given below
	while (1) { // Set infinite loop
		std::cout << st_q_2;
		std::cin >> n_guess;
		if (n_guess > n_secret) {
			std::cout << "The guess is way too big!!\n";
		}
		else if (n_guess < n_secret) {
			std::cout << "The guess is way too small!!\n";
		}
		if (n_guess == n_secret) {
			break;
		}
	}
	std::cout << "You guessed it correctly!! The secret is : " << n_secret << std::endl;

	return 0;
}