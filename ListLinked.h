#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> 
{
    private:
 
        Node<T>* first{};
        int n{};

    public:

        ListLinked()
        {
            first=nullptr;
            n=0;
        }

        ~ListLinked()
        {
            while (first != nullptr)
            {
                Node<T>* toDelete = first;
                first = first->next;
                delete toDelete;
            }
        }

        void insert (int pos, T e) override
        {
            if (pos < 0 || pos > n)
                throw std::out_of_range("Index out of range");
            if (pos == 0) 
                prepend(e);
            else
            {
                Node<T>* prev = first;
                for (int i = 1; i < pos; ++i)
                    prev = prev->next;
                prev->next = new Node<T>(e, prev->next);
                ++n;
            }
        }

        void append(T e) override
        {
            if (empty())
                first = new Node<T>(e, nullptr);
            else 
            {
                Node<T>* current = first;
                while (current->next != nullptr)
                    current = current->next;
                current->next = new Node<T>(e, nullptr);
            }
            ++n;
        }

        void prepend(T e) override
        {
            first = new Node<T>(e, first);
            ++n;
        }

        T remove(int pos) override
        {
            if (pos < 0 || pos >= n)
                throw std::out_of_range("Index out of range");
            Node<T>* toDelete;
            T value;
            if (pos == 0)
            {
                toDelete = first;
                first = first->next;
            } else
            {
                Node<T>* prev = first;
                for (int i = 1; i < pos; ++i)
                    prev = prev->next;
                toDelete = prev->next;
                prev->next = toDelete->next;
            }
            value = toDelete->value;
            delete toDelete;
            --n;
            return value;
        }

        T get(int pos) override
        {
            if (pos < 0 || pos >= n)
                throw std::out_of_range("Index out of range");
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i)
                current = current->next;
            return current->value;
        }

        int search(T e) override
        {
            Node<T>* current = first;
            for (int i = 0; i < n; ++i)
            {
                if (current->value == e)
                    return i;
                current = current->next;
            }
            return -1;
        }

        bool empty() override
        {
            return n == 0;
        }

        int size() override
        {
            return n;
        }

        T operator[](int pos)
        {
            return get(pos);
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
        {
            Node<T>* current = list.first;
            out << "[";
            while (current != nullptr)
            {
                out << current->value;
                if (current->next != nullptr)
                    out << ", ";
                current = current->next;
            }
            out << "]";
            return out;
        }
};