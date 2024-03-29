#pragma once
#include "predicate.h"
#include <cstdlib>
#include <algorithm>
#include <string>
#include <typeinfo>
#include <vector>
#include <list>

using namespace std;

template <class T, class Container>
class tContainer_t
{
    public:
        ~tContainer_t() {}
        tContainer_t() {}

        bool isEmpty() const;
        size_t getSize() const;
        void pushBack(const T* t);
        T* getFirst() const;
        T* getLast() const;
        T* findByValue(const T& t) const;
        T* removeByValue(const T& t);
        void removeAll();
        void deleteByValue(const T& t);
        void deleteAll();
        T* operator[](size_t index) const;

    private:
        tContainer_t(const tContainer_t& c);
        tContainer_t& operator=(const tContainer_t& c);

        Container container;

        typedef typename Container::iterator iter_t;
        typedef typename Container::const_iterator iterConst_t;
};


template <class T, class Container>
inline bool tContainer_t<T, Container>::isEmpty() const
{
    return container.empty();
}

template <class T, class Container>
inline size_t tContainer_t<T, Container>::getSize() const
{
    return container.size();
}

template <class T, class Container>
inline void tContainer_t<T, Container>::pushBack(const T* t)
{
    container.push_back((T*)t);
}

template <class T, class Container>
T* tContainer_t<T, Container>::getFirst() const
{
    if(isEmpty())
    {
        return 0;
    }
    return container.front();
}

template <class T, class Container>
T* tContainer_t<T, Container>::getLast() const
{
    if(isEmpty())
    {
        return 0;
    }
    return container.back();
}

template <class T, class Container>
T* tContainer_t<T, Container>::findByValue(const T& t) const
{
    iterConst_t it = find_if(container.begin(), container.end(), typename FindValue<T>::FindValue(t));

    return (it != container.end()) ? *it : 0;
}

template <class T, class Container>
T* tContainer_t<T, Container>::removeByValue(const T& t)
{
    iter_t it = find_if(container.begin(), container.end(), typename FindValue<T>::FindValue(t));
    
    if(it != container.end())
    {
        T* remVal = *it;
        container.erase(it);
        return remVal;
    }
    else
    {
        return 0;
    }    
}

template <class T, class Container>
inline void tContainer_t<T, Container>::removeAll()
{
    container.clear();
}

template <class T, class Container>
void tContainer_t<T, Container>::deleteByValue(const T& t)
{
    iter_t it = find_if(container.begin(), container.end(), typename FindValue<T>::FindValue(t));
    
    if(it != container.end())
    {
        delete *it;
        container.erase(it);
    }
}

template <class T, class Container>
void tContainer_t<T, Container>::deleteAll()
{
    for(iter_t it = container.begin(); it != container.end(); ++it)
    {
        delete *it;
    }

    container.clear();
}

template <class T, class Container>
T* tContainer_t<T, Container>::operator[](size_t index) const
{
    if(index < container.size())
    {
        if(typeid(Container) == typeid(vector<T*>))
        {
            return (*(vector<T*>*)&container)[index];
        }
        else if(typeid(Container) == typeid(list<T*>))
        {
            iterConst_t it = container.begin();
            advance(it, index);
            return *it;
        }
    }

    return 0;        
}