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
# include <chrono>
# include <thread>
# include <mutex>


// Define global variables
double d_MAX_POWER_RESERVE = 1000; 
std::mutex mutex_LOCK; // Define a lock to avoid racing and erroneous 
double d_THREAD_TIME = 0;


// To use threads, we need to have global storage points that can be accessed anywhere
std::mutex mutex_PRIME_LOCK;
std::vector<unsigned int> vec_u_n_PRIMES;


// Declare a function to get power!
void 
GetPowerFromReserve(int n_id, double d_power);


// Define a function to get power!
void 
GetPowerFromReserve(int n_id, double d_power) {

	/*
	inputs--

	n_id :
		The thread id
	d_power :
		The amount of the thread power
	*/

	/*
	outputs--
	*/

	/*
	If a thread is getting some power, it should be the only one accessing the reserve!
	If two threads access the reserve simultaneously, the resultant might be that the amount reamining in the reserve is wrong!!
	CAN VIOLATE LAW OF CONSERVATION OF POWER (whatever)!
	*/

	// Lock the reservoir
	std::lock_guard<std::mutex> lock(mutex_LOCK);

	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << "####################################################################################################\n";
	
	 std::cout << "[INFO] The current thread has : \n";
	std::cout << "[INFO]\t\tID\t:" << n_id << std::endl;
	std::cout << "[INFO]\t\tattempted withdrawal amount\t:" << d_power << std::endl;

	// Get current time
	auto time_now = std::chrono::system_clock::now();
	// Convert the time to the one that is readable
	std::time_t time_t_sleep = std::chrono::system_clock::to_time_t(time_now);
	// Convert to time zone
	tm tm_local_time = *localtime(&time_t_sleep); // This makes the thread sleep for some time

	std::cout << "[INFO]\t\tTime\t: " <<  std::ctime(&time_t_sleep);
	std::cout << "[INFO]\t\tMonth\t" << tm_local_time.tm_mon << std::endl;
	std::cout << "[INFO]\t\tDay\t" << tm_local_time.tm_mday << std::endl;
	std::cout << "[INFO]\t\tYear\t" << tm_local_time.tm_year << std::endl;
	std::cout << "[INFO]\t\tHour\t" << tm_local_time.tm_hour << std::endl;
	std::cout << "[INFO]\t\tMinute\t" << tm_local_time.tm_min << std::endl;
	std::cout << "[INFO]\t\tSecond\t" << tm_local_time.tm_sec << std::endl;

	// Check for power reservoir!
	if ((d_MAX_POWER_RESERVE - d_power) >= 0) {
		d_MAX_POWER_RESERVE -= d_power;
		std::cout << "[INFO] Withdrawal of power from the reservoir is SUCCESSFUL!!"<< std::endl;
		std::cout << "[INFO] Current remaining power : " << d_MAX_POWER_RESERVE << std::endl;
	}
	else {
		std::cout << "[INFO] Withdrawal of power from the reservoir is FAILED!!"<< std::endl;
		std::cout << "[INFO] Current remaining power : " << d_MAX_POWER_RESERVE << std::endl;	
	}

	std::cout << "####################################################################################################\n";

	/*
	Another way--

	mutex_LOCK.lock();
	<code_block_to_lock>
	mutex_LOCK.unlock();

	This way is not safe, as it might give erroneous results in the cases of exceptions
	*/

}


// Declare a function to create a ranged random int
int
GetRangedRandomValue(int n_min, int n_max);


// Define a function to create a ranged random int
int
GetRangedRandomValue(int n_min, int n_max) {

	/*
	inputs--

	n_min :
		The minimum value included
	n_max :
		The maximum value excluded
	*/

	/*
	outputs--

	n_rand (implicit) :
		The ranged random value
	*/
	

	// Return the random number
	return (n_min + (rand()%(n_max - n_min)));

}


// Declare a function to get a new thread for time example
void
ExecuteThread(int n_id);


