// Dependencies
# include <cstdlib>
# include <iostream>
# include <string>
# include <vector>
# include <cmath>
# include <math.h>
# include <ctime>
# include <numeric>
# include <sstream>


// Class definition
class anAnimal {

	// Create private variables : Accessible inside of class, i.e. can be accessed only by an instance
	private : // private attributes can ONLY be accessed by the class itself, not even by any subclass
	// protected : // // protected attributes can be accessed by the class itself and by any subclass
		
		std::string st_name;
		
		double d_height;
		
		double d_weight;
		
		// Static variable : shared across all the instances of a class
		static int n_num_of_animals; // Utility of the class, can not be counted by each instance

	// Create public variables : Accessible anywhere, by anything calling it
	public :
		
		// Getter for name
		std::string
		GetName() {

			/*
			inputs--
			*/

			/*
			outputs--

			st_name :
				The name of the dog
			*/

			return st_name;
		}
		
		// Setter for name
		void 
		SetName(std::string st_n) {

			/*
			inputs--


			st_n :
				The name of the dog
			*/

			/*
			outputs--
			*/

			this->st_name = st_n; // Refer to all object instances by using "this". "this" is the pointer to the instance
		}

		// Getter for height
		double
		GetHeight() {

			/*
			inputs--
			*/

			/*
			outputs--

			d_height :
				The height of the dog
			*/

			return this->d_height;
		}

		// Setter for height
		void
		SetHeight(double d_h) {

			/*
			inputs--

			d_h :
				The height of the dog
			*/

			/*
			outputs--
			*/

			this->d_height = d_h;
		}

		// Getter for weight
		double
		GetWeight() {

			/*
			inputs--
			*/

			/*
			outputs--

			d_weight :
				The weight of the dog
			*/

			return this->d_weight;
		}

		// Setter for weight
		void
		SetWeight(double d_w) {

			/*
			inputs--

			d_w :
				The weight of the dog
			*/

			/*
			outputs--
			*/

			this->d_weight = d_w;
		}

		// Declare a function to set all entities at the same time
		void 
		SetAllAttributes(std::string, double, double);

		// Declare a constructor
		anAnimal(std::string, double, double);

		// Declare overloaded constructor
		anAnimal();

		// Declare a deconstructor : called when an instance is deleted or no-longer used
		~anAnimal(); // Could and should create custom deconstructors to care for memory

		// Static methods can access statics fields ONLY!!
		static int 
		GetNumOfAnimal() {
			return n_num_of_animals; // "this->n_num_of_animals" does not work here!
		}

		// Declare a function to print the instances
		void
		PrintInstanceOfAnAnimal();

};


// Initialize the static private variable
int anAnimal::n_num_of_animals = 0;


// Define a function to set all entities at the same time
void 
anAnimal::SetAllAttributes(std::string st_name_, double d_height_, double d_weight_) {

	/*
	inputs--

	st_name_ :
		The name of the instance
	d_height_ :
		The height of the instance
	d_weight_ :
		The weight of the instance
	*/

	/*
	outputs--
	*/

	this->st_name = st_name_;
	this->d_height = d_height_;
	this->d_weight = d_weight_; // Order of assignment is irrelevant to the order of definition of the attributes

}


// Define a constructor : does not return anything
anAnimal::anAnimal(std::string st_name_, double d_height_, double d_weight_) {

	/*
	inputs--

	st_name_ :
		The name of the instance
	d_height_ :
		The height of the instance
	d_weight_ :
		The weight of the instance
	*/

	/*
	outputs--
	*/

	this->st_name = st_name_;
	this->d_height = d_height_;
	this->d_weight = d_weight_;

	// Do NOT forget to update the static variables
	anAnimal::n_num_of_animals += 1;

}


// Define another constructor : This constructor is usually referred to as the default constructor
anAnimal::anAnimal() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	this->st_name = "";
	this->d_height = 0;
	this->d_weight = 0; // Set some characteristics that can be detected easily. GOOD PRACTICE

	// Do NOT forget to update the static variables
	anAnimal::n_num_of_animals += 1;

}


// Define a deconstructor
anAnimal::~anAnimal() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	// Here, we just display a message. We can have custom destructors that de-allocate the memory and do some other "efficiency-related" stuff
	std::cout << "[INFO] The animal with name : " << this->st_name << " height : " << this->d_height << " : weight : " << this->d_weight << " is destroyed.\n";

}


