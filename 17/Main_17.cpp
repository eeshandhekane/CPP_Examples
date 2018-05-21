// Dependencies
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <ctime>
# include <cmath>
# include <numeric>
# include <vector> // Sequential container vector
# include <deque> // Sequential container deque
# include <list> // Sequential container list
# include <forward_list> // Sequential container forward list


// Declare a function to return bool true if num is 2 or 3
bool
Is2Or3(int num);


// Define a function to return bool true if num is 2 or 3
bool
Is2Or3(int num) {

	/*
	inputs--

	num :
		The number which is to be checked
	*/

	/*
	outputs--

	is_2_or_3 (implicit) :
		Whether the number is 2 or 3
	*/
	return ((num == 2) || (num == 3));
}


// Main
int 
main(int argc, char const *argv[]) {
	
	/*
	Sequential containers--

	Contain ordered data. Include vectors, deques, lists and forward lists.
	*/

	/*
	Deque--

	It is a dynamic array, like vector.
	However, unlike vector, it allows for insertion and deletion from the front and from the back
	*/

	// Create a deque and push
	std::deque<int> deq_1(5); // Initialize a deque of size 5 with all 0's
	deq_1.push_back(2);
	deq_1.push_back(3);
	deq_1.push_front(1);
	deq_1.push_front(0);
	// deq_1.assign({11,12}); NOT AVAILABLE
	std::cout << "####################################################################################################" << std::endl;
	for (auto x : deq_1) {
		std::cout << "[INFO] Next entry of deque deq_1 : " << x << std::endl;
	}
	// Length
	std::cout << "[INFO] The size of the vector is : " << deq_1.size() << std::endl;
	// Indexed access
	std::cout << "####################################################################################################" << std::endl;
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1[i] << std::endl;	
	}
	// Access using 'at'
	std::cout << "####################################################################################################" << std::endl;
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	// Create iterator over the deque. We can add an entry at specific index using this iterator
	std::cout << "####################################################################################################" << std::endl;
	std::deque<int>::iterator itr_deq_1 = deq_1.begin() + 2; // Second location from beginning
	deq_1.insert(itr_deq_1, 7); // Add entry '7' at that location.
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	// Insertion using arrays
	std::cout << "####################################################################################################" << std::endl;
	int arr_n_rand[] = {11, 12, 13, 14, 15};
	deq_1.insert(deq_1.end(), arr_n_rand, arr_n_rand + 4); // Add first 4 entries of the array at the end of the deque
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	// Deletion
	std::cout << "####################################################################################################" << std::endl;
	deq_1.erase(deq_1.end()); 
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	std::cout << "####################################################################################################" << std::endl;
	deq_1.erase(deq_1.begin());
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	// The location can be specified using an iterator as well!
	std::cout << "####################################################################################################" << std::endl;
	// The iterator is AT index 2. We make it go 5 more indices to the right
	itr_deq_1 += 5; 
	deq_1.erase(itr_deq_1);
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	} // TRICK : The iterator is 7 places away from the beginning of the CURRENT DEQUE! (Not the one before the deletion and insertion operations!!)
	std::deque<int>::iterator itr_deq_2 = deq_1.end() - 3; // Three places from behind
	deq_1.insert(itr_deq_2, 343);
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	deq_1.push_back(1234);
	std::cout << "[INFO] TRICK : The iterator was defined to be at 3 places from behind the deq_1. It is now at : " << *itr_deq_2 << std::endl; // iterators are essentially pointer-like objects, so just dereference them to get values!!
	std::cout << "####################################################################################################" << std::endl;
	// Erase from deque in chunk
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	deq_1.erase(deq_1.begin(), deq_1.begin() + 3); // Deletes inclusive of the start and exclusive of the last
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	// Print entry at last
	itr_deq_2 = deq_1.end();
	std::cout << "[INFO] The entry at the last is NOT : " << *itr_deq_2 << std::endl; // NOTE : .end() referes to a location that is not in the deque!!
	std::cout << "[INFO] The entry at the last is : " << *(itr_deq_2 - 1) << std::endl; // NOTE : .end() referes to a location that is not in the deque!!
	std::cout << "####################################################################################################" << std::endl;
	// Push and pop techniques
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	for (int j = 0; j < 4; j++) {
		deq_1.pop_front(); // Remove the entry at the front end!
	}
	std::cout << "##################################################" << std::endl;
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	deq_1.pop_back(); // Remove the entry at the back end!
	std::cout << "##################################################" << std::endl;
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	// Create deque with count and entry
	std::cout << "####################################################################################################" << std::endl;
	std::deque<int> deq_n_1(2, 2345);
	// Swap values in decks. Contents are swapped
	deq_1.swap(deq_n_1);
	for (int i = 0; i < deq_1.size(); i ++) {
		std::cout << "[INFO] The entry of deq_1 after swapping at index : " << i << " is : " << deq_1.at(i) << std::endl;	
	}
	for (int i = 0; i < deq_n_1.size(); i ++) {
		std::cout << "[INFO] The entry of deq_n_1 after swapping at index : " << i << " is : " << deq_n_1.at(i) << std::endl;	
	}
	// Clear a deque
	deq_n_1.clear();
	std::cout << "##################################################" << std::endl;
	for (int i = 0; i < deq_n_1.size(); i ++) {
		std::cout << "[INFO] The entry of deq_n_1 after swapping at index : " << i << " is : " << deq_n_1.at(i) << std::endl;	
	} // NOTHING WILL BE PRINTED
	std::cout << "##################################################" << std::endl;

	/*
	Lists--

	Lists are good for insertion, extraction and moving, so far!
	Lack the ability to directly access elements
	*/

	std::cout << "\n\n####################################################################################################" << std::endl;
	int arr_n_1[5] = {34, 45}; // First entry 34, next 45 and rest 0
	for (int i = 0; i < 5; i ++) {
		std::cout << "[INFO] The entry of array arr_n_1 at index : " << i << " is : " << arr_n_1[i] << std::endl;
	}
	// Add values from array to list
	std::list<int> list_n_1;
	list_n_1.insert(list_n_1.begin(), arr_n_1, arr_n_1 + 3); // Add first 3 entries of the array to the list
	std::cout << "[INFO] The list list_n_1 has size : " << list_n_1.size() << std::endl;
	// for (int i = 0; i < list_n_1.size(); i ++) {
	// 	std::cout << "[INFO] The entry of list list_n_1 at index : " << i << " is " << list_n_1[i] << std::endl;
	// } // BAD!! Lists do not support subscripts. We get error-- error: type 'std::list<...>' does not provide a subscript operator
	// list_n_1.assign({123, 234, 345}); // Not supported in my laptop
	std::list<int>::iterator itr_list_n_1 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size() ; i ++) {
		std::cout << "[INFO] The next entry at index : " << i << " of the list is : " << *itr_list_n_1 << std::endl;
		// itr_list_n_1 += 1; BAD!! NOT SUPPORTED!!
		itr_list_n_1 ++;
	}
	for (int i = list_n_1.size() - 1; i >= 0 ; i --) {
		itr_list_n_1 --; // To start with, list_n_1.end() was the location of itr_list_n_1. We need to decrement first and then print
		std::cout << "[INFO] REVERSE :: The next entry at index : " << i << " of the list is : " << *itr_list_n_1 << std::endl;
		
	}
	// std::list<int>::iterator itr_list_n_2 = list_n_1.begin() + 2; // BAD!! Even this is not supported!! We get error-- error: invalid operands to binary expression ('iterator' (aka '__list_iterator<int, void *>') and 'int')
	std::list<int>::iterator itr_list_n_2 = list_n_1.begin();
	// We traverse using advance function, i.e., do ++ thing!!
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] Print using advancing ::  The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Put value of 23456 at last location
	std::list<int>::iterator itr_list_n_3 = list_n_1.end();
	list_n_1.insert(itr_list_n_3, 23456);
	std::cout << "####################################################################################################" << std::endl;
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] Print using advancing ::  The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Negative advance
	for (int i = list_n_1.size() - 1; i >= 0 ; i --) {
		std::advance(itr_list_n_2, -1);
		std::cout << "[INFO] REVERSE :: Print using negative advancing ::  The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
	}
	// Indexed insert and indexed delete
	std::cout << "####################################################################################################" << std::endl;
	itr_list_n_2 = list_n_1.begin();
	std::advance(itr_list_n_2, 2); // Advance two locations using iterator. Go to location and add entry
	list_n_1.insert(itr_list_n_2, 987);
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] Print using advancing ::  The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	itr_list_n_2 = list_n_1.end(); // Using an iterator, go to a location and erase the entry!
	// list_n_1.erase(itr_list_n_2); // TRICK : We need to erase at the location one prior to the end
	list_n_1.erase(--itr_list_n_2); // TRICK : We need to erase at the location one prior to the end. --itr_list_n_2 signifies that first decrement and then erase
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] Print using advancing ::  The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// After erase, where am I??
	std::cout << "[INFO] After erase, the entry at the location is : " << *itr_list_n_2 << std::endl; // TRICK : THIS GIVES A TRASH VALUE!
	std::cout << "[INFO] After erase, the last entry at the location is : " << *(--itr_list_n_2) << std::endl;
	std::cout << "[INFO] After erase, the second last entry at the location is : " << *(--itr_list_n_2) << std::endl;
	// Erasing in chunks
	std::list<int>::iterator itr_list_n_4 = list_n_1.begin();
	std::list<int>::iterator itr_list_n_5 = list_n_1.begin();
	for (int i = 0; i < 3; i ++) {
		std::advance(itr_list_n_5, 1); // Incrememnt thrice. TO KILL FIRST 3 ELEMENTS
	}
	list_n_1.erase(itr_list_n_4, itr_list_n_5);
	std::cout << "####################################################################################################" << std::endl;
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Push and pop from front and back
	list_n_1.push_back(1);
	list_n_1.push_back(4);
	list_n_1.push_back(9);
	list_n_1.push_back(16);
	list_n_1.push_front(-1);
	std::cout << "####################################################################################################" << std::endl;
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	list_n_1.pop_front();
	list_n_1.pop_back();
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Create list from array with repeated entries
	int arr_n_2[6] = {2, 1, 1, 4, 3, 4};
	std::list<int> list_n_2;
	list_n_2.insert(list_n_2.begin(), arr_n_2, arr_n_2 + 6); // Add all 6 entries
	std::cout << "####################################################################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}	
	// Sort
	list_n_2.sort();
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] SORT :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Reverse
	list_n_2.reverse();
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] REVERSE :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Get unique entries. All repeated entries are permanently removed
	int arr_n_3[6] = {2, 1, 1, 4, 3, 4};
	list_n_2.insert(list_n_2.begin(), arr_n_3, arr_n_3 + 6);
	list_n_2.unique();
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] REVERSE :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	} // TRICKY! The output is shown below. Only the consecutive repeated entries are removed!!
	// [INFO] REVERSE :: The next entry at index : 0 of the list is : 2
	// [INFO] REVERSE :: The next entry at index : 1 of the list is : 1
	// [INFO] REVERSE :: The next entry at index : 2 of the list is : 4
	// [INFO] REVERSE :: The next entry at index : 3 of the list is : 3
	// [INFO] REVERSE :: The next entry at index : 4 of the list is : 4
	// [INFO] REVERSE :: The next entry at index : 5 of the list is : 3
	// [INFO] REVERSE :: The next entry at index : 6 of the list is : 2
	// [INFO] REVERSE :: The next entry at index : 7 of the list is : 1
	// // SORT AND UNIQUE FOR REMOVING ALL REPEATED INSTANCES
	// list_n_2.sort(); 
	// list_n_2.unique();
	// std::cout << "##################################################" << std::endl;
	// itr_list_n_2 = list_n_2.begin();
	// for (int i = 0; i < list_n_2.size(); i ++) {
	// 	std::cout << "[INFO] REVERSE :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
	// 	std::advance(itr_list_n_2, 1);
	// }
	// Remove all instances
	list_n_2.remove(4); // Remove all instances of 4
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] REMOVE 4 :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Remove based on condition
	list_n_2.remove_if(Is2Or3); // Remove a num if it is 2 or 3
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] REMOVE 4 :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	// Merging
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] LIST 1 :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] LIST 2 :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	list_n_1.merge(list_n_2);
	itr_list_n_2 = list_n_1.begin();
	for (int i = 0; i < list_n_1.size(); i ++) {
		std::cout << "[INFO] LIST 1 :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	}
	std::cout << "##################################################" << std::endl;
	itr_list_n_2 = list_n_2.begin();
	for (int i = 0; i < list_n_2.size(); i ++) {
		std::cout << "[INFO] LIST 2 :: The next entry at index : " << i << " of the list is : " << *itr_list_n_2 << std::endl;
		std::advance(itr_list_n_2, 1);
	} // After merging the argument list vanishes!!
	std::cout << "##################################################" << std::endl;

	/*
	Forward lists--

	Each item has link ONLY to the member that succeeds it and not to the member that proceeds it.
	We can move forward, but never backwards.
	*/

	std::forward_list<float> fw_list_f_1;
	// fw_list_f_1.assign({1.0, 2.0, -3.0}); // NOT SUPPORTED IN MY LAPTOP
	// Only front is accessible! Not the back. 
	for (float i = 0; i < 10; i++) {
		fw_list_f_1.push_front((float)(i+1)*(i+1) + 2*i); // Entry at front is 10^2 + 2*9
	}
	std::cout << "\n\n####################################################################################################" << std::endl;
	// for (int i = 0; i < 10; i ++) {
	// 	std::cout << "[INFO] The next entry in the forward list at index : " << i << " is : " << fw_list_f_1[i] << std::endl;
	// } BAD!! Indexing is not supported and we get the error-- error: type 'std::forward_list<...>' does not provide a subscript operator
	// To access the list, we need to create an iterator
	// std::cout << "[INFO] The forward list has size : " << fw_list_f_1.size() << std::endl; // BAD!! EVEN THIS IS NOT SUPPORTED! error: no member named 'size' in 'std::__1::forward_list<..., std::__1::allocator<...> >'
	std::cout << "[INFO] The forward list has first entry : " << *fw_list_f_1.begin() << std::endl;
	std::cout << "[INFO] The forward list has first entry : " << fw_list_f_1.front() << std::endl;
	// Pop from front 
	fw_list_f_1.pop_front();
	std::cout << "[INFO] The forward list has first entry : " << *fw_list_f_1.begin() << std::endl; // (8+1)^2 + 2*8 = 97
	// Print all!!
	// std::forward_list<float>::iterator itr_fw_list_f_minus_1 = fw_list_f_1.end(); // WOW!!
	// std::forward_list<float>::iterator itr_fw_list_f_0 = fw_list_f_1.end();
	// for (int i = 0; itr_fw_list_f_minus_1 < itr_fw_list_f_0; i ++) {
	// 	std::cout << "[INFO] The forward list entry at index : " << i << " is : " << *itr_fw_list_f_0 << std::endl;
	// 	itr_fw_list_f_0++;
	// } // THIS DID NOT WORK FOR SOME REASON
	std::cout << "##################################################" << std::endl;
	int n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	// Insert at location
	std::cout << "##################################################" << std::endl;
	std::forward_list<float>::iterator itr_fw_list_f_1 = fw_list_f_1.begin();
	itr_fw_list_f_1++;
	itr_fw_list_f_1++; // A way to increment the iterator
	std::advance(itr_fw_list_f_1, 1);
	itr_fw_list_f_1 = fw_list_f_1.insert_after(itr_fw_list_f_1, 12345); // Insert the entry at the location 
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	std::cout << "[INFO] After incrememnt, iterator at : " << *itr_fw_list_f_1 << std::endl;
	std::cout << "##################################################" << std::endl;
	itr_fw_list_f_1 = fw_list_f_1.erase_after(itr_fw_list_f_1); // BE CAREFUL AS TO WHAT IT PRINTS!!
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	std::cout << "[INFO] After incrememnt, iterator at : " << *itr_fw_list_f_1 << std::endl;
	// Value removal
	fw_list_f_1.remove(12345);
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] REMOVEDD 12345 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	fw_list_f_1.push_front(2);
	fw_list_f_1.push_front(2);
	fw_list_f_1.push_front(2);
	fw_list_f_1.push_front(3);
	fw_list_f_1.push_front(3);
	fw_list_f_1.push_front(2);
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] ADDING MULTIPLE 2'S AND 3'S :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	fw_list_f_1.remove_if(Is2Or3);
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] REMOVING MULTIPLE 2'S AND 3'S :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	// Get unique
	fw_list_f_1.push_front(2);
	fw_list_f_1.push_front(2);
	fw_list_f_1.push_front(2);
	fw_list_f_1.push_front(3);
	fw_list_f_1.push_front(3);
	fw_list_f_1.push_front(2);
	// fw_list_f_1.unique();
	// std::cout << "##################################################" << std::endl;
	// n_1 = 0;
	// for (auto x : fw_list_f_1) {
	// 	std::cout << "[INFO] ADDED MULTIPLE 2'S AND 3'S + UNIQUES :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
	// 	n_1 ++;
	// } // TRICK! The uniques are removed from successive pairs only!!
	// Sort
	fw_list_f_1.sort();
	// Reverse
	fw_list_f_1.reverse();
	// uniques
	fw_list_f_1.unique();
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] SORT + REVERSE + UNIQUE :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	// Create new forward list
	std::forward_list<float> fw_list_f_2;
	fw_list_f_2.push_front(2);
	fw_list_f_2.push_front(2);
	fw_list_f_2.push_front(2);
	fw_list_f_2.push_front(3);
	fw_list_f_2.push_front(3);
	fw_list_f_2.push_front(2);
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] FORWARD LIST 1 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_2) {
		std::cout << "[INFO] FORWARD LIST 2 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	// Merge
	fw_list_f_2.merge(fw_list_f_1);
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] FORWARD LIST 1 MERGED INTO FORWARD LIST 2 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	} // Vanishes after merging into list 2
	std::cout << "##################################################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_2) {
		std::cout << "[INFO] FORWARD LIST 1 MERGED INTO FORWARD LIST 2 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}
	// Clearing!!
	fw_list_f_2.clear();
	std::cout << "####################EVERYTHING VANISHES##############################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_1) {
		std::cout << "[INFO] FORWARD LIST 1 MERGED INTO FORWARD LIST 2 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	} // VEVERYTHING VANISHES!!
	std::cout << "####################EVERYTHING VANISHES##############################" << std::endl;
	n_1 = 0;
	for (auto x : fw_list_f_2) {
		std::cout << "[INFO] FORWARD LIST 1 MERGED INTO FORWARD LIST 2 :: The forward list entry at index : " << n_1 << " is : " << x << std::endl;
		n_1 ++;
	}

	return 0;

}