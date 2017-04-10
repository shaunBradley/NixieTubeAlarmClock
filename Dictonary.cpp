#include "Dictonary.h"

template<typename TKey, typename TValue>
Dictonary<TKey, TValue>::Dictonary()
{
  this->m_count = 0;
}

template<typename TKey, typename TValue>
void Dictonary<TKey, TValue>::Add(const TKey& key, TValue& value)
{
  // keep pointer
  TKey* tempKey = this->m_key;
  TValue* tempValue = this->m_value;

  // make new array
  // normally I would double the array size but memory is limited
  this->m_key = new TKey[this->m_count + 1];
  this->m_value = new TValue[this->m_count + 1];

  // copy
  for(int i = 0; i < this->m_count; i++)
  {
    this->m_key[i] = tempKey[i];
    this->m_value[i] = tempValue[i];
  }

  // add new element
  this->m_key[this->m_count] = key;
  this->m_value[this->m_count] = value;

  // increment counter
  this->m_count++;

  // delete old array
  delete[] tempKey;
  delete[] tempValue;
}

template<typename TKey, typename TValue>
void Dictonary<TKey, TValue>::Remove(const TKey& key)
{
  // keep pointer
  TKey* tempKey = this->m_key;
  TValue* tempValue = this->m_value;

  // make new array 
  this->m_key = new TKey[m_count-1];
  this->m_value = new TValue[m_count-1];

  // copy
  for(int i = 0; i < m_count-1; i++)
  {
    this->m_key = tempKey[i];
    this->m_value = tempValue[i];
  }

  // decrement
  this->m_count--;

  delete[] tempKey;
  delete[] tempValue;
}

// indexer
template<typename TKey, typename TValue>
TValue& Dictonary<TKey, TValue>::operator [](const TKey& key)
{
  for(int i = 0; i < this->m_count; i++)
  {
    if(*this->m_key[i] == key)
    {
      return this->m_value[i];
    }
  }
}

template<typename TKey, typename TValue>
int Dictonary<TKey, TValue>::Count()
{
  return this->m_count;
}


template<typename TKey, typename TValue>
void Dictonary<TKey, TValue>::Clear()
{
  m_count = 0;
  delete[] this->m_key;
  delete[] this->m_value;
}

template<typename TKey, typename TValue>
Dictonary<TKey, TValue>::~Dictonary()
{
  this->m_count = 0;
  if (this->m_key)
  { delete[] this->m_key;}
  if(this->m_value)
  {delete[] this->m_value;}
}