// Define a function to print the instances
void
anAnimal::PrintInstanceOfAnAnimal() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	// This is essentially similar to python's print(...) method
	std::cout << "[INFO] The instance of class anAnimal has : " << std::endl; 
	std::cout << "[INFO]\t\tst_name\t\t : " << this->st_name << std::endl;
	std::cout << "[INFO]\t\td_height\t : " << this->d_height << std::endl;
	std::cout << "[INFO]\t\td_weight\t : " << this->d_weight << std::endl;

}


// Define a subclass of anAnimal : aDog
class aDog : public anAnimal { // aDog inherits everything in anAnimal!

	private :

		std::string st_sound = "Woof-Woof";

	public :

		void
		MakeSound() {

			/*
			inputs--
			*/

			/*
			outputs--
			*/

			// std::cout << "[INFO] The instance of aDog with name : " << this->st_name << " says : " << this->st_sound << "!\n"; // If st_name is private, even any subclass CANNOT access the private member. To achieve access by the class itself and all its subclasses, make the private attribute a protected attribute
			std::cout << "[INFO] The instance of aDog with name : " << this->GetName() << " says : " << this->st_sound << std::endl; // The private attribute values can be accessed by the getters! Thus, no need to make protected the private attributes 
		}

		// Specific constructor
		aDog(std::string, double, double, std::string); // The first 3 of animal + 1 of the dog specific (the sound)

		// Default constructor
		aDog() : anAnimal() {}; // Call animal constructor by default!

		// Declare a new print function (ocerload!)
		void
		PrintInstanceOfAnAnimal(); // Overloaded
};


// Define constructor : Here, we invoke the parent constructor and then do the dog-specific things!
aDog::aDog(std::string st_n, double d_h, double d_w, std::string st_s) : anAnimal(st_n, d_h, d_w) {

	/*
	inputs--

	st_n :
		The name of the instance
	d_h :
		The height of the instance
	d_w :
		The weight of the instance
	st_s :
		The sound of the instance
	*/

	/*
	outputs--
	*/

	/*
	// this->st_name = st_n;
	// this->d_height = d_h;
	// this->d_weight = d_w;

	// Do NOT forget to update the static variables
	// anAnimal::n_num_of_animals += 1;
	*/ // This is done by the parent constructor automatically!!

	this->st_sound = st_s;

}


// Overload the Print function
void
aDog::PrintInstanceOfAnAnimal() { // Overloaded function

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	std::cout << "[INFO] The instance of class aDog has : " << std::endl; 

	// This is essentially similar to python's print(...) method
	/*
	std::cout << "[INFO]\t\tst_name\t\t : " << this->st_name << std::endl;
	std::cout << "[INFO]\t\td_height\t : " << this->d_height << std::endl;
	std::cout << "[INFO]\t\td_weight\t : " << this->d_weight << std::endl;
	*/ // WON'T WORK AS THE ATTRIBUTES ARE PRIVATE!! ACCESS USING GETTERS!!

	std::cout << "[INFO]\t\tst_name\t\t : " << this->GetName() << std::endl;
	std::cout << "[INFO]\t\td_height\t : " << this->GetHeight() << std::endl;
	std::cout << "[INFO]\t\td_weight\t : " << this->GetWeight() << std::endl;
	std::cout << "[INFO]\t\td_weight\t : " << this->st_sound << std::endl;


}


// Define a class of warriors
class aWarrior {

	private :

		std::string st_name;

		int n_life;

		int n_max_attack;

		int n_max_defense;

	public :

		// Define getter for name
		std::string
		GetName() {

			/*
			inputs--
			*/

			/*
			outputs--

			st_name :
				The name of the warrior
			*/

			return this->st_name;

		}

		// Define setter for name
		void 
		SetName(std::string st_n) {

			/*
			inputs--

			st_n :
				The name of the warrior
			*/

			/*
			outputs--
			*/

			this->st_name = st_n;
			
		}

		// Define getter for life
		int 
		GetLife() {

			/*
			inputs--
			*/

			/*
			outputs--

			n_life :
				The life of the warrior
			*/

			return this->n_life;

		}

		// Define setter for name
		void 
		SetLife(int n_l) {

			/*
			inputs--

			n_l :
				The life of the warrior
			*/

			/*
			outputs--
			*/

			this->n_life = n_l;
			
		}

