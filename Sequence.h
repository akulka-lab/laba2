#pragma once

using namespace std;

template<typename T>

class Sequence
{
public:
    virtual void InsertAt(T item,int index);
    virtual Sequence<T>* Concat(Sequence<T>* list)const;
    virtual T Get(int index)const;
    virtual int GetLength()const;
    virtual void Remove(int index);
    virtual void Append(T item);
    virtual void Prepend(T item);
     virtual T GetFirst()const;
    virtual T GetLast() const;
    
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const;
};


