# Cpp09

### deque (short for "double-ended queue"
is a sequence container that allows efficient insertion and deletion of elements at both ends, making it a versatile data structure for certain scenarios. It is part of the C++ Standard Library and is defined in the header.

    #include <deque>

    std::deque<T> myDeque;                 // Creates an empty deque of type T
    std::deque<T> myDeque(otherDeque);     // Creates a copy of 'otherDeque'
    std::deque<T> myDeque(size, value);    // Creates a deque with 'size' elements, each initialized to 'value'
    std::deque<T> myDeque(beginIterator, endIterator);      // Creates a deque from the elements in the range [beginIterator, endIterator)

