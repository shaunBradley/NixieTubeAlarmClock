#ifndef DICTONARY_H
#define DICTONARY_H

template<typename TKey, typename TValue>
class Dictonary final
{
  public:
    Dictonary();    
    ~Dictonary();
    void Add(const TKey& key, TValue& value);
    void Remove(const TKey& key);
    TValue& operator [](const TKey& key);
    void Clear();
    int Count();
  private:
    int m_count;
    TKey m_key[];
    TValue m_value[];
};

#endif
