#include "CircularQueue.hpp"

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    this->circularQueue.reserve(size);
    this->back_index = 0;
}

CircularQueue::CircularQueue(std::vector<int> list)
{
    this->circularQueue = list;
    this->size = list.size();
    this->circularQueue.reserve(this->size);
    this->counter = this->size;
    this->back_index = 0;
}

void CircularQueue::push(int value)
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
}

int CircularQueue::pop()
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

std::vector<int> CircularQueue::get_queue()
{
    return this->circularQueue;
}

int CircularQueue::get_size()
{
    return this->size;
}

int CircularQueue::get_front()
{
    return this->circularQueue[(this->counter - 1) % size];
}

int CircularQueue::get_back()
{
    return this->circularQueue[back_index];
}