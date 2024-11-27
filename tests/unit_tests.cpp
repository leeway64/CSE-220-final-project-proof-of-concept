#include <catch2/catch_test_macros.hpp>
#include "../src/CircularQueue.hpp"

TEST_CASE("CircularQueue", "[CircularQueue]")
{
    const std::vector<int> vec1 = {1, 2, 3, 4, 5};
    const int size1 = 2;

    const std::vector<int> vec2 = {223432, 34546, 435435, 135, 54654, 1, 4, 90, 6, 7, 8};
    const int size2 = 3;

    CircularQueue cq1 = CircularQueue(size1);
    CircularQueue cq2 = CircularQueue(vec1);
    CircularQueue cq3 = CircularQueue(size2);
    CircularQueue cq4 = CircularQueue(vec2);

    SECTION("Constructors")
    {
        REQUIRE(cq1.get_size() == size1);
        REQUIRE(cq1.get_queue() == std::vector<int>{});

        REQUIRE(cq2.get_size() == vec1.size());
        REQUIRE(cq2.get_queue() == vec1);
    }

    SECTION("push, get_front, get_back")
    {
        SECTION("Constructor that accepts size")
        {            
            cq3.push(6);
            REQUIRE(cq3.get_queue() == std::vector<int>{6});
            REQUIRE(cq3.get_front() == 6);
            REQUIRE(cq3.get_back() == 6);

            cq3.push(7);
            REQUIRE(cq3.get_queue() == std::vector<int>{6, 7});
            REQUIRE(cq3.get_front() == 7);
            REQUIRE(cq3.get_back() == 6);

            cq3.push(8);
            REQUIRE(cq3.get_queue() == std::vector<int>{6, 7, 8});
            REQUIRE(cq3.get_front() == 8);
            REQUIRE(cq3.get_back() == 6);

            cq3.push(9);
            REQUIRE(cq3.get_queue() == std::vector<int>{9, 7, 8});
            REQUIRE(cq3.get_front() == 9);
            REQUIRE(cq3.get_back() == 7);
        }

        SECTION("Constructor that accepts vector")
        {
            REQUIRE(cq4.get_front() == 8);
            REQUIRE(cq4.get_back() == 223432);  

            cq4.push(-1);
            REQUIRE(cq4.get_queue() == std::vector<int>{-1, 34546, 435435, 135, 54654, 1, 4, 90, 6, 7, 8});
            REQUIRE(cq4.get_front() == -1);
            REQUIRE(cq4.get_back() == 34546);

            cq4.push(-20);
            REQUIRE(cq4.get_queue() == std::vector<int>{-1, -20, 435435, 135, 54654, 1, 4, 90, 6, 7, 8});
            REQUIRE(cq4.get_front() == -20);
            REQUIRE(cq4.get_back() == 435435);
        }
    }

    SECTION("pop")
    {
        SECTION("Constructor that accepts size")
        {
            cq3.push(6);
            cq3.push(7);
            cq3.push(8);
            cq3.push(9);
            
            REQUIRE(cq3.get_queue() == std::vector<int>{9, 7, 8});
            REQUIRE(cq3.get_front() == 9);
            REQUIRE(cq3.get_back() == 7);

            REQUIRE(cq3.pop() == 7);
            REQUIRE(cq3.get_front() == 9);
            REQUIRE(cq3.get_back() == 8);
            REQUIRE(cq3.get_queue() == std::vector<int>{9, 8});

            REQUIRE(cq3.pop() == 8);
            REQUIRE(cq3.get_front() == 9);
            REQUIRE(cq3.get_back() == 9);
            REQUIRE(cq3.get_queue() == std::vector<int>{9});

            REQUIRE(cq3.pop() == 9);            
            REQUIRE(cq3.get_queue() == std::vector<int>{});
            REQUIRE(cq3.get_queue().size() == 0);
        }

        SECTION("Constructor that accepts vector")
        {
            REQUIRE(cq4.get_queue() == std::vector<int>{223432, 34546, 435435, 135, 54654, 1, 4, 90, 6, 7, 8});

            REQUIRE(cq4.pop() == 223432);
            REQUIRE(cq4.get_back() == 34546);
            REQUIRE(cq4.get_queue() == std::vector<int>{34546, 435435, 135, 54654, 1, 4, 90, 6, 7, 8});
        
            REQUIRE(cq4.pop() == 34546);
            REQUIRE(cq4.get_back() == 435435);
            REQUIRE(cq4.get_queue() == std::vector<int>{435435, 135, 54654, 1, 4, 90, 6, 7, 8});
        }
    }
}