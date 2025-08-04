// TODO Comment Header
// Name :Jinseok Son
// Assignment :Linked_list
// Course : CS170
//Term :Digipen 2022 - spring
#include "List.h"

#include <iomanip>
#include <stdexcept>


namespace CS170
{

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    // public methods in matching order of header file:
    // Constructors (default, copy, non-defaults), destructor, push_front(), etc...

    List::List()
    {
        global_list_count++;
    }



    List::List(const List& list)
    {
        Node* original = list.head_;
        Node* current = nullptr;
        
        while (original != nullptr)
        {
            if (head_ == nullptr)
            {
                current = new_node(original->data);
                head_ = current;
                tail_ = current;
                global_nodes_alive++;
                size_++;
            }
            else
            {
                current= new_node(original->data);
                tail_->next = current;
                tail_ = current;
                current = current->next;
                global_nodes_alive++;
                size_++;
                
            }
            original = original->next;
         }
        global_list_count++;
    }

    List::List(List&&list) noexcept
    {
        head_ = list.head_;
        tail_ = list.tail_;
        size_ = list.size();
        list.size_ = 0;
        list.tail_ = nullptr;
        list.head_ = nullptr;
        global_nodes_alive = list.global_nodes_alive;
        global_list_count++;


    }

    List::List(const int*array, int size)
    {
        Node* current = nullptr;
        global_list_count++;
        if (array == nullptr || size <=0)
        {
            throw std::runtime_error(error_messages::BAD_ARRAY);
        }
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                current = new_node(*(array + i));
                head_ = current;
                tail_ = current;
                global_nodes_alive++;
                size_++;
            }
            else
            {
                current->next = new_node(*(array + i));
                tail_ = current->next;
                current = current->next;
                global_nodes_alive++;
                size_++;
            }
        }
        

    }


    List::~List()
    {
        clear();
       
    }




    void CS170::List::push_front(int data)
    {
        Node* current = nullptr;

        if (head_ == nullptr)
        {
            current = new_node(data);
            head_ = current;
            tail_ = current;
            global_nodes_alive++;
            size_++;
        }
        else
        {
            current = new_node(data);
            current->next = head_;
            head_ = current;
            global_nodes_alive++;
            size_++;
        }


    }

    
    void CS170::List::push_back(int data)
    {
        Node* current=nullptr;
        if (head_ == nullptr)
        {
            current = new_node(data);
            head_ = current;
            tail_ = current;
            global_nodes_alive++;
            size_++;
        }
        else
        {
            current = new_node(data);
            tail_->next = current;
            tail_ = current;
            global_nodes_alive++;
            size_++;
        }
        


    }
    
    void CS170::List::pop()
    {
        if (size() <= 0)
        {
            throw std::runtime_error(error_messages::EMPTY_LIST);
        }

        else
        {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
            global_nodes_alive--;
            size_--;
        }
        
        
    }

    int CS170::List::front()
    {
        if (head_ != nullptr)
        {
            return head_->data;
        }
        else
        {
            throw std::runtime_error(error_messages::EMPTY_LIST);
        }
        
    }

     int CS170::List::size() const
    {
        return size_;
    }

     bool CS170::List::empty() const
    {
        if (head_ ==nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void CS170::List::clear()
    {
        while (head_ != nullptr)
        {
               pop();
        }
                
        
    }

    List& CS170::List::operator=(const List& list)
    {
        if (this == &list)
        {
            return *this;
        }
        clear();

        size_ = list.size_;
        Node*original=list.head_;
        Node* current = nullptr;
        list.global_nodes_alive += list.size_;
        while (original!=nullptr)
        {
            if (current == nullptr)
            {
                current = new_node(original->data);
                head_ = current;
                tail_ = current;
                                     
            }
            else
            {
                current->next = new_node(original->data);
                tail_ = current;
                current = current->next;
            }
            original = original->next;
        }
        return *this;

    }
    

    List& List::operator=(List&& list) noexcept
    {
        if (this == &list)
        {
            return *this;
        }
        clear();
        head_ = list.head_;
        tail_ = list.tail_;
        size_ = list.size();
        list.size_ = 0;
        list.tail_ = nullptr;
        list.head_ = nullptr;
        global_nodes_alive = list.global_nodes_alive;
        return *this;
    }

    List List::operator+(const List& other)
    {
        List temp = *this;
        int loop = other.size_;
        for (int i = 0; i < loop; i++)
            temp.push_back(other[i]);
        return temp;
    }
    
    List& List::operator+=(const List& other)
    {
           
        int loop = other.size_;
        for (int i = 0; i < loop; i++)
            push_back(other[i]);
        return *this;
    }

    int& List::operator[](int index) 
    {
        if (index < 0 || index>=size_)
        {
            throw std::runtime_error(error_messages::BAD_INDEX);
        }
        Node* current = head_;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    const int& CS170::List::operator[](int index) const
    {
        if (index < 0 || index >= size_)
        {
            throw std::runtime_error(error_messages::BAD_INDEX);
        }
        Node* current = head_;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;

    }


    int List::list_count() noexcept
    {
        return global_list_count;
    }

    int CS170::List::node_count() noexcept
    {
        return global_nodes_alive;
    }
    

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    // private methods
    // new_node and any more that you want to create
    List::Node* List::new_node(int data) const
    {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = nullptr;
        return newnode;
    }


    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    // non-member methods

    std::ostream& operator<<(std::ostream& os, const List& list)
    {
        // Start at the first node
        List::Node* current_node = list.head_;

        // Until we reach the end of the list
        while (current_node != nullptr)
        {
            os << std::setw(4) << current_node->data; // print the data in this node
            current_node = current_node->next;        // move to the next node
        }

        os << '\n'; // extra newline for readability
        return os;
    }

   

   
}
