Mutex:
g++ -std=c++11 -pthread -o mutex_example mutex.cpp -DUSE_MUTEX=1

Timed mutex:
g++ -std=c++14 -pthread timed_mutex.cpp -o timed_mutex_example

Pointers:
g++ -o pointers pointers.cpp

