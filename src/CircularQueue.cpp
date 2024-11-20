#include "CircularQueue.hpp"

CircularQueue::CircularQueue(){}

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    this->circularQueue.reserve(size);
}

CircularQueue::CircularQueue(std::vector<int> list)
{
    this->circularQueue = list;
    this->size = list.size();
}

void CircularQueue::push(int value)
{
    int index = counter % size;
    auto position = this->circularQueue.begin();
    this->circularQueue.erase(std::next(position, index));
    this->circularQueue.insert(std::next(position, index), value);
    counter++;
}

std::vector<int> CircularQueue::get_queue()
{
    return this->circularQueue;
}

int CircularQueue::get_size()
{
    return this->size;
}