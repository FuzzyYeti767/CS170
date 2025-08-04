// TODO Comment Header

#include "List.h"

#include <iomanip>
#include <stdexcept>

namespace CS170
{
    List::List()
    {
        global_list_count++;
    }

    List::List(const List &list)
    {
        global_list_count++;

        int size_of_list = list.size();
        for (unsigned int i = 0; i < size_of_list; i++)
        {
            push_back(list[i]);
        }
    }

    List::List(List &&list) noexcept
    {

        global_list_count++;
        head_ = list.head_;
        tail_ = list.tail_;
        size_ = list.size_;

        list.head_ = nullptr;
        list.tail_ = nullptr;
        list.size_ = 0;
        
    }

    List::List(const int *array, int size)
    {
        global_list_count++;
        if (size <= 0)
        {
            throw std::runtime_error(error_messages::BAD_ARRAY);
        }

        if (array == nullptr)
        {
            throw std::runtime_error(error_messages::BAD_ARRAY);
        }

        for (int i = 0; i < size; i++)
        {
            push_back(array[i]);
        }
      
    }

    List::~List()
    {

        
        while (head_ != nullptr)
        {
           pop();
        }
    }

    void List::push_front(int data)
    {
        if (head_ == nullptr)
        {
            List::Node *node = new_node(data);
            head_ = node;
            tail_ = node;
            global_nodes_alive++;
        }
        else
        {
            List::Node *temp = head_;
            List::Node *node = new_node(data);
            node->next = temp;
            head_ = node;

            global_nodes_alive++;
        }
    }

    void List::push_back(int data)
    {
        if (tail_ == nullptr)
        {
            List::Node *node = new_node(data);
            tail_ = node;
            head_ = node;
            global_nodes_alive++;
        }
        else
        {
            tail_->next = new_node(data);
            tail_ = tail_->next;
            global_nodes_alive++;
        }
    }

    void List::pop()
    {
        if (head_ == nullptr)
        {
            throw std::runtime_error(error_messages::EMPTY_LIST);
        }
        else
        {
            global_nodes_alive--;
            Node *temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }

    int List::front()
    {
        if (this->empty() == true)
        {
            throw std::runtime_error(error_messages::EMPTY_LIST);
        }
        else
        {
            return head_->data;
        }
    }

    int List::size() const
    {
        int size_count = 0;
        Node *temp = head_;
        while (temp != nullptr)
        {
            temp = temp->next;
            size_count++;
        }
        return size_count;
    }

    bool List::empty() const
    {
        if (head_ == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    List &List::operator=(const List &list)
    {
        if (this == &list)
        {
            return *this;
        }

        else
        {
            clean();
            for (int i = 0; i < list.size(); i++)
            {
                push_back(list[i]);
            }
            return *this;
        }
    }

    List &List::operator=(List &&list) noexcept
    {
        if (this == &list)
        {
            return *this;
        }
        else
        {
            clean();
            head_ = list.head_;
            tail_ = list.tail_;
            size_ = list.size_;

            list.head_ = nullptr;
            list.tail_ = nullptr;
            list.size_ = 0;
            global_nodes_alive = list.global_nodes_alive;
            return *this;
        }
    }

    List &List::operator+=(const List &list)
    {
        int size = list.size();
        for (int i = 0; i < size; i++)
        {
            push_back(list[i]);
        }
        return *this;
    }

    List List::operator+(const List &list)
    {
        List new_list = *this;
        int size=list.size();
        for (int i = 0; i < size; i++)
        {
            new_list.push_back(list[i]);
        }

        return new_list; // ✅ 이동 생성자 강제 호출됨 → count 증가
    }

    int &List::operator[](int index)
    {
        if (index < 0 || index > this->size() - 1)
        {
            throw std::runtime_error(error_messages::BAD_INDEX);
        }

        List::Node *temp = head_;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    const int &List::operator[](int index) const
    {
        List::Node *temp = head_;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    List::Node *List::new_node(int data) const
    {
        List::Node *new_node = new Node();
        new_node->next = nullptr;
        new_node->data = data;
        return new_node;
    }
    std::ostream &operator<<(std::ostream &os, const List &list)
    {
        // Start at the first node
        List::Node *current_node = list.head_;

        // Until we reach the end of the list
        while (current_node != nullptr)
        {
            os << std::setw(4) << current_node->data; // print the data in this node
            current_node = current_node->next;        // move to the next node
        }

        os << '\n'; // extra newline for readability
        return os;
    }

    void List::clean()
    {
         while (head_ != nullptr)
        {
               pop();
        }
    }
}
