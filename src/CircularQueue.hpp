#include <vector>

class CircularQueue
{
    private:
        std::vector<int> circularQueue{};
        int size = 0;
        int counter = 0;
    public:

        // Default constructor
        CircularQueue();

        // Initializes a vector with size equal to size
        CircularQueue(int size);

        // Size of list must be less than or equal to size
        CircularQueue(std::vector<int> list);
    
        std::vector<int> get_queue();

        int get_size();

        void push(int value);
};