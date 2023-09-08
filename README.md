# Cpp09

### deque "double-ended queue"
is a sequence container that allows efficient insertion and deletion of elements at both ends, making it a versatile data structure for certain scenarios. It is part of the C++ Standard Library and is defined in the header.

    #include <deque>

    std::deque<T> myDeque;                 // Creates an empty deque of type T
    std::deque<T> myDeque(otherDeque);     // Creates a copy of 'otherDeque'
    std::deque<T> myDeque(size, value);    // Creates a deque with 'size' elements, each initialized to 'value'
    std::deque<T> myDeque(beginIterator, endIterator);      // Creates a deque from the elements in the range [beginIterator, endIterator)

Inserting Elements:

- push_back(value): Adds an element to the back of the deque.
* push_front(value): Adds an element to the front of the deque.
+ insert(iterator, value): Inserts an element at the specified position.

Accessing Elements:

- front(): Returns the first element.
- back(): Returns the last element.
- at(index): Returns the element at the specified index with bounds checking.

Removing Elements:

- pop_back(): Removes the last element.
- pop_front(): Removes the first element.
- erase(iterator): Removes the element at the specified position.
- clear(): Removes all elements from the deque.

Size and Capacity:

- size(): Returns the number of elements in the deque.
- empty(): Checks if the deque is empty.
- resize(newSize): Changes the size of the deque.

  ----------------------


