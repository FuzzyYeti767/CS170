// TODO Comment Header
#pragma once

#include <iostream>

namespace CS170
{
    class List
    {
    public:
        // TODO Four constructors - No param, copy, move and array ctor
        List(); //No Param
        List(const List&); //copy
        List(List&&) noexcept; //move
        List(const int*array, int size);

        // TODO Destructor
        ~List(); //Destructor
        // TODO Seven methods:
        //   push_front, adds the item to the front of the list
        void push_front(int data);
        //   push_back, adds the item to the end of the list
        void push_back(int data);
        //   pop, removes the first item in the list
        void pop();
        //   front, returns the first item in the list
        int front();
        //   size, returns the number of items in the list
        int size() const;
        //   empty, returns true if empty, else false
        bool empty() const;
        //   clear, clears the list (removes all of the nodes)
        void clean();
        // TODO Six operators:
     
        //   operator= for copy and move
        List& operator=(const List&);
        List& operator=(List&&) noexcept;

        //   operator+=
        List& operator+=(const List&);
        List operator+(const List&);
        //   operator+
        
        int& operator[](int index);
        const int& operator[](int index) const;
        
        //   operator[] (2 of these)

        // Output operator for printing lists (<<)
        friend std::ostream& operator<<(std::ostream& os, const List& list);

        // Returns the number of Lists that have been created
        [[nodiscard]] inline  static int list_count() noexcept
        {
            return global_list_count;
        }

        // Returns the number of Nodes that are still alive
        [[nodiscard]] inline  static int node_count() noexcept
        {
          return global_nodes_alive;
        }

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
