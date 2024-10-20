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

        }

        void insert (int pos, T e) override
        {
                    
        }

        void append(T e) override
        {
        
        }

        void prepend(T e) override
        {
        
        }

        T remove(int pos) override
        {
            
        }

        T get(int pos) override
        {
            
        }

        int search(T e) override
        {
            
        }

        bool empty() override
        {
            
        }

        int size() override
        {
            
        }

        T operator[](int pos)
        {
            
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list)
        {

        }
};