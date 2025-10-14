#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> container_;
  int numChildren_;
  PComparator comparator_;

  int maxChild(size_t parentIndex);
  size_t getParent(size_t index);
  void print() const;
};

// Add implementation of member functions here

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty stack");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return container_[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty stack");
  }

  else if(size() == 1){
    container_.pop_back();
  }

  else{
    size_t currIndex = 0;
    container_[currIndex] = container_[size()-1];
    container_.pop_back();

    // std::cout << "before heapify" << std::endl;
    // print();

    while(currIndex < size()-1){
      if(maxChild(currIndex) != -1){
        size_t storeMaxChild = maxChild(currIndex);
        // std::cout << "Max child index: " << storeMaxChild << std::endl;
        // std::cout << "We're comparing: " << container_[currIndex] << " and " << container_[storeMaxChild] << std::endl;
        
        if(comparator_(container_[storeMaxChild], container_[currIndex])){
          // std::cout << "Before swapping, the values are: " << container_[currIndex] << " and " << container_[storeMaxChild] << std::endl;
          std::swap(container_[currIndex], container_[storeMaxChild]);
          currIndex = storeMaxChild;
          // std::cout << "Final value for currIndex: " << currIndex << std::endl;
        }

        else{
          break;
        } 
      }

      else{
        break;
      }
    }
  }

  // print();
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  numChildren_ = m;
  comparator_ = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  container_.push_back(item);
  std::size_t currIndex = size() - 1;

  while(currIndex > 0){
    //Trickle-up
    int parentIndex = getParent(currIndex);
    if(comparator_(container_[currIndex], container_[parentIndex])){
      //The comparator returns true then swap
      std::swap(container_[currIndex], container_[parentIndex]);
      currIndex = parentIndex;
    }

    else{
      break;
    }
  }

  // print();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return container_.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return container_.size();
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::maxChild(size_t parentIndex){
  size_t maxIndex = parentIndex*numChildren_ + 1; 
  // std::cout << "maxIndex in maxChild function: " << maxIndex << std::endl;
  if(maxIndex >= size()){
    return -1;
  }

  for(int i = 1; i < numChildren_; i++){
    size_t currChild = parentIndex*numChildren_+i+1;
    if(currChild < size() && comparator_(container_[currChild], container_[maxIndex])){
    //Check if the child exists by comparing it to the size() AND has higher priority than maxIndex content, 
    //then assign to maxIndex
      maxIndex = parentIndex * numChildren_ + i + 1;
    }
  }

  return maxIndex;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::getParent(size_t index){
  return (index-1)/numChildren_; 
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::print() const{
  typename std::vector<T>::const_iterator it;
  std::cout << "=== Heap Print Begin ===" << std::endl;
  for(it = container_.begin(); it != container_.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "=== Heap Print End ===" << std::endl;
}

#endif