		// Define getter for max attack
		int 
		GetMaxAttack() {

			/*
			inputs--
			*/

			/*
			outputs--

			n_max_attack :
				The maximum attack of the warrior
			*/

			return this->n_max_attack;

		}

		// Define setter for max attack
		void 
		SetMaxAttack(int n_m_a) {

			/*
			inputs--

			n_m_a :
				The maximum attack of the warrior
			*/

			/*
			outputs--
			*/

			this->n_max_attack = n_m_a;
			
		}

		// Define getter for max defense
		int 
		GetMaxDefense() {

			/*
			inputs--
			*/

			/*
			outputs--

			n_max_defense :
				The maximum defense of the warrior
			*/

			return this->n_max_defense;

		}

		// Define setter for max attack
		void 
		SetMaxDefense(int n_m_d) {

			/*
			inputs--

			n_m_d :
				The maximum defense of the warrior
			*/

			/*
			outputs--
			*/

			this->n_max_defense = n_m_d;
			
		}

		// Declare the default constructor
		aWarrior();

		// Declare the custom constructor
		aWarrior(std::string st_n, int n_l, int n_m_a, int n_m_d);

		// Declare the destructor
		~aWarrior();

		// Declare a function to print the warrior information
		void
		PrintAnInstanceOfAWarrior();

}; // DON'T FORGET THE SEMI-COLON AT THE END OF THE DEFINITION


// Define the deafult constructor
aWarrior::aWarrior() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	this->st_name = "";
	this->n_life = 100;
	this->n_max_attack = 10;
	this->n_max_defense = 10;

}


// Define the deafult constructor
aWarrior::aWarrior(std::string st_n, int n_l, int n_m_a, int n_m_d) {

	/*
	inputs--

	st_n :
		The name of the warrior
	n_l :
		The life of the warrior
	n_m_a :
		The maximum attack of the warrior
	n_m_d :
		The maximum defense of the warrior
	*/

	/*
	outputs--
	*/

	this->st_name = st_n;
	this->n_life = n_l;
	this->n_max_attack = n_m_a;
	this->n_max_defense = n_m_d;

}


// Define the destructor
aWarrior::~aWarrior() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	// std::cout << "[INFO] The instance of the class aWarrior with name : " << this->st_name << " life : " << this->n_life << " max attack : " << this->n_max_attack << " max defense : " << this->n_max_defense << " is destroyed." << std::endl; // BAD PRACTICE! Keep the habit to access private attributes using the getters. Helps when there is inheritence
	std::cout << "[INFO] The instance of the class aWarrior with name : " << this->GetName() << " life : " << this->GetLife() << " max attack : " << this->GetMaxAttack() << " max defense : " << this->GetMaxDefense() << " is destroyed." << std::endl; // BAD PRACTICE! Keep the habit to access private attributes using the getters. Helps when there is inheritence

}


// Define a function to print the warrior information
void
aWarrior::PrintAnInstanceOfAWarrior() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	std::cout << "[INFO] The instance of the class aWarrior has : \n" << std::endl;
	std::cout << "[INFO]\t\tname : " << this->GetName() << std::endl;
	std::cout << "[INFO]\t\tlife : " << this->GetLife() << std::endl;
	std::cout << "[INFO]\t\tmax attack : " << this->GetMaxAttack() << std::endl;
	std::cout << "[INFO]\t\tmax defense : " << this->GetMaxDefense() << std::endl;

}


// Define a class of battlefield. We could keep the battlefield empty and then simulate a match. For practice, we will allow the battlefield to MUST have 2 warriors
class battleField {

	private :

		aWarrior* aWarrior_1;

		aWarrior* aWarrior_2;

	public :

		// Define the getter for warrior 1
		aWarrior*
		GetAWarrior1() {

			/*
			inputs--
			*/	

			/*
			outputs--

			aWarrior_1 :
				Pointer to the first warrior
			*/

			return this->aWarrior_1;

		}

		// Define the setter for warrior 1
		void
		SetAWarrior1(aWarrior* aWarrior_) {

			/*
			inputs--

			aWarrior_ :
				Pointer to the first warrior
			*/

			/*
			outputs--
			*/

			this->aWarrior_1 = aWarrior_;
			
		}

