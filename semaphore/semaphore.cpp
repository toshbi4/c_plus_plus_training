#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <semaphore>

std::counting_semaphore<3> sem{3};

class Worker {
public:
    Worker(){}
    ~Worker(){}

    void do_work(int thread_id) {

        int count = 0;

        std::this_thread::sleep_for(std::chrono::milliseconds(thread_id * 10));
        std::cout << "==> Started: " << thread_id << std::endl;

        sem.acquire();

        while(1) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Exec: " << thread_id << " count: " << count << std::endl;
            count++;
            if (count > 3) {
                break;
            }
        }

        std::cout << "==> Finished: " << thread_id << std::endl;
        sem.release();
    }

};

int main() {
    Worker w{};

    std::vector<std::thread> threads;

    for (int i = 0; i < 5; i++) {
        threads.emplace_back(&Worker::do_work, &w, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

}