// Define a function to get a new thread for time example
void
ExecuteThread(int n_id) {

	/*
	inputs--

	n_id :
		The id of the thread
	*/

	/*
	outputs--
	*/

	// Get current time
	auto time_now = std::chrono::system_clock::now();
	// Convert the time to the one that is readable
	std::time_t time_t_sleep = std::chrono::system_clock::to_time_t(time_now);
	// Convert to time zone
	tm tm_local_time = *localtime(&time_t_sleep); // This makes the thread sleep for some time

	// Display thread info
	std::cout << "[INFO] The thread (before sleeping) has : " << std::endl;
	std::cout << "[INFO]\t\tID\t: " <<  n_id << "\n";
	std::cout << "[INFO]\t\tTime\t: " <<  std::ctime(&time_t_sleep);
	std::cout << "[INFO]\t\tMonth\t" << tm_local_time.tm_mon << std::endl;
	std::cout << "[INFO]\t\tDay\t" << tm_local_time.tm_mday << std::endl;
	std::cout << "[INFO]\t\tYear\t" << tm_local_time.tm_year << std::endl;
	std::cout << "[INFO]\t\tHour\t" << tm_local_time.tm_hour << std::endl;
	std::cout << "[INFO]\t\tMinute\t" << tm_local_time.tm_min << std::endl;
	std::cout << "[INFO]\t\tSecond\t" << tm_local_time.tm_sec << std::endl;

	/*
	Thread-- block of code that runs simultaneously! 
	Block of code executed at the same time.
	Helps utilize the computation of the system to the fullest
	*/

	// Put the thread to sleep!! (KNOWLEDGE OF OS-RELATED COURSE HELPS!)
	// std::this_thread::sleep_for(std::chrono::seconds(GetRangedRandomValue(1, 4))); // Sleep for time from 1 second and < 4 second
	std::this_thread::sleep_for(std::chrono::seconds(GetRangedRandomValue(0, 2))); // Sleep for time from 0 second and < 2 second
	// Get current time
	time_now = std::chrono::system_clock::now();
	// Convert the time to the one that is readable
	time_t_sleep = std::chrono::system_clock::to_time_t(time_now);
	// Convert to time zone
	tm_local_time = *localtime(&time_t_sleep); // This makes the thread sleep for some time

	// Display thread info
	std::cout << "[INFO] The thread (after sleeping) has : " << std::endl;
	std::cout << "[INFO]\t\tID\t: " <<  n_id << "\n";
	std::cout << "[INFO]\t\tTime\t: " <<  std::ctime(&time_t_sleep);
	std::cout << "[INFO]\t\tMonth\t" << tm_local_time.tm_mon << std::endl;
	std::cout << "[INFO]\t\tDay\t" << tm_local_time.tm_mday << std::endl;
	std::cout << "[INFO]\t\tYear\t" << tm_local_time.tm_year << std::endl;
	std::cout << "[INFO]\t\tHour\t" << tm_local_time.tm_hour << std::endl;
	std::cout << "[INFO]\t\tMinute\t" << tm_local_time.tm_min << std::endl;
	std::cout << "[INFO]\t\tSecond\t" << tm_local_time.tm_sec << std::endl;

}


// Declare a function to calculate primes without threads
void
FindPrimesWithoutThreads(unsigned int u_n_start, unsigned int u_n_end, std::vector<unsigned int>& vec_u_int_);


// Declare a function to calculate primes without threads
void
FindPrimesWithoutThreads(unsigned int u_n_start, unsigned int u_n_end, std::vector<unsigned int>& vec_u_int_) {

	/*
	inputs--

	u_n_start :
		The starting value to search for primes
	u_n_end :
		The ending value to search for primes
	vec_u_int_ (reference) :
		The vector to store primes
	*/

	/*
	outputs--
	*/

	// Scan all the legit integers
	for (unsigned int u_n_i = u_n_start; u_n_i <= u_n_end; u_n_i += 2) {
		// Scan all divisors
		for (unsigned int u_n_j = 2; u_n_j < u_n_i; u_n_j ++) {

			if ((u_n_i % u_n_j) == 0) {
				// Not a prime
				break;
			}
			else if ((u_n_j + 1 == u_n_i)){
				vec_u_int_.push_back(u_n_i);
			}

		}
	}

}


// Declare a function to calculate primes with threads
void
FindPrimesWithThreads(unsigned int u_n_start, unsigned int u_n_end, int n_id);


