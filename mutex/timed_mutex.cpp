#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tmutex;

void try_to_lock(int thread_id) {
    using namespace std::literals::chrono_literals;

    std::cout << "Thread " << thread_id << " attempting to acquire lock...\n";

    // If "try_lock_for" > "hold_time" - "delay_time"
    // Then the next thread will manage to aceuire in time.
    // Otherwise it fails
    const auto try_lock_for = 3s;
    const auto hold_time = 3s;

    if (tmutex.try_lock_for(try_lock_for)) {
        std::cout << "Thread " << thread_id << " acquired the lock!\n";

        std::this_thread::sleep_for(hold_time);  // Hold the lock for 3 seconds
        tmutex.unlock();
        std::cout << "Thread " << thread_id << " released the lock.\n";
    } else {
        std::cout << "Thread " << thread_id << " failed to acquire the lock.\n";
    }
}

int main() {
    std::thread t1(try_to_lock, 1);
    // Slight delay to make a lag between tasks
    const auto sleep_time = std::chrono::milliseconds(100);
    std::this_thread::sleep_for(sleep_time);
    std::thread t2(try_to_lock, 2);

    t1.join();
    t2.join();

    return 0;
}