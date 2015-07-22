#include <iostream>
#include <cstddef>  //for ptrdiff_t
#include <stdlib.h> //for system("PAUSE")
//注意不能開放 namespace std; 否則會和std的iterator_traits相衝突
 
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::iterator_category    iterator_category;
    typedef typename Iterator::value_type           value_type;
    typedef typename Iterator::reference            reference;
    typedef typename Iterator::difference_type      difference_type;
    typedef typename Iterator::pointer              pointer;
};

//partial specialization for regular pointer

template <class T>
struct iterator_traits<T*>{
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef T&                          reference;
    typedef ptrdiff_t                   difference_type;
    typedef T*                          pointer;
};

template <class T>
struct iterator_traits<const T*>{
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef T&                          reference;
    typedef ptrdiff_t                   difference_type;
    typedef T*                          pointer;
};

template <class InputIterator>
typename iterator_traits<InputIterator>::value_type //return type
sum_nonempty(InputIterator first, InputIterator last){
    typename iterator_traits<InputIterator>::value_type result = *first++;
    for (;first != last; ++first)
        result += *first;
        
    return result;
}

template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type //return type
count(InputIterator first, InputIterator last, const T& x){
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for (; first != last; ++first)
        if (*first == n)
            ++n;        
    return n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n, input_iterator_tag){
    for (; n > 0; --n, ++i);
}

template <class RandomAccessIterator, class Distance>
void advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag){
    i += n;
}

template <class BidirectionalIterator, class Distance>
void advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag){
    if (n >= 0)
        for (; n > 0; --n, ++i);
    else
        for (; n < 0; ++n, --i);
}


//Top level (把上面幾個overload的advance函數包裝起來)
template <class Iterator, class Distance>
inline void advance(Iterator& i, Distance n){
    advance(i, n, iterator_traits<Iterator>::iterator_category());
}

int main(int argc, char *argv[])
{
  int ia[] = { 0, 1, 3, 3, 4 };
  int total = sum_nonempty(ia, ia+5);
  int c = count(ia, ia+5, 3);
  cout << "Total sum in array is " << total << endl;
  cout << "There are " << c << " \"3\" in the array!" << endl;
  
  cout << "The first element is " << *ia << endl;
  int* pi = &(ia[0]);
  advance(pi, 4);
  cout << "forward 4 steps in the array is " << *pi << endl;
  
  system("PAUSE");
  return 0;
}
