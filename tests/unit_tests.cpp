#include <catch2/catch_test_macros.hpp>
#include "../src/CircularQueue.hpp"

TEST_CASE("CircularQueue", "[CircularQueue]")
{
    const std::vector<int> vec1 = {1, 2, 3, 4, 5};
    const int size1 = 2;

    const std::vector<int> vec2 = {223432, 34546, 435435, 135, 54654, 1, 4, 90, 6, 7, 8};
    const int size2 = 3;

    CircularQueue<int> cq1 = CircularQueue<int>(size1);
    CircularQueue<int> cq2 = CircularQueue<int>(vec1);
    CircularQueue<int> cq3 = CircularQueue<int>(size2);
    CircularQueue<int> cq4 = CircularQueue<int>(vec2);
    CircularQueue<std::string> cq5(size1);
    CircularQueue<double> cq6(size2);

    SECTION("Constructors")
    {
        REQUIRE(cq1.get_size() == 0);
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
            REQUIRE(cq3.get_size() == 2);

            REQUIRE(cq3.pop() == 8);
            REQUIRE(cq3.get_front() == 9);
            REQUIRE(cq3.get_back() == 9);
            REQUIRE(cq3.get_queue() == std::vector<int>{9});

            REQUIRE(cq3.pop() == 9);            
            REQUIRE(cq3.get_queue() == std::vector<int>{});
            REQUIRE(cq3.get_size() == 0);
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

    SECTION("Different data types")
    {
        cq5.push("Hello");
        cq5.push("world");
        REQUIRE(cq5.get_front() == "world");
        REQUIRE(cq5.get_back() == "Hello");
        REQUIRE(cq5.get_size() == 2);

        REQUIRE(cq5.pop() == "Hello");
        REQUIRE(cq5.get_front() == "world");
        REQUIRE(cq5.get_back() == "world");
        REQUIRE(cq5.get_size() == 1);


        REQUIRE(cq5.pop() == "world");
        REQUIRE(cq5.get_queue() == std::vector<std::string>{});
        REQUIRE(cq5.get_size() == 0);
    }

    SECTION("For-each loop")
    {
        const std::vector<int> test_vector1 = {5, 4, 3, 2, 1};
        const std::vector<double> test_vector2 = {0.32323201, 1893.234324, 12332.3323};
        SECTION("With integers")
        {
            REQUIRE(*cq2.begin() == 5);
            REQUIRE(*(cq2.end() - 1) == 1);

            auto iter = cq2.begin();
            int i = 0;
            while(iter != cq2.end())
            {
                REQUIRE(*iter == test_vector1[i]);
                iter++;
                i++;
            }
        }

        SECTION("With doubles")
        {
            cq6.push(12.3);
            cq6.push(12332.3323);
            cq6.push(1893.234324);
            cq6.push(0.32323201);
            REQUIRE(*cq6.begin() == 0.32323201);
            REQUIRE(*(cq6.end() - 1) == 12332.3323);

            int i = 0;
            for (auto iter = cq6.begin(); iter != cq6.end();)
            {
                REQUIRE(*iter == test_vector2[i]);
                ++iter;
                ++i;
            }
        }
    }
}