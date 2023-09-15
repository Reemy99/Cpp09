# Cpp09

**Associative Containers:** store data in a sorted order and allow for efficient lookup and retrieval of elements based on their keys.

1. set: a container that stores unique elements in a sorted order.

1. map: a container that stores key-value pairs in a sorted order based on keys.

________________
## MAP
1) **Include the Header File:**

           #include <map>
2) **Map Declaration and Initialization:**

        std::map<int, std::string> myMap;                  //Declare an empty map
        std::map<int, std::string> myMap = {{1, "Sting"}}; //with specific key-value pairs:
3) Inserting Elements:

        myMap.insert(std::make_pair(4, "David")); 
        myMap[5] = "Eve";
4) Accessing Elements:

        std::string value = myMap[1]; // Access the value associated with key 1 (e.g., "string")
5) Removing Elements:

        myMap.erase(3); // Remove the key-value pair with key 3
6) Iterating Over a Map:

        std::map<int, std::string>::iterator it = myMap.begin();
        while (it != myMap.end())
        {
            int key = it->first;
            std::string value = it->second;
                    // Process the key and value
            ++it;        // Move to the next key-value pair
        }

7) Map Size:

        int size = myMap.size();
__________________________________________________
### deque "double-ended queue"
is a sequence container that allows efficient insertion and deletion of elements at both ends, making it a versatile data structure for certain scenarios. It is part of the C++ Standard Library and is defined in the header.

    #include <deque>

    std::deque<T> myDeque;                 // Creates an empty deque of type T
    std::deque<T> myDeque(otherDeque);     // Creates a copy of 'otherDeque'
    std::deque<T> myDeque(size, value);    // Creates a deque with 'size' elements, each initialized to 'value'
    std::deque<T> myDeque(beginIterator, endIterator);      // Creates a deque from the elements in the range [beginIterator, endIterator)

***Inserting Elements:***

- push_back(value): Adds an element to the back of the deque.
* push_front(value): Adds an element to the front of the deque.
+ insert(iterator, value): Inserts an element at the specified position.

***Accessing Elements:***

- front(): Returns the first element.
- back(): Returns the last element.
- at(index): Returns the element at the specified index with bounds checking.

***Removing Elements:***

- pop_back(): Removes the last element.
- pop_front(): Removes the first element.
- erase(iterator): Removes the element at the specified position.
- clear(): Removes all elements from the deque.

***Size and Capacity:***

- size(): Returns the number of elements in the deque.
- empty(): Checks if the deque is empty.
- resize(newSize): Changes the size of the deque.
----------------------

**getline()**

we have more than one declaration
           
           istream& getline(istream& is, string& str, char delim);
- is: It is an object of istream class and tells the function about the stream from where to read the input from.
- str: It is a string object, the input is stored in this object after being read from the stream.
- delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.

           istream& getline (istream& is, string& str);
- The second declaration is almost the same as that of the first one. The only difference is, the latter have an delimitation character which is by default newline(\n)character.

***Stringstream :***

is a class in C++ that allows you to manipulate strings as if they were input or output streams, and provides a convenient and powerful way to convert data between strings and other data types, split a string into substrings, and manipulate strings in a variety of other ways

-------------------------------------
## ex01

**The advantage of reverse Polish notation**

is that it removes the need for order of operations and parentheses that are required by infix notation and can be evaluated linearly, left-to-right.

For example, the infix expression (3 × 4) + (5 × 6) becomes 3 4 × 5 6 × + in reverse Polish notation
