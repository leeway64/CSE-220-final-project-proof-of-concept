#include <catch2/catch_test_macros.hpp>
#include "../src/CircularQueue.hpp"

TEST_CASE("CircularQueue", "[CircularQueue]")
{
    const std::vector<int> vec1 = {1, 2, 3, 4, 5};
    const int size1 = 3;
    SECTION("Constructors")
    {
        CircularQueue cq1 = CircularQueue();
        CircularQueue cq2 = CircularQueue(size1);
        CircularQueue cq3 = CircularQueue(vec1);

        REQUIRE(cq1.get_size() == 0);
        REQUIRE(cq1.get_queue() == std::vector<int>{});

        REQUIRE(cq2.get_size() == size1);
        REQUIRE(cq2.get_queue() == std::vector<int>{});

        REQUIRE(cq3.get_size() == vec1.size());
        REQUIRE(cq3.get_queue() == vec1);
    }

    SECTION("push")
    {

    }

}