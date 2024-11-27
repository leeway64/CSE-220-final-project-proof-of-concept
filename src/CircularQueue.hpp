#include <vector>

class CircularQueue
{
    private:
        std::vector<int> circularQueue{};
        int size = 0;
        int counter = 0;
        int back_index = 0;
        int front_index = 0;

    
    public:
        // Initializes a vector with size equal to size
        CircularQueue(int size);

        // Size of list must be less than or equal to size
        CircularQueue(std::vector<int> list);
    
        std::vector<int> get_queue();

        int get_size();

        void push(int value);

        int pop();

        int get_front();

        int get_back();
};