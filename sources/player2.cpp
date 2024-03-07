#include "../headers/TRound.h"

#include "../headers/functions.h"

#include <thread>
#include <chrono>
#include <iostream>

int main(int argc, char** argv)
{
    if (!argv[1])
        std::cout << "No map filename given!" << std::endl;
    else if (!argv[2])
        std::cout << "No status filename given!" << std::endl;
    else if (!argv[3])
        std::cout << "No order filename given!" << std::endl;
    else
    {
        unsigned int timer{};

        if (!argv[4])
            timer = 2;
        else
            timer = std::stoi(argv[4]);

        /* orders.txt from the previous round is deleted */
        std::remove(argv[3]);

        std::thread thread1(play_round, 'E', argv[1], argv[2], argv[3]);

        std::this_thread::sleep_for(std::chrono::seconds(timer));
        
        thread1.join();
    }
    
    return 0;
}