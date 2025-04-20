#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

static constexpr int num_threads = 40;
static constexpr int repetitions = 10;
int counter = 0; // Shared resource
std::mutex counter_mutex;

void increment(int thread_id) {
    for (int i = 0; i < 1000; ++i) {
#ifdef USE_MUTEX
        std::lock_guard<std::mutex> lock(counter_mutex);
#endif
        ++counter;
    }
}

int main() {

#ifdef USE_MUTEX
    std::cout << "Mutex in use" << std::endl;
    std::cout << "With enabled mutex result should be same every repetition" << std::endl;
#else
    std::cout << "No mutex" << std::endl;
    std::cout << "Without mutex result can differ between iterations because of race" << std::endl;
#endif

    for (int rep = 0; rep < repetitions; ++rep) {
        
        counter = 0;
        std::vector<std::thread> threads;

        // Create threads
        for (int i = 0; i < num_threads; ++i) {
            threads.emplace_back(increment, i);
        }

        // Waiting all threads finish
        for (auto &t : threads) {
            t.join();
        }

        std::cout << "Finall count: " << counter << std::endl;
    }

    return 0;
}