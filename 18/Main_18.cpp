// Dependencies
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <ctime>
# include <cmath>
# include <numeric>
# include <set>
# include <map>
# include <stack>
# include <queue>


// Main function
int
main(int argc, char const *argv[])
{
	
	/*
	Associative containers--

	They store sorted data. Since the data is sorted, inserting is slower. However, search and retrieval is very fast
	*/

	/*
	Sets--

	Store unique and sorted data
	*/

	// std::set<float> set_f_1 {2, 2, 1, 1, 1, 5, 4, 3}; // This is not allowed in my laptop
	std::set<float> set_f_1;
	std::cout << "[INFO] Set set_f_1 is empty? : " << set_f_1.empty() << std::endl;
	for (int n_i = 0; n_i < 10; n_i ++) {
		for (int n_j = 0; n_j <= n_i; n_j ++) {
			set_f_1.insert(std::sqrt(n_i)); // Insert using .insert(). Repeated instances will be removed
		}
	}
	// Get size
	std::cout << "[INFO] Set set_f_1 has size : " << set_f_1.size() << std::endl;
	// Empty
	std::cout.setf(std::ios::boolalpha); // Set boolean as true or false vs 1 or 0
	std::cout << "[INFO] Set set_f_1 is empty? : " << set_f_1.empty() << std::endl;
	// Access
	int n_index = 0;
	for (auto f_i : set_f_1) {
		std::cout << "[INFO] Next entry at index : " << n_index << " in set_f_1 : " << f_i << std::endl;
		n_index++;
	}
	// // No subsricpt
	// std::cout << "[INFO] 0-th entry : " << set_f_1[0] << std::endl; // We hit the error-- error: type 'std::set<...>' does not provide a subscript operator
	// Accessing using iterator
	std::set<float>::iterator itr_set_f_1;
	itr_set_f_1 = set_f_1.begin();
	for (int n_i = 0; n_i < set_f_1.size(); n_i ++) {
		std::cout << "[INFO] Accessed next entry using iterator is : " << *itr_set_f_1 << std::endl;
		itr_set_f_1++; // Iteartor increment
	}
	std::cout << "[INFO] Garbage value after the iterator leaves the range of set : " << *itr_set_f_1 << std::endl;
	// Delete specific entry
	set_f_1.erase(3.00); // Not same as 3 in our set!! Yet, it will be removed!!
	n_index = 0;
	for (auto f_i : set_f_1) {
		std::cout << "[INFO] Next entry at index : " << n_index << " in set_f_1 : " << f_i << std::endl;
		n_index++;
	}
	itr_set_f_1 = set_f_1.end();
	// Advancing iterators
	std::advance(itr_set_f_1, -2); // Second last from the end
	std::cout << "[INFO] Second last entry : " << *itr_set_f_1 << std::endl;
	// Array based assignments
	float arr_f_1[] = {-1.22, -3, 0.00, 4.32, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1}; // Repeated entries will automatically be removed from set
	set_f_1.insert(arr_f_1 + 1, arr_f_1 + 8); // Out of the 7 entries, add the 2nd to 6th entries into the set
	n_index = 0;
	for (auto f_i : set_f_1) {
		std::cout << "[INFO] Next entry at index : " << n_index << " in set_f_1 : " << f_i << std::endl;
		n_index++;
	}
	// Value searching
	auto f_val_1 = set_f_1.find(1.1);
	std::cout << "[INFO] Value 1.1 found? : " << *f_val_1 << std::endl;
	auto f_val_2 = set_f_1.find(-1342.1);
	std::cout << "[INFO] Value -1324.1 found? : " << *f_val_2 << std::endl; // Returns trash
	// Set lower bound
	auto f_less_than_2_1 = set_f_1.lower_bound(2.1);
	std::cout << "[INFO] 2.1 : " << *f_less_than_2_1 << std::endl; // It returns the entry just above or equal to the lower bound we are checking for
	auto f_less_than_2_5 = set_f_1.upper_bound(2.5);
	std::cout << "[INFO] 2.5 : " << *f_less_than_2_5 << std::endl; // It returns the entry just below or equal to the upper bound we are checking for
	// Swap
	std::set<float> set_f_2;
	set_f_2.insert(1);
	set_f_2.insert(2);
	set_f_1.swap(set_f_2);
	n_index = 0;
	for (auto f_i : set_f_1) {
		std::cout << "[INFO] Next entry in set_f_1 at index : " << n_index << " in set_f_1 : " << f_i << std::endl;
		n_index++;
	}
	n_index = 0;
	for (auto f_i : set_f_2) {
		std::cout << "[INFO] Next entry in set_f_2 at index : " << n_index << " in set_f_1 : " << f_i << std::endl;
		n_index++;
	}

	/*
	Multiset--

	Do all operations of set, plus allow for repeated values
	Below we literally copy the set code, with repeated declarations removed, and run to get the results. Note that repeated instances are maintained!!
	*/

	std::multiset<float> multiset_f_1;
	std::cout << "[INFO] multiset multiset_f_1 is empty? : " << multiset_f_1.empty() << std::endl;
	for (int n_i = 0; n_i < 10; n_i ++) {
		for (int n_j = 0; n_j <= n_i; n_j ++) {
			multiset_f_1.insert(std::sqrt(n_i)); // Insert using .insert(). Repeated instances will be removed
		}
	}
	// Get size
	std::cout << "[INFO] multiset multiset_f_1 has size : " << multiset_f_1.size() << std::endl;
	// Empty
	std::cout << "[INFO] multiset multiset_f_1 is empty? : " << multiset_f_1.empty() << std::endl;
	// Access
	for (auto f_i : multiset_f_1) {
		std::cout << "[INFO] Next entry at index : " << n_index << " in multiset_f_1 : " << f_i << std::endl;
		n_index++;
	}
	// // No subsricpt
	// std::cout << "[INFO] 0-th entry : " << multiset_f_1[0] << std::endl; // We hit the error-- error: type 'std::multiset<...>' does not provide a subscript operator
	// Accessing using iterator
	std::multiset<float>::iterator itr_multiset_f_1;
	itr_multiset_f_1 = multiset_f_1.begin();
	for (int n_i = 0; n_i < multiset_f_1.size(); n_i ++) {
		std::cout << "[INFO] Accessed next entry using iterator is : " << *itr_multiset_f_1 << std::endl;
		itr_multiset_f_1++; // Iteartor increment
	}
	std::cout << "[INFO] Garbage value after the iterator leaves the range of multiset : " << *itr_multiset_f_1 << std::endl;
	// Delete specific entry
	multiset_f_1.erase(3.00); // Not same as 3 in our multiset!! Yet, it will be removed!!
	n_index = 0;
	for (auto f_i : multiset_f_1) {
		std::cout << "[INFO] Next entry at index : " << n_index << " in multiset_f_1 : " << f_i << std::endl;
		n_index++;
	}
	itr_multiset_f_1 = multiset_f_1.end();
	// Advancing iterators
	std::advance(itr_multiset_f_1, -2); // Second last from the end
	std::cout << "[INFO] Second last entry : " << *itr_multiset_f_1 << std::endl;
	// Array based assignments
	multiset_f_1.insert(arr_f_1 + 1, arr_f_1 + 8); // Out of the 7 entries, add the 2nd to 6th entries into the multiset
	n_index = 0;
	for (auto f_i : multiset_f_1) {
		std::cout << "[INFO] Next entry at index : " << n_index << " in multiset_f_1 : " << f_i << std::endl;
		n_index++;
	}
	// Value searching
	f_val_1 = multiset_f_1.find(1.1);
	std::cout << "[INFO] Value 1.1 found? : " << *f_val_1 << std::endl;
	f_val_2 = multiset_f_1.find(-1342.1);
	std::cout << "[INFO] Value -1324.1 found? : " << *f_val_2 << std::endl; // Returns trash
	// multiset lower bound
	f_less_than_2_1 = multiset_f_1.lower_bound(2.1);
	std::cout << "[INFO] 2.1 : " << *f_less_than_2_1 << std::endl; // It returns the entry just above or equal to the lower bound we are checking for
	f_less_than_2_5 = multiset_f_1.upper_bound(2.5);
	std::cout << "[INFO] 2.5 : " << *f_less_than_2_5 << std::endl; // It returns the entry just below or equal to the upper bound we are checking for
	// Swap
	std::multiset<float> multiset_f_2;
	multiset_f_2.insert(1);
	multiset_f_2.insert(2);
	multiset_f_1.swap(multiset_f_2);
	n_index = 0;
	for (auto f_i : multiset_f_1) {
		std::cout << "[INFO] Next entry in multiset_f_1 at index : " << n_index << " in multiset_f_1 : " << f_i << std::endl;
		n_index++;
	}
	n_index = 0;
	for (auto f_i : multiset_f_2) {
		std::cout << "[INFO] Next entry in multiset_f_2 at index : " << n_index << " in multiset_f_1 : " << f_i << std::endl;
		n_index++;
	}
	std::cout << "##################################################" << std::endl;
	n_index = 0;
	for (auto f_i : multiset_f_2) {
		std::cout << "[INFO] Next entry in multiset_f_2 at index : " << n_index << " in multiset_f_2 : " << f_i << std::endl;
		n_index++;
	}
	multiset_f_2.erase(1.1); // ALL 1.1 instances are removed
	std::cout << "##################################################" << std::endl;
	n_index = 0;
	for (auto f_i : multiset_f_2) {
		std::cout << "[INFO] Next entry in multiset_f_2 after removing 1.1 at index : " << n_index << " in multiset_f_2 : " << f_i << std::endl;
		n_index++;
	}

	/*
	Maps--

	Stores key value pairs, with NO DUPLICATE KEYS
	*/
	std::map<int, float> map_n_to_float_1;
	// We need to add std::pair instances
	for (int n_i = 0; n_i < 10; n_i ++) {
		map_n_to_float_1.insert(std::pair<int, float> (n_i, (float)std::sqrt(n_i)));
	}
	// // Access via auto
	// for (auto x : map_n_to_float_1) {
	// 	std::cout << "[INFO] Next entry in map : " << x << std::endl; // NOT ALLOWED!!
	// } // NOT ALLOWED!!
	// Access via auto
	for (auto x : map_n_to_float_1) {
		std::cout << "[INFO] Next entry in map : (" << x.first << ", " << x.second << ")" << std::endl;
	}
	std::map<int, float>::iterator itr_map_n_to_float_1;
	itr_map_n_to_float_1 = map_n_to_float_1.begin();
	// Size 
	std::cout << "[INFO] The size of the map : " << map_n_to_float_1.size() << std::endl; // GIVES 0!!
	// For access, use iterators!!
	n_index = 0;
	for (; itr_map_n_to_float_1 != map_n_to_float_1.end(); itr_map_n_to_float_1 ++) {
		std::cout << "[INFO] Next entry in map at index : " << n_index << " is : (KEY : " << itr_map_n_to_float_1->first << " , VALUE : " << itr_map_n_to_float_1->second << ")" << std::endl; // NOT ALLOWED!!
		n_index++;
	}
	// Find using key
	auto match = map_n_to_float_1.find(3);
	std::cout << "[INFO] KEY = 3 => VALUE : " << match->second << std::endl;
	match = map_n_to_float_1.find(-3);
	std::cout << "[INFO] KEY = -3 => VALUE : " << match->second << std::endl; // RETURNS TRASH!!

	/*
	Multimaps--

	Stores key value pairs. It can have multiple keys as long as values are different!!
	*/
	std::multimap<int, float> multimap_n_to_float_1;
	// We need to add std::pair instances
	for (int n_i = 0; n_i < 10; n_i ++) {
		multimap_n_to_float_1.insert(std::pair<int, float> (n_i, (float)std::sqrt(n_i)));
		multimap_n_to_float_1.insert(std::pair<int, float> (n_i, (float)std::cbrt(n_i)));
	}
	// // Access via auto
	// for (auto x : multimap_n_to_float_1) {
	// 	std::cout << "[INFO] Next entry in multimap : " << x << std::endl; // NOT ALLOWED!!
	// } // NOT ALLOWED!!
	// Access via auto
	for (auto x : multimap_n_to_float_1) {
		std::cout << "[INFO] Next entry in multimap : (" << x.first << ", " << x.second << ")" << std::endl;
	}
	std::multimap<int, float>::iterator itr_multimap_n_to_float_1;
	itr_multimap_n_to_float_1 = multimap_n_to_float_1.begin();
	// Size 
	std::cout << "[INFO] The size of the multimap : " << multimap_n_to_float_1.size() << std::endl; // GIVES 0!!
	// For access, use iterators!!
	n_index = 0;
	for (; itr_multimap_n_to_float_1 != multimap_n_to_float_1.end(); itr_multimap_n_to_float_1 ++) {
		std::cout << "[INFO] Next entry in multimap at index : " << n_index << " is : (KEY : " << itr_multimap_n_to_float_1->first << " , VALUE : " << itr_multimap_n_to_float_1->second << ")" << std::endl; // NOT ALLOWED!!
		n_index++;
	}
	// Find using key
	match = multimap_n_to_float_1.find(3);
	std::cout << "[INFO] KEY = 3 => VALUE : " << match->second << std::endl; // No repeated values corresponding to the repeated keys!!
	match = multimap_n_to_float_1.find(-3);
	std::cout << "[INFO] KEY = -3 => VALUE : " << match->second << std::endl; // RETURNS TRASH!!

	/*
	Container adapters--

	Containers. Provide defined interface for storing data. 
	*/

	/*
	Stacks--

	Stores data in last in last in first out format
	*/

	std::stack<std::string> stack_st_names;
	stack_st_names.push("Eeshan");
	stack_st_names.push("Eeshan1");
	stack_st_names.push("Eeshan2");
	stack_st_names.push("Gunesh");
	stack_st_names.push("Dhekane");
	// Size
	std::cout << "##################################################" << std::endl;
	std::cout << "[INFO] The size of the stack : " << stack_st_names.size() <<std::endl;
	// Empty check
	std::cout << "[INFO] Is the stack empty? : " << stack_st_names.empty() <<std::endl;
	// // Access. Subscript not allowed!!!!
	// for (int n_i = 0; n_i < stack_st_names.size(); n_i ++) {
	// 	std::cout << "[INFO] Next entry at index : " << n_i << " is : " << stack_st_names[n_i] << std::endl; // NOT ALLOWED!! We hot the error-- type <...> does not provide a subscript operator
	// }
	// Top
	std::cout << "[INFO] The top of the stack : " << stack_st_names.top() << std::endl;
	// Access must be pop-based!!
	while (!stack_st_names.empty()) {
		std::cout << "[INFO] The entry at the top : " << stack_st_names.top() << std::endl;
		stack_st_names.pop();
	}

	/*
	Queues--

	Stores data in last in first in first out format
	*/

	std::queue<std::string> queue_st_names;
	queue_st_names.push("Eeshan");
	queue_st_names.push("Eeshan1");
	queue_st_names.push("Eeshan2");
	queue_st_names.push("Gunesh");
	queue_st_names.push("Dhekane");
	// Size
	std::cout << "##################################################" << std::endl;
	std::cout << "[INFO] The size of the queue : " << queue_st_names.size() <<std::endl;
	// Empty check
	std::cout << "[INFO] Is the queue empty? : " << queue_st_names.empty() <<std::endl;
	// // Access. Subscript not allowed!!!!
	// for (int n_i = 0; n_i < queue_st_names.size(); n_i ++) {
	// 	std::cout << "[INFO] Next entry at index : " << n_i << " is : " << queue_st_names[n_i] << std::endl; // NOT ALLOWED!! We hot the error-- type <...> does not provide a subscript operator
	// }
	// Front
	std::cout << "[INFO] The top of the queue : " << queue_st_names.front() << std::endl;
	// Access must be pop-based!!
	while (!queue_st_names.empty()) {
		std::cout << "[INFO] The entry at the top : " << queue_st_names.front() << std::endl;
		queue_st_names.pop();
	}

	/*
	Priority queue--

	Elements are organized with largest priority first
	*/
	std::priority_queue<float> pr_queue_f_names;
	pr_queue_f_names.push(4.3);
	pr_queue_f_names.push(-3.4);
	pr_queue_f_names.push(4.4);
	// Size
	std::cout << "##################################################" << std::endl;
	std::cout << "[INFO] The size of the priority queue : " << pr_queue_f_names.size() <<std::endl;
	// Empty check
	std::cout << "[INFO] Is the priority queue empty? : " << pr_queue_f_names.empty() <<std::endl;
	// Top
	std::cout << "[INFO] The top of the priority queue : " << pr_queue_f_names.top() << std::endl;
	// Access must be pop-based!!
	while (!pr_queue_f_names.empty()) {
		std::cout << "[INFO] The entry at the top : " << pr_queue_f_names.top() << std::endl;
		pr_queue_f_names.pop();
	}

	/*
	Enums--

	Custom datatypes. Assigns names to constant ints
	*/

	// std::cout << "##################################################" << std::endl;
	// enum enum_days{
	// 	Monday = 1, Tuesday = 3, Wednesday, Thursday, Friday,  Saturday, Sunday = -1
	// };
	// enum enum_days a_day = Wednesday;
	// std::cout << "[INFO] Enum day Wednesday : " << a_day << std::endl; // 4
	// a_day = Thursday;
	// std::cout << "[INFO] Enum day Thursday : " << a_day << std::endl; // 4
	// // Scan
	// for (int n_i = Monday; n_i < Sunday; n_i ++) {
	// 	std::cout << "[INFO] Next day : " << n_i << std::endl;
	// } // NOTHING IS PRINTED BECAUSE Sunday = -1 makes the condition of the loop false!!
	enum enum_days_{
		Monday = 1, Tuesday = 3, Wednesday, Thursday, Friday,  Saturday, Sunday
	};
	enum enum_days_ a_day = Wednesday;
	std::cout << "[INFO] Enum day Wednesday : " << a_day << std::endl; // 4
	a_day = Thursday;
	std::cout << "[INFO] Enum day Thursday : " << a_day << std::endl; // 4
	// Scan
	for (int n_i = Monday; n_i < Sunday; n_i ++) {
		std::cout << "[INFO] Next day : " << n_i << std::endl;
	} // NOTHING IS PRINTED BECAUSE Sunday = -1 makes the condition of the loop false!!

	return 0;
}