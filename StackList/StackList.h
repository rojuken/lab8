#ifndef _STACKLIST_
#define _STACKLIST_

#include <iostream>
#include<fstream>
#include "List.h"

using namespace std;

template <class T>
class TStackList
{
protected:
    TList<T> list;
public:
  TStackList();
  TStackList(TStackList<T>& _v);
  ~TStackList();

  TStackList<T>& operator =(TStackList<T>& _v);

  void Push(T d);
  T Get();

  bool IsEmpty() const;
  bool IsFull() const;

  int MinElem();
  int MaxElem();
  void LoadToFile();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TStackList<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TStackList<T1> &A);

  int Length();
};

template<class T1>
inline ostream& operator<<(ostream& ostr, const TStackList<T1>& A)
{
    return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TStackList<T1>& A)
{
    return istr >> A.list;
}

template<class T>
inline TStackList<T>::TStackList()
{
}

template<class T>
inline TStackList<T>::TStackList(TStackList<T>& _v)
{
    list = _v.list;
}

template<class T>
inline TStackList<T>::~TStackList()
{
}

template<class T>
inline TStackList<T>& TStackList<T>::operator=(TStackList<T>& _v)
{
    if (this == &_v)
        return *this;

    list = _v.list;
    return *this;
}

template<class T>
inline void TStackList<T>::Push(T d)
{
    list.InsFirst(d);
}

template<class T>
inline T TStackList<T>::Get()
{
    if (list.IsEmpty())
        throw new exception;

    T tmp = list.GetFirst()->GetData();
    list.DelFirst();

    return tmp;
}

template<class T>
inline bool TStackList<T>::IsEmpty() const
{
    return list.IsEmpty();
}

template<class T>
inline bool TStackList<T>::IsFull() const
{
    return list.IsFull();
}

template<class T>
inline int TStackList<T>::MinElem()
{
    int min = this->list.GetFirst()->GetData();
    int j = this->Length();
    for (int i = 0; i < j; i++)
    {
        int k = this->Get();
        if (k < min)
            min = k;
    }
    return min;
}

template<class T>
inline int TStackList<T>::MaxElem()
{
    int max = this->list.GetFirst()->GetData();
    int j = this->Length();
    for (int i = 0; i < j; i++)
    {
        int k = this->Get();
        if (k > max)
            max = k;
    }
    return max;
}

template<class T>
inline void TStackList<T>::LoadToFile()
{
    ofstream fout("StackList.txt");
    if (!fout)
        throw new exception;
    int j = this->Length();
    for (int i = 0; i < j; i++)
        fout << this->Get() << " ";
}

template<class T>
inline int TStackList<T>::Length()
{
    return list.GetCount();
}

#endif