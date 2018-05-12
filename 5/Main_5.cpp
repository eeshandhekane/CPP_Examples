// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <numeric>
# include <cmath> // For math functions


// Main
int 
main(int argc, char const **argv) {
	
	// Strings
	/*
	C-string is an array of chars with '\0' at end
	C++-string is std::string typed
	*/
	char arr_ch_1[] = {'e', 'e', 's', 'h', 'a', 'n', '\0'}; // \0 is included
	std::cout << "The array of chars has length : " << sizeof(arr_ch_1)/sizeof(arr_ch_1[0]) << std::endl;
	std::cout << "The array of chars has length (each char has size of 1 byte) : " << sizeof(arr_ch_1) << std::endl;

	std::vector<std::string> vec_st_1(10);
	std::string st_0 = "The 0-th string";
	vec_st_1[0] = st_0;
	// Access chars!
	std::cout << "First of string : " << st_0[0] << " or " << st_0.at(0) << " or " << st_0.front() << std::endl;
	std::cout << "Length of string : " << st_0.length() << "\n";
	std::string st_1 = st_0;
	std::cout << "String 1 is assigned value of string 0 as std::string st_1 = st_0 : " << st_1 << std::endl;
	std::string st_2(st_0);
	std::cout << "String 2 is assigned value of string 0 as std::string st_2(st_0): " << st_2 << std::endl;
	// Assign to vector
	vec_st_1[1] = st_1;
	vec_st_1[2] = st_2;
	int i;
	i = 0;
	for (auto j : vec_st_1) {
		std::cout << i << " : " << j << std::endl;
		i += 1;
	}

	// String slicing and manipulations
	std::string st_3(st_0, 5); // Start from 5-th index (6th position!)
	vec_st_1[3] = st_3;
	i = 0;
	for (auto j : vec_st_1) {
		std::cout << i << " : " << j << std::endl;
		i += 1;
	}
	std::string st_4(23, 'e'); // 23 times e
	vec_st_1[4] = st_4;
	i = 0;
	for (auto j : vec_st_1) {
		std::cout << i << " : " << j << std::endl;
		i += 1;
	}
	std::string st_5 = st_0.append("_<-APPENDED_THIS_TO_st_0_TO_GET_st_5"); // 23 times e
	vec_st_1[5] = st_5;
	i = 0;
	for (auto j : vec_st_1) {
		std::cout << i << " : " << j << std::endl;
		i += 1;
	}
	st_0 += "_<-CHANGED_st_0_PERMANENTLY";
	st_0.append(st_0, 2, 3); // Append from 23 to 45 indices
	std::cout << "Changed st_0 : " << st_0 << std::endl; // TRICK : The append skips the whitespaces!
	// st_0.erase(0, st_0.length() - 10); // From beginning to end - 10 entries are deleted
	// std::cout << "Changed st_0 after erase is : " << st_0 << std::endl; // TRICK : LAST 10 chars including the spaces are left

	// Find
	if (st_0.find("PERMANENT") != std::string::npos) { // This means that there is a match. npos is returned when no match	
		std::cout << "First matching index : " << st_0.find("PERMANENT") << std::endl;
	}
	// Get from start and length the substring
	std::cout << "Substring : " << st_0.substr(st_0.find("PERMANENT"), 9) << std::endl;
	// Reverse in place
	reverse(st_0.begin(), st_0.end());
	std::cout << "Reversed : " << st_0 << std::endl;
	reverse(st_0.begin(), st_0.end());
	std::cout << "Original : " << st_0 << std::endl;
	// Transform
	transform(st_0.begin(), st_0.end(), st_0.begin(), ::toupper);
	std::cout << "Upper case (in place) : " << st_0 << std::endl;
	transform(st_0.begin(), st_0.end(), st_0.begin(), ::tolower);
	std::cout << "Lower case (in place) : " << st_0 << std::endl;

	// ASCII 
	/*
	a-z : 97-122
	A-Z : 65-90
	0-9 : 48-57
	*/
	char ch_1 = 'Z';
	int n_1 = ch_1;
	// std::cout << "The typecasted character : " << n_1 << std::endl;
	// for (int i = 0; i < 123; i++) { // 130 -> 256
	// 	ch_1 = i;
	// 	std::cout << i << " : " << ch_1 << std::endl;
	// }

	// String conversion
	std::string st_num = std::to_string(3.56 + 4.59/4*2.2);
	std::cout << "3.56 + 4.59/4*2.2 = " << st_num << std::endl;

	// Example encode :
	std::string st_q("Please enter the string to encode (Preferably all upper case): \n");
	std::cout << st_q;
	std::string st_input = "HAHA_DEFAULT";
	// getline(std::cin, st_input);
	std::string st_enc = "";
	for (char c : st_input) {
		// st_enc += std::to_string((int) c); // Take char c, type cast to int and then add the int as a string to the encoded version
		st_enc += std::to_string((int) c - 23); // Take char c, type cast to int and then add the int as a string to the encoded version. -23 allows for 2 digits numbers only
	}
	std::cout << "The encoded string is : " << st_enc << std::endl; 
	std::string st_input_rec = "";
	std::string st_an_int = "";
	int n_an_int;
	char ch_a_ch;
	for (int i = 0; i < st_enc.length(); i += 2) {
		st_an_int = "";
		st_an_int += st_enc[i];
		st_an_int += st_enc[i + 1];
		n_an_int = std::stoi(st_an_int) ;
		// ch_a_ch = (char) n_an_int; 
		ch_a_ch = (char)(n_an_int + 23); 
		st_input_rec += ch_a_ch; // String can be appended by char
	}
	std::cout << "The decoded string is : " << st_input_rec << std::endl;

	// Math functions
	std::cout << "Absolute(-10) : " << std::abs(-10) << std::endl;
	std::cout << "Max(-343, 7) : " << std::max(-343, 7) << std::endl; // Only for 2 ints
	std::cout << "Min(-343, 7) : " << std::min(-343, 7) << std::endl; // Only for 2 ints
	std::cout << "Max(-343, 7.6) : " << std::fmax(-343, 7.6) << std::endl; 
	std::cout << "Min(-343, 7.6) : " << std::fmin(-343, 7.6) << std::endl; 
	std::cout << "Exponent e^(-3.4) : " << std::exp(-3.4) << std::endl; 
	std::cout << "Exponent 2^(4.0) : " << std::exp2(4.0) << std::endl; 
	std::cout << "Logarithm ln(20.079) : " << std::log(20.079) << std::endl;
	std::cout << "Logarithm log10(1000) : " << std::log10(1000) << std::endl;
	std::cout << "Logarithm log2(1024) : " << std::log2(1024) << std::endl;
	std::cout << "4.3^2.3 : " << std::pow(4.3, 2.3) << std::endl;
	std::cout << "Square root of 16.1 : " << std::sqrt(16.1) << std::endl;
	std::cout << "Cube root of 27.1 : " << std::cbrt(27.1) << std::endl;
	std::cout << "Hypotenuse of right triangle with base sides 3.0, 4.0 : " << std::hypot(3.0, 4.0) << std::endl;
	std::cout << "Ceiling, floor and rounding-off of 1.5 : " << std::ceil(1.5) << " " << std::floor(1.5) << " " << std::round(1.5) << std::endl;
	std::cout << "Ceiling, floor and rounding-off of -1.5 : " << std::ceil(-1.5) << " " << std::floor(-1.5) << " " << std::round(-1.5) << std::endl;
	/*
	Other functions--

	sin, cos, tan, asin, acos, atan, atan2, sinh, cosh, tanh, asinh, acosh, atanh
	*/

	return 0;

}
