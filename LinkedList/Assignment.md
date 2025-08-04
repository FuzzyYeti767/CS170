# Assignment Linked List

You are to implement a class called `List`, which will implement a singly linked list with a tail pointer.

The point of this assignment is to practice topics such as exceptions, RAII, Rule of 5, pointers, dynamic memory allocation, R-Value References, constructors, overloaded operators, and linked lists.

There are several methods that manipulate the nodes in the linked list. These methods include adding items to either end, removing an item from the front, copying lists, concatenating lists, etc. Each Node in a list contains an integer and a pointer to another Node. This node structure is intentionally kept simple so you can focus on the list aspect of the assignment.



## List class Interface

```c++
// TODO Comment Header
#pragma once

#include <iostream>

namespace CS170
{
    class List
    {
    public:
        // TODO Four constructors - No param, copy, move and array ctor
        
        // TODO Destructor

        // TODO Seven methods:
        //   push_front, adds the item to the front of the list
        //   push_back, adds the item to the end of the list
        //   pop, removes the first item in the list
        //   front, returns the first item in the list
        //   size, returns the number of items in the list
        //   empty, returns true if empty, else false
        //   clear, clears the list (removes all of the nodes)

        // TODO Six operators:
        //   operator= for copy and move
        //   operator+=
        //   operator+
        //   operator[] (2 of these)

        // Output operator for printing lists (<<)
        friend std::ostream& operator<<(std::ostream& os, const List& list);

        // Returns the number of Lists that have been created
        [[nodiscard]] static int list_count() noexcept;

        // Returns the number of Nodes that are still alive
        [[nodiscard]] static int node_count() noexcept;

    private:
        // used to build a linked list of integers
        struct Node
        {
            Node* next{nullptr}; // pointer to the next Node
            int   data{0};       // the actual data in the node
        };

        Node* head_{nullptr}; // pointer to the head of the list
        Node* tail_{nullptr}; // pointer to the last node
        int   size_{0};       // number of items on the list

        static inline int global_list_count{0};  // number of Lists created
        static inline int global_nodes_alive{0}; // count of nodes still allocated

        Node* new_node(int data) const; // allocate node, initialize data/next
        // TODO other helper functions
    };

    namespace error_messages
    {
        constexpr auto BAD_ARRAY  = "Bad array provided in List constructor";
        constexpr auto EMPTY_LIST = "Cannot perform operation on EMPTY List";
        constexpr auto BAD_INDEX  = "Index is out of range with respect to the size of the List";
    }

}
```

See the tests for learning what the expected usage of these functions are. 

Many of the functions will call other functions you've implemented ***(code reuse)***, so the amount of code is not that great. The "worker" functions are **`push_back`**, **`push_front`**, and **`pop`**. Once these functions are implemented and _thoroughly tested_, the rest of the assignment can build on top of these.

## FAQ

1. What should the `pop()` and `front()` member function do if the list is empty?

    It should throw an exception that is a derived class of `std::exception` with the `EMPTY_LIST` error message.

2. What should `operator[]` do if the index value is invalid?

    It should throw an exception that is a derived class of `std::exception` with the `BAD_INDEX` error message.

3. How does the `clear()` method work? The sample driver isn't calling it.

    It should make the list become empty. It doesn't return anything. Even though the driver doesn't call it, your code should. _(Hint: The destructor should call it. Code re-use!)_
    
4. The program that I compiled wth g++ and clang++ give me the same value for the total number of lists created, but Microsoft's compiler gives me a different number. Am I doing something wrong?

    No. You _may_ get different answers. This is related to Return Value Optimization, which we will study soon. It is likely that Microsoft's Debug version produces slightly different numbers, but Release mode should help get the numbers to match.

5. Why do we need two subscript operators _(`operator[]`)_?

    Because sometimes we want read only access _(const)_ and sometimes we want read and write access _(non-const)_. Also, the driver won't compile without them.

## Create a ReadMe


Create a **`ReadMe.md`** file that defines the following

1. your name, assignment name/number, course name, term
2. Section describing how to build and run the project
3. Section describing anything incomplete about the assignment
4. Section describing something you're proud of about the assignment
5. File and Line numbers for all coding requirements


## Submission

You will be submitting your work on GitHub with the provided class assignment repository.

You will also submit your `List.h` and `List.cpp` files on to the course site.

Note that we will be grading from **both** the GitHub repo and the course site.

## Grading Rubric

- [ ] [**core**] Implemented an int based singly linked list class with a tail pointer
- [ ] [**core**] Implemented all needed constructors, public member functions, and operator member functions
- [ ] [**core**] Allocate nodes using **`new`**. The only function that uses it is `new_node()` and the `new` operator is used exactly once in your code.
- [ ] [**core**] Only `push_front()` and `push_back()` call `new_node()` to create nodes
- [ ] [**core**] Deallocate the nodes using **`delete`**. The only function that will use `delete` is `pop()` and the `delete` operator is used exactly once in your code.
- [ ] [**core**] Implemented the Rule of 5 for the List class
- [ ] [**core**] The List array constructor throws an exception if provided with bad input, `pop()` & `front()` throws an exception of the List is empty, and the `operator[]` functions throw an exception if provided a bad index value
- [ ] [**core**] All assignment operators return a reference to `this` instance
- [ ] [**core**] All member functions are marked `const` where possible
- [ ] `operator+` will create a new List object and fill it with a deep copy of the nodes from list `this` and nodes from the right hand side
- [ ] `operator+=` will add the nodes from the right hand side to `this` list
- [ ] Only the standard `iostream` header is included inside of `List.h` and only `List.h`, `iomanip` and `stdexcept` are included inside of `List.cpp`
- [ ] No redundant code duplication and helper functions are used for commonly used code. HOWEVER, the two `operator[]` functions must have duplicate code
- [ ] `noexcept` applied to functions that don't throw nor call any functions that could throw. NOTE that operators `new` and `delete` could throw an exception.
- [ ] Make the List class `nodiscard` and utilize `nodiscard` where possible for return values
- [ ] All source files that you modified have a proper header comment with your name, assignment name/number, course name, term.
- [ ] All source files compile without warnings and without errors
- [ ] Created a helpful `ReadMe.md` file as described above
- [ ] Correct files submitted. No unnecessary files submitted.
- [ ] Followed the appropriate Code Quality Guidelines and Code Style Guidelines.

Scores for Assignments will be given as the following:

Score        | Assessment
------------ | ----------
Zero         | Nothing turned in at all
Failing      | Close to meeting core requirements
Rudimentary  | Meets all of the core requirements
Satisfactory | Close to meeting all requirements
Good         | Clearly meets all requirements 
Excellent    | High quality, well beyond the requirements