		// Define the getter for warrior 2
		aWarrior*
		GetAWarrior2() {

			/*
			inputs--
			*/	

			/*
			outputs--

			aWarrior_2 :
				Pointer to the second warrior
			*/

			return this->aWarrior_2;

		}

		// Define the setter for warrior 2
		void
		SetAWarrior2(aWarrior* aWarrior_) {

			/*
			inputs--

			aWarrior_ :
				Pointer to the second warrior
			*/

			/*
			outputs--
			*/

			this->aWarrior_2 = aWarrior_;
			
		}

		// Declare the default constructor
		battleField();

		// Declare the destructor
		~battleField();

		// Declare a function to simulate an attack by one player on another
		void 
		PerformRandomPowerAttackAndRandomPowerDefense(aWarrior* aWarrior_1_, aWarrior* aWarrior_2_);

		// Declare a function to simulate the war
		void 
		SimulateWar();

};


// Define the default constructor
battleField::battleField() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	this->aWarrior_1 =  nullptr;
	this->aWarrior_2 =  nullptr;

}

// Define the default destructor
battleField::~battleField() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	std::cout << "[INFO] The instance of the battleField with ... " << std::endl;
	std::cout << "[INFO] aWarrior_1 with : \n";
	this->aWarrior_1->PrintAnInstanceOfAWarrior();
	std::cout << "[INFO] aWarrior_2 with : \n";
	this->aWarrior_2->PrintAnInstanceOfAWarrior();
	std::cout << "[INFO] ... is destroyed.\n";

}

// Define the function to simulate an attack by one player on another
void 
battleField::PerformRandomPowerAttackAndRandomPowerDefense(aWarrior* aWarrior_1_, aWarrior* aWarrior_2_) {

	/*
	inputs--

	aWarrior_1_ :
		One warrior
	aWarrior_2_ :
		The other warrior
	*/

	/*
	outputs--
	*/

	std::cout << "######################################## NEXT ROUND ##################################################" << std::endl;
	int n_pow_attack = std::rand() % (aWarrior_1_->GetMaxAttack() + 1);
	std::cout << "[ATTACK] " << aWarrior_1_->GetName() << " attacks " << aWarrior_2_->GetName() << " with power " << n_pow_attack << "\n";
	int n_pow_defense = std::rand() % (aWarrior_2_->GetMaxDefense() + 1);
	std::cout << "[DEFENSE] " << aWarrior_2_->GetName() << " defends the attack with power " << n_pow_defense << "\n";
	if (n_pow_defense >= n_pow_attack) {
		std::cout << "[ANALYSIS] " << aWarrior_2_->GetName() << " successfully defended the attack!" << std::endl;
	}
	else {
		int n_diff = n_pow_attack - n_pow_defense;
		std::cout << "[ANALYSIS] " << aWarrior_2_->GetName() << " partially defended the attack and is down by " << n_diff  << " life!" << std::endl;
		aWarrior_2_->SetLife(std::max((aWarrior_2_->GetLife() - n_diff), 0));
	}
	std::cout << "[STATS] " << aWarrior_1_->GetName() << " has remaining life : " << aWarrior_1_->GetLife() << std::endl;
	std::cout << "[STATS] " << aWarrior_2_->GetName() << " has remaining life : " << aWarrior_2_->GetLife() << std::endl;
}


// Define the function to simulate the war
void 
battleField::SimulateWar() {

	/*
	inputs--
	*/

	/*
	outputs--
	*/

	aWarrior* aWarrior_1_ = this->aWarrior_2;
	aWarrior* aWarrior_2_ = this->aWarrior_1;
	aWarrior* aWarrior_temp = nullptr;

	std::cout << "####################################################################################################" << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << "[BEGIN] Let the tornament begin!!" << std::endl;
	std::cout << "[INFO] Warrior 1 has : " << std::endl;
	std::cout << "[INFO]\t\tname : " << aWarrior_2_->GetName() << std::endl;
	std::cout << "[INFO]\t\tlife : " << aWarrior_2_->GetLife() << std::endl;
	std::cout << "[INFO]\t\tmax attack power : " << aWarrior_2_->GetMaxAttack() << std::endl;
	std::cout << "[INFO]\t\tmax defense power : " << aWarrior_2_->GetMaxDefense() << std::endl;
	std::cout << "[INFO] Warrior 2 has : " << std::endl;
	std::cout << "[INFO]\t\tname : " << aWarrior_1_->GetName() << std::endl;
	std::cout << "[INFO]\t\tlife : " << aWarrior_1_->GetLife() << std::endl;
	std::cout << "[INFO]\t\tmax attack power : " << aWarrior_1_->GetMaxAttack() << std::endl;
	std::cout << "[INFO]\t\tmax defense power : " << aWarrior_1_->GetMaxDefense() << std::endl;

	// The war goes on till both players are alive! By definition, it will end when the FIRST player will die
	while ((aWarrior_1_->GetLife() > 0) && (aWarrior_2_->GetLife() > 0)) {

		// Swap the players
		aWarrior_temp = aWarrior_1_;
		aWarrior_1_ = aWarrior_2_;
		aWarrior_2_ = aWarrior_temp;

		// Simulate attack
		PerformRandomPowerAttackAndRandomPowerDefense(aWarrior_1_, aWarrior_2_);

	}

	std::cout << "####################################################################################################" << std::endl;
	std::cout << "[END] KO!!" << std::endl;
	if (aWarrior_1_->GetLife() <= 0) {
		std::cout << "[INFO] " << aWarrior_1_->GetName() << " has life : " << aWarrior_1_->GetLife() << std::endl;
		std::cout << "[INFO] " << aWarrior_2_->GetName() << " has life : " << aWarrior_2_->GetLife() << std::endl;
		std::cout << "[RESULT] Therefore, the winner is : " << aWarrior_2_->GetName() << std::endl; 
	}
	else  {
		std::cout << "[INFO] " << aWarrior_1_->GetName() << " has life : " << aWarrior_1_->GetLife() << std::endl;
		std::cout << "[INFO] " << aWarrior_2_->GetName() << " has life : " << aWarrior_2_->GetLife() << std::endl;
		std::cout << "[RESULT] Therefore, the winner is : " << aWarrior_1_->GetName() << std::endl; 
	}
	std::cout << "[END] GAME OVER!!" << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << "####################################################################################################" << std::endl;
	std::cout << "####################################################################################################" << std::endl;

}


// Main
int
main(int argc, char const *argv[])
{
	
	// Class instances and manipulation
	// Create an instance of the class. The name of the class acts as a data type!
	anAnimal anAnimal_fred; // The default constructor is called here!
	// Print the class instance
	anAnimal_fred.PrintInstanceOfAnAnimal();
	// Set the name, weight, height in any order
	anAnimal_fred.SetHeight(30);
	anAnimal_fred.PrintInstanceOfAnAnimal();
	anAnimal_fred.SetName("Fred");
	anAnimal_fred.PrintInstanceOfAnAnimal();
	anAnimal_fred.SetWeight(50);
	anAnimal_fred.PrintInstanceOfAnAnimal();
	/*
	Note that the class instance is destroyed by default at the end of the program!
	*/

	// Instance using constructor
	anAnimal anAnimal_tommy("Tommy", 35, 45);
	anAnimal_tommy.PrintInstanceOfAnAnimal();
	// THE FOLLOWING IS NOT ALLOWED!
	// anAnimal anAnimal_spike();
	// anAnimal_spike.PrintInstanceOfAnAnimal();

	// Instance of subclass
	aDog aDog_jimmy("Jimmy", 45, 50, "Roof-Roof");
	aDog_jimmy.PrintInstanceOfAnAnimal();
	aDog aDog_jay("Jay", 25, 25, "Meow"); 
	aDog_jay.PrintInstanceOfAnAnimal();

	std::cout << "[INFO] The total number of animals as of now : " << anAnimal::GetNumOfAnimal() << std::endl; // NOTE : INCLUDES THE INSTANCES OF aDog CLASS AS WELL!! IMPORTANT
	std::cout << "[INFO] The total number of dogs as of now : " << aDog::GetNumOfAnimal() << std::endl; // NOTE : INCLUDES THE INSTANCES OF anAnimal CLASS AS WELL!! IMPORTANT

	// THE GREAT BATTLE
	srand(time(NULL)); // Set random seed
	aWarrior aWarrior_thor("Thor", 100, 50, 10);
	aWarrior aWarrior_hulk("Hulk", 100, 50, 10);
	battleField battleField_;
	battleField_.SetAWarrior1(&aWarrior_thor);
	battleField_.SetAWarrior2(&aWarrior_hulk);
	battleField_.SimulateWar();

	return 0;

}