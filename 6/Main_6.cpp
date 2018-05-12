// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <numeric>
# include <cmath>
# include <sstream>


// Declare a function to convert a string sentence into a vector of words
std::vector<std::string> 
StringToVectorOfWords(std::string st_input, char ch_sep);


// Declare a function to convert a vector of strings into a string. Note that the strings and vectors are all passed by references!
std::string 
VectorOfWordsToString(std::vector<std::string> vec_st_words, char ch_sep);


// Declare a function to strip whitespaces at the beginning and the end of a string
std::string
StripInputString(std::string st_input);


// Declare a function to find all the matches of a substring in a string. Return a vector of all indices where a match occurred
std::vector<int>
GetVectorOfMatchIndicesOfSubstringInAString(std::string st_input, std::string st_pattern);


// Declare a function to replace all the occurrences of source pattern by target pattern in input string, in a recursive manner
std::string
ReplaceSourcePatternByTargetPatttern(std::string st_input, std::string st_source, std::string st_target);

// Declare a function to replace all the occurrences of source pattern by target pattern in input string, in a recursive manner
std::string
CaesarCypher(std::string st_input, int n_key, int n_choice);


// Define a function to convert a string sentence into a vector of words
std::vector<std::string>
StringToVectorOfWords(std::string st_input, char ch_sep) {
	
	/*
	inputs--

	st_input :
		Input string to be converted into a vector of individual words
	ch_sep :
		The separator character to do the split of sentence into words
	*/

	/*
	outputs--

	vec_st_words :
		Set of all the word strings in a vector format
	*/

	std::stringstream ss_1(st_input);
	std::string st_a_word;
	std::vector<std::string> vec_st_words;

	// Scan sentence, break on separator and return words
	while(getline(ss_1, st_a_word, ch_sep)) {
		vec_st_words.push_back(st_a_word);
	}

	// Return the vector
	return vec_st_words;

}	


// Define a function to convert a vector of strings into a string
std::string 
VectorOfWordsToString(std::vector<std::string> vec_st_words, char ch_sep) {

	/*
	inputs--

	vec_st_words :
		A vector of strings of individual words that need to be concatenated into a string
	ch_sep :
		The separator to be added to the string
	*/

	/*
	outputs--

	st_sentence :
		The string formed by concatenating all the words passed in the vector and then adding the newline character
	*/

	// Initialize the sentece
	std::string st_sentence = "";

	for (int i = 0; i < vec_st_words.size(); i ++) {
		
		// Add word one-by-one
		st_sentence += vec_st_words[i];
		// If the last word, do not add anything
		if (i + 1 < vec_st_words.size()) {
			st_sentence += ch_sep;
		}

	}

	// Add new-line
	st_sentence += '\n';

	// Return the final sentence
	return st_sentence;

}


// Define a function to strip whitespaces at the beginning and the end of a string
std::string
StripInputString(std::string st_input) {

	/*
	inputs--

	st_input :
		Input string
	*/

	/*
	outputs--

	st_input : 
		The stripped input string
	*/

	std::string st_chars_to_strip = " \t\n\f\r";
	st_input.erase(0, st_input.find_first_not_of(st_chars_to_strip)); // From 0 to the location where the non-whitespace occurs
	st_input.erase(st_input.find_last_not_of(st_chars_to_strip) + 1); // From the last non-whitespace onwards, erase
	
	return st_input;

}


// Define a function to find all the matches of a substring in a string. Return a vector of all indices where a match occurred
std::vector<int>
GetVectorOfMatchIndicesOfSubstringInAString(std::string st_input, std::string st_pattern) {

	/*
	inputs--

	st_input :
		Input string which needs to be scanned
	st_pattern :
		The pattern which needs to be found in the input string
	*/

	/*
	outputs--

	vec_n_ind :
		The array of all match indices
	*/

	std::vector<int> vec_n_ind;

	// Search for match, if not empty, append to the vector and then move forwards (scan from the next position onwards)
	int index = st_input.find(st_pattern, 0); // Starting from 0-th location
	while (index != std::string::npos) {
		vec_n_ind.push_back(index);
		index = st_input.find(st_pattern, index + 1);
	}

	return vec_n_ind;

}


