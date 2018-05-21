g++ $1 -O3 -std=c++11 -o main 
# The -std=c++11 is needed for MAC OSX and c++11 behaviour. Otherwise, we are hit with the error "error: no matching constructor for initialization of 'std::thread'"