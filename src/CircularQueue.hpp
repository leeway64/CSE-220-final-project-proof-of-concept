#include <vector>

template<class T>
class CircularQueue
{
    private:
        std::vector<T> circularQueue{};
        int size = 0;
        int counter = 0;
        int back_index = 0;
        int front_index = 0;

    
    public:
        // Initializes a vector with size equal to size
        CircularQueue(int size);

        CircularQueue(std::vector<T> list);
    
        std::vector<T> get_queue();

        int get_size();

        void push(T value);

        int pop();

        T get_front();

        T get_back();
};

template<class T>
CircularQueue<T>::CircularQueue(int size)
{
    this->size = size;
    this->circularQueue.reserve(size);
    this->back_index = 0;
    this->front_index = (this->counter - 1) % size;
}

template <class T>
CircularQueue<T>::CircularQueue(std::vector<T> list)
{
    this->circularQueue = list;
    this->size = list.size();
    this->circularQueue.reserve(this->size);
    this->counter = this->size;
    this->front_index = (this->counter - 1) % size;
    this->back_index = 0;
}

template<class T>
void CircularQueue<T>::push(T value)
{
    if (this->counter < this->size)
    {
        this->circularQueue.push_back(value);
    }
    else
    {
        int index = counter % size;
        auto position = this->circularQueue.begin() + index;
        this->circularQueue.erase(position);
        this->circularQueue.insert(position, value);

        this->back_index = (counter + 1) % size;
    }

    this->counter++;
    this->front_index = (this->counter - 1) % size;
}

template<class T>
int CircularQueue<T>::pop()
{
    int value = this->circularQueue[back_index];
    auto position = this->circularQueue.begin() + back_index;

    this->circularQueue.erase(position);
    
    if (this->back_index > this->circularQueue.size() - 1)
    {
        this->back_index = 0;
    }

    return value;
}

template<class T>
std::vector<T> CircularQueue<T>::get_queue()
{
    return this->circularQueue;
}

template<class T>
int CircularQueue<T>::get_size()
{
    return this->size;
}

template<class T>
T CircularQueue<T>::get_front()
{
    return this->circularQueue[this->front_index];
}

template<class T>
T CircularQueue<T>::get_back()
{
    return this->circularQueue[back_index];
}