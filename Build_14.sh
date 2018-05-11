g++ -c $2 -O3 -o main_2.o
g++ -c $1 -O3 -o main_1.o
g++ main_2.o main_1.o -O3 -o main
# We can also do like : g++ -O3 main.cpp anAnimal_14.cpp -o main