// Declare a function to calculate primes without threads
void
FindPrimesWithThreads(unsigned int u_n_start, unsigned int u_n_end, int n_id) {

	/*
	inputs--

	u_n_start :
		The starting value to search for primes
	u_n_end :
		The ending value to search for primes
	n_id :
		The id
	*/

	/*
	outputs--
	*/

	// // Lock the reservoir
	// std::lock_guard<std::mutex> lock(mutex_PRIME_LOCK); // LOCKS FOREVER!!!! NOT GOOD!!

	// Scan all the legit integers

	// mutex_PRIME_LOCK.lock();
	// std::cout << "[INFO] New thread spawned : " << n_id << std::endl;
	// mutex_PRIME_LOCK.unlock();

	int n_start_time = clock();

	for (unsigned int u_n_i = u_n_start; u_n_i <= u_n_end; u_n_i += 2) {
		// Scan all divisors
		for (unsigned int u_n_j = 2; u_n_j < u_n_i; u_n_j ++) {

			if ((u_n_i % u_n_j) == 0) {
				// Not a prime
				break;
			}
			else if ((u_n_j + 1 == u_n_i)){
				mutex_PRIME_LOCK.lock();
				vec_u_n_PRIMES.push_back(u_n_i);
				mutex_PRIME_LOCK.unlock();
			}

		}
	}

	int n_end_time = clock();

	mutex_PRIME_LOCK.lock();
		d_THREAD_TIME += (double)(n_end_time - n_start_time)/(CLOCKS_PER_SEC);
	mutex_PRIME_LOCK.unlock();

}


// Main
int
main(int argc, char const *argv[]) {

	// Set the seed
	srand(time(NULL));
	
	// Print the random values
	for (int i = 0; i < 10; i++) {
		std::cout << "The next random value : " << GetRangedRandomValue(0, 10) << std::endl;
	}

	// // Execute function!
	// for (int i = 0; i < 2 ; i++) {
	// 	ExecuteThread(i);
	// }

	// // Create threads
	// std::thread th_1 (ExecuteThread, 1);
	// // Join threads to main after execution. Main waits for threads to stop execution before it does so itself!
	// th_1.join();
	// std::thread th_2 (ExecuteThread, 2);
	// th_2.join();

	// // Create power extracting threads!
	// std::thread arr_th[10];
	// for (int n_i = 0; n_i < 10; n_i ++) {
	// 	arr_th[n_i] = std::thread(GetPowerFromReserve, n_i, GetRangedRandomValue(200, 301)); // Way to instantiate threads in array
	// }
	// for (int n_i = 0; n_i < 10; n_i ++) {
	// 	arr_th[n_i].join();
	// }

	// Calculate prime numbers without threads
	std::vector<unsigned int> vec_u_int_;
	int n_start_time = clock();
	FindPrimesWithoutThreads(1, 1000000, vec_u_int_);
	int n_end_time = clock();
	// for (auto x : vec_u_int_) {
	// 	std::cout << "[INFO] The next prime from " << 1 << " to " << 10000 << " is : " << x << std::endl;
	// }
	std::cout << "[INFO] The execution time for this is : " << (double)(n_end_time - n_start_time)/(CLOCKS_PER_SEC) << std::endl;

	// // Create a pool of threads
	// std::thread arr_th_[10]; // Number of threads must be checked for optimal performance
	// n_start_time = clock();
	// for (int n_i = 0; n_i < 10; n_i ++) {
	// 	arr_th_[n_i] = std::thread(FindPrimesWithThreads, int(1 + n_i*10000), int(10000 + (n_i + 1)*10000), n_i);
	// }
	// for (int n_i = 0; n_i < 10; n_i ++) {
	// 	arr_th_[n_i].join(); // DO NOT FORGET TO JOIN THE THREADS TO THE MAIN'S EXECUTION!
	// }
	// n_end_time = clock();
	// // for (auto x : vec_u_n_PRIMES) {
	// // 	std::cout << "[INFO] The next prime from " << 1 << " to " << 10000 << " is : " << x << std::endl;
	// // }
	// std::cout << "[INFO] The execution time for this is : " << (double)(n_end_time - n_start_time)/(CLOCKS_PER_SEC) << std::endl;
	// // std::cout << "[INFO] The execution time for this is : " << d_THREAD_TIME << std::endl;

	// Choose the number of threads!! Set n_thread_count to divisor of 10000
	int n_thread_count = 5;
	std::vector<std::thread> vec_th_(n_thread_count);
	int n_jump = 1000000/n_thread_count;
	int n_idx = 0;
	n_start_time = clock();
	for (int n_i = 0; n_i < n_thread_count ; n_i ++) {
		vec_th_[n_i] = std::thread(FindPrimesWithThreads, 1 + n_idx*n_jump, n_jump + (n_idx + 1)*n_jump, n_idx);
		n_idx ++;
	}
	for (int n_i = 0; n_i < n_thread_count ; n_i ++) {
		vec_th_[n_i].join();
	}
	n_end_time = clock();
	std::cout << "[INFO] The execution time for this is : " << (double)(n_end_time - n_start_time)/(CLOCKS_PER_SEC) << std::endl;
	std::cout << "[INFO] The execution time for this is : " << d_THREAD_TIME/n_thread_count << std::endl;

	return 0;
}