// Define a function to replace all the occurrences of source pattern by target pattern in input string, in a non-overlap manner (Find all instances, then replace by target. NOT DONE-- find an instance, replace and then find another)
std::string
ReplaceSourcePatternByTargetPatttern(std::string st_input, std::string st_source, std::string st_target) {

	/*
	inputs--
	
	st_input :
		The input string
	st_source :
		The source pattern
	st_target :
		The target pattern which needs to replace the source pattern
	*/

	/*
	outputs--

	st_input :
		The string obtained by replacements of source by target
	*/

	// Get all the matching locations
	std::vector<int> vec_n_ind = GetVectorOfMatchIndicesOfSubstringInAString(st_input, st_source);

	if (vec_n_ind.size() > 0) { // If there are matches

		int n_delta_lengths = st_target.size() - st_source.size();
		int n_source_size = st_source.size();
		int n_replace_count = 0;

		for (int i : vec_n_ind) {
			st_input.replace(i + n_replace_count*n_delta_lengths, n_source_size, st_target);
			n_replace_count += 1;
		}
	}

	return st_input;
}


// Declare a function to replace all the occurrences of source pattern by target pattern in input string, in a recursive manner
std::string
CaesarCypher(std::string st_input, int n_key, int n_choice) {

	/*
	inputs--

	st_input :
		The input string given to encode or decode
	n_key :
		The integer key to shift the alphabet for the caesar cypher
	n_choice :
		The integer 0/1 for decoding/encoding the string
	*/

	/*
	outputs--

	st_input :
		The encoded/decoded string, with appropriate key
	*/

	// If the char is an uppercase, lowercase or digit, shift it!!
	int n_shift = n_key;
	if (n_choice == 0) {
		n_shift *= -1;
	}
	int n_diff = 0;

	char ch_i = ' ';

	// For each char :
	for (int i = 0; i < st_input.size(); i ++) {
		ch_i = st_input[i];
		// If a number : 
		if ((ch_i <= '9') && (ch_i >= '0')) {
			n_diff = ch_i - '0' + n_shift;
			while (n_diff < 0) {
				n_diff += '9' - '0' + 1;
			}
			st_input[i] = (n_diff)%('9' - '0' + 1) + '0'; // Note the addition of '9' - '0' + 1 is needed to take care of % of -ve in C++
		}
		else if ((ch_i <= 'z') && (ch_i >= 'a')) {
			n_diff = ch_i - 'a' + n_shift;
			while (n_diff < 0) {
				n_diff += 'z' - 'a' + 1;
			}
			st_input[i] = (n_diff)%('z' - 'a' + 1) + 'a'; // Note how chars can be manipulated like integers
		}
		else if ((ch_i <= 'Z') && (ch_i >= 'A')) {
			n_diff = ch_i - 'A' + n_shift;
			while (n_diff < 0) {
				n_diff += 'Z' - 'A' + 1;
			}
			st_input[i] = (n_diff)%('Z' - 'A' + 1) + 'A';
		}
	}

	return st_input;
}


// Main function
int 
main(int argc, char const *argv[])
{

	// Test : StringToVectorOfWords
	std::string st_1 = "Hi! My Name is Eeshan and I am learning to code in C++";
	char ch_1 = ' ';
	// std::vector<std::string> vec_st_1 = StringToVectorOfWords(st_1, ch_1);
	std::vector<std::string> vec_st_1 = StringToVectorOfWords(st_1, ' ');
	for (std::string st_2 : vec_st_1) {
		std::cout << st_2 << " X ";
	}
	std::cout << std::endl;
	// for (int i = 0; i < vec_st_1.size(); i++) {
	// 	std::cout << vec_st_1[i] << " X ";
	// }
	// std::cout << std::endl;

	// Test : VectorOfWordsToString
	std::vector<std::string> vec_st_2(5);
	for (int i = 0; i < 5; i ++ ) {
		vec_st_2[i] = std::to_string(i*i);
	}
	std::string st_3 = VectorOfWordsToString(vec_st_2, ' ');
	std::cout << "The string formed by the input words is : \n" << st_3;

	// Test : StripInputString
	std::string st_4 = "\n\n\f\r \t asfahsjfkhkajshfkahdfa \n\n\f\r \t ";
	std::string st_5 = StripInputString(st_4);
	std::cout << "Original String : \n" << st_4 << std::endl;
	std::cout << "Stripped String : \n*" << st_5 << "*" << std::endl;

	// Test : GetVectorOfMatchIndicesOfSubstringInAString
	std::string st_6 = "abababa";
	std::string st_7 = "aba";
	std::vector<int> vec_n_1 = GetVectorOfMatchIndicesOfSubstringInAString(st_6, st_7);
	std::cout << "Input String : " << st_6 << std::endl;
	std::cout << "Pattern String : " << st_7 << std::endl;
	for (int i = 0; i < vec_n_1.size(); ++i) {
		std::cout << "Next Match Location : " << vec_n_1[i] << std::endl;
	}

	// Test : ReplaceSourcePatternByTargetPatttern. TRICK example!
	std::string st_8 = "abababa";
	std::string st_9 = "aba";
	std::string st_10 = "aba";
	std::string st_11 = ReplaceSourcePatternByTargetPatttern(st_8, st_9, st_10);
	std::cout << "Input String : " << st_8 << std::endl;
	std::cout << "Source String : " << st_9 << std::endl;
	std::cout << "Pattern String : " << st_10 << std::endl;
	std::cout << "Replaced String : " << st_11 << std::endl; // Carefully note the st_8 and st_11 strings!

	// Char functions
	char ch_A = 'A', ch_a = 'a', ch_9 = '9', ch_bs_n = '\n', ch_bs_r = '\r', ch_bs_f = '\f', ch_bs_t = '\t', ch_sp = ' ';
	std::cout << "####################################################################################################" << std::endl;
	std::cout << ch_A << " is alphanumeric : " << isalnum(ch_A) << std::endl;
	std::cout << ch_a << " is alphanumeric : " << isalnum(ch_a) << std::endl;
	std::cout << ch_9 << " is alphanumeric : " << isalnum(ch_9) << std::endl;
	std::cout << ch_bs_n << " is alphanumeric : " << isalnum(ch_bs_n) << std::endl;
	std::cout << ch_bs_r << " is alphanumeric : " << isalnum(ch_bs_r) << std::endl;
	std::cout << ch_bs_f << " is alphanumeric : " << isalnum(ch_bs_f) << std::endl;
	std::cout << ch_bs_n << " is alphanumeric : " << isalnum(ch_bs_t) << std::endl;
	std::cout << ch_sp << " is alphanumeric : " << isalnum(ch_sp) << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << ch_A << " is alphabet : " << isalpha(ch_A) << std::endl;
	std::cout << ch_a << " is alphabet : " << isalpha(ch_a) << std::endl;
	std::cout << ch_9 << " is alphabet : " << isalpha(ch_9) << std::endl;
	std::cout << ch_bs_n << " is alphabet : " << isalpha(ch_bs_n) << std::endl;
	std::cout << ch_bs_r << " is alphabet : " << isalpha(ch_bs_r) << std::endl;
	std::cout << ch_bs_f << " is alphabet : " << isalpha(ch_bs_f) << std::endl;
	std::cout << ch_bs_n << " is alphabet : " << isalpha(ch_bs_t) << std::endl;
	std::cout << ch_sp << " is alphabet : " << isalpha(ch_sp) << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << ch_A << " is uppercase : " << isupper(ch_A) << std::endl;
	std::cout << ch_a << " is uppercase : " << isupper(ch_a) << std::endl;
	std::cout << ch_9 << " is uppercase : " << isupper(ch_9) << std::endl;
	std::cout << ch_bs_n << " is uppercase : " << isupper(ch_bs_n) << std::endl;
	std::cout << ch_bs_r << " is uppercase : " << isupper(ch_bs_r) << std::endl;
	std::cout << ch_bs_f << " is uppercase : " << isupper(ch_bs_f) << std::endl;
	std::cout << ch_bs_n << " is uppercase : " << isupper(ch_bs_t) << std::endl;
	std::cout << ch_sp << " is uppercase : " << isupper(ch_sp) << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << ch_A << " is lowercase : " << islower(ch_A) << std::endl;
	std::cout << ch_a << " is lowercase : " << islower(ch_a) << std::endl;
	std::cout << ch_9 << " is lowercase : " << islower(ch_9) << std::endl;
	std::cout << ch_bs_n << " is lowercase : " << islower(ch_bs_n) << std::endl;
	std::cout << ch_bs_r << " is lowercase : " << islower(ch_bs_r) << std::endl;
	std::cout << ch_bs_f << " is lowercase : " << islower(ch_bs_f) << std::endl;
	std::cout << ch_bs_n << " is lowercase : " << islower(ch_bs_t) << std::endl;
	std::cout << ch_sp << " is lowercase : " << islower(ch_sp) << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << ch_A << " is digit : " << isdigit(ch_A) << std::endl;
	std::cout << ch_a << " is digit : " << isdigit(ch_a) << std::endl;
	std::cout << ch_9 << " is digit : " << isdigit(ch_9) << std::endl;
	std::cout << ch_bs_n << " is digit : " << isdigit(ch_bs_n) << std::endl;
	std::cout << ch_bs_r << " is digit : " << isdigit(ch_bs_r) << std::endl;
	std::cout << ch_bs_f << " is digit : " << isdigit(ch_bs_f) << std::endl;
	std::cout << ch_bs_n << " is digit : " << isdigit(ch_bs_t) << std::endl;
	std::cout << ch_sp << " is digit : " << isdigit(ch_sp) << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << ch_A << " is space : " << isspace(ch_A) << std::endl;
	std::cout << ch_a << " is space : " << isspace(ch_a) << std::endl;
	std::cout << ch_9 << " is space : " << isspace(ch_9) << std::endl;
	std::cout << ch_bs_n << " is space : " << isspace(ch_bs_n) << std::endl;
	std::cout << ch_bs_r << " is space : " << isspace(ch_bs_r) << std::endl;
	std::cout << ch_bs_f << " is space : " << isspace(ch_bs_f) << std::endl;
	std::cout << ch_bs_n << " is space : " << isspace(ch_bs_t) << std::endl;
	std::cout << ch_sp << " is space : " << isspace(ch_sp) << std::endl;
	std::cout << "####################################################################################################" << std::endl;

	// Test : CaesarCypher
	std::string st_input;
	std::string st_enc_dec_key;
	std::string st_key;
	std::string st_output;
	std::string st_question_1("Please input a string to encrypt/decrypt : \n");
	std::cout << st_question_1;
	getline(std::cin, st_input);
	std::string st_question_2("Please input 1 if you wish to encode the string and 0 if you wish to decode the string : \n");
	std::cout << st_question_2;
	getline(std::cin, st_enc_dec_key);
	int n_choice = std::stoi(st_enc_dec_key);
	if ((n_choice != 1) && (n_choice != 0)) {
		std::cout << "[ERROR] You entered a wrong option.\nTerminating the program ...";
		return 0;
	}
	std::string st_question_3("Please input the integer key to encode/decode the input : \n");
	std::cout << st_question_3;
	getline(std::cin, st_key);
	int n_key = std::stoi(st_key);
	st_output = CaesarCypher(st_input, n_key, n_choice);
	if (n_choice == 0) {
			std::cout << "The input string given to decode is : \n" << st_input << std::endl;
			std::cout << "The decoded string is : \n" << st_output << std::endl;
			std::cout << "[DEBUG] The input string is NOT changed in place : \n" << st_input << std::endl;
	}
	else {
			std::cout << "The input string given to encode is : \n" << st_input << std::endl;
			std::cout << "The encoded string is : \n" << st_output << std::endl;
			std::cout << "[DEBUG] The input string is NOT changed in place : \n" << st_input << std::endl;
	}


	return 0;
}