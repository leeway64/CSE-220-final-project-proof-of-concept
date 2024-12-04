#include <vector>

// This class implements a circular buffer. Refer to this Wikipedia page for more information:
// https://en.wikipedia.org/wiki/Circular_buffer
// This implementation was heavily influenced by the ideas laid out in the Circular buffer
// Wikipedia page.
template<class T>
class CircularQueue
{
    public:
        // Initializes a CircularQueue with max_size. Reserves a vector with a size of max_size.
        CircularQueue(int max_size);

        // Initializes a CircularQueue with the contents of list. The front of the CircularQueue
        // will be the last value of list, and the back will be the first value of list.
        CircularQueue(std::vector<T> list);
    
        // Returns the vector representing the circular buffer. The "front" of the queue might not
        // necessarily be the last value of the vector, and the "back" of the queue might not
        // necessarily be the first value.
        std::vector<T> get_queue();
        
        int calculate_priority(int index);

        // Return the total number of elements in the circular queue
        int get_size();
        
        // Return the maximum number of elements the circular queue can store
        int get_max_size();

        // Add a value to the front of the circular queue. If adding another value would cause the
        // queue to exceed the maximum size, then the value overwrites the back of the queue. The
        // front of the queue now points to the newly added value, and the back of the queue moves
        // to the next value in the sequence.
        void push(T value);

        // Remove and return the value from the back of the circular buffer. In other words, this
        // circular buffer maintains a first in, first out policy.
        T pop();

        // Return the value at the front of the queue
        T get_front();

        // Return the value at the back of the queue
        T get_back();

        // Return the last value of the vector holding the circular queue. This might not
        // necessarily be the back of the circular queue
        T get_last();

        // Remove and return the last value of the vector holding the circular queue (not
        // necessarily the value of the back of the circular queue)
        T pop_last();

        // Return an iterator pointing to the front of the queue
        auto begin();

        // Return an iterator pointing to one element past the back of the queue
        auto end();

        auto erase(auto iter);

    private:
        // The vector containing all the values in the circular queue
        std::vector<T> circularQueue{};

        // The maximum size of the circular queue
        int max_size = 0;

        int counter = 0;
        
        int back_index = 0;
        int front_index = 0;

        std::vector<T> unrolled_queue{};
        bool wrap_around = false;
};

template<class T>
int CircularQueue<T>::calculate_priority(int index) {
    if (wrap_around){
        if (index < back_index){
            return max_size + index;
        }
    }
    return index;
}

template<class T>
CircularQueue<T>::CircularQueue(int max_size)
{
    this->max_size = max_size;
    this->circularQueue.reserve(max_size);
    this->back_index = 0;
    this->front_index = (this->counter - 1) % max_size;
}

template <class T>
CircularQueue<T>::CircularQueue(std::vector<T> list)
{
    this->circularQueue = list;
    this->max_size = list.size();
    this->circularQueue.reserve(this->max_size);
    this->counter = this->max_size;
    this->front_index = (this->counter - 1) % this->max_size;
    this->back_index = 0;
}

template<class T>
void CircularQueue<T>::push(T value)
{
    if (this->counter < this->max_size)
    {
        this->circularQueue.push_back(value);
    }
    else
    {
        int index = this->counter % this->max_size;
        auto position = this->circularQueue.begin() + index;
        this->circularQueue.erase(position);
        this->circularQueue.insert(position, value);

        this->back_index = (this->counter + 1) % this->max_size;
        wrap_around = true;
    }

    this->counter++;
    this->front_index = (this->counter - 1) % this->max_size;
}

template<class T>
T CircularQueue<T>::pop()
{
    int highest_priority = calculate_priority(this->back_index);
    int target_index = this->back_index;
    for (size_t i = 1; i < this->circularQueue.size(); i++){
        int current_index = (this->back_index + i) % max_size;
        int current_priority = calculate_priority(current_index);
        if(current_priority < highest_priority){
            highest_priority = current_priority;
            target_index = current_index;
        }
    }
    T value = this->circularQueue[target_index];

    this->circularQueue.erase( this->circularQueue.begin() + target_index);
    
    if (target_index == this->back_index)
    {
       this->back_index = (this->back_index) % max_size;
    }
    this->counter--;
    if(this->counter < max_size){
        wrap_around = false;
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
    return this->circularQueue.size();
}

template<class T>
int CircularQueue<T>::get_max_size()
{
    return this->max_size;
}

template<class T>
T CircularQueue<T>::get_front()
{
    return this->circularQueue[this->front_index];
}

template<class T>
T CircularQueue<T>::get_back()
{
    return this->circularQueue[this->back_index];
}

template<class T>
T CircularQueue<T>::get_last()
{
    return this->circularQueue.back();
}

template<class T>
T CircularQueue<T>::pop_last()
{
    this->counter--;
    if (this->front_index == this->max_size - 1)
    {
        this->front_index = (this->counter - 1) % this->max_size;
    }
    auto last = this->circularQueue.back();
    this->circularQueue.pop_back();
    return last;
}

template<class T>
auto CircularQueue<T>::begin()
{
    return this->circularQueue.begin();
}

template<class T>
auto CircularQueue<T>::end()
{
    return this->circularQueue.end();
}


template<class T>
auto CircularQueue<T>::erase(auto iter)
{
    this->counter--;
    this->front_index = (this->counter - 1) % this->max_size;
    return this->circularQueue.erase(iter);
}