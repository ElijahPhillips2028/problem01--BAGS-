#include "DynamicBag.hpp"
#include <utility>

template<typename T>
DynamicBag<T>::DynamicBag() {
currentSize = 0;
  capacity = 10; 
  bagContainer = new T[capacity];

}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){
//coppy constuctor
  currentSize = x.currentSize;
  bagContainer = new T[currentSize];
  for (std::size_t i = 0; i < currentSize; i++) {
    bagContainer[i] = x.bagContainer[i];
  }

}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete[] bagContainer;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  

    swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){

  std::swap(bagContainer, x.bagContainer);
  std::swap(currentSize, x.currentSize);
  std::swap(capacity, x.capacity);
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if (currentSize >= capacity) {
    // allows for more space
    capacity *= 2;
    T* newContainer = new T[capacity];
    for (std::size_t i = 0; i < currentSize; i++) {
      newContainer[i] = bagContainer[i];
    }
    delete[] bagContainer;
    bagContainer = newContainer;
  }
  //add to the bag
  bagContainer[currentSize] = item;
  currentSize = currentSize + 1;
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  for(std::size_t i = 0; i < currentSize; i++) {
    //if the bag has the item
    if (bagContainer[i] == item) {
      //remvoce the ditem from the bag
      //set j = i for the same size
      for (std::size_t j = i; j < currentSize - 1; j++) {
        bagContainer[j] = bagContainer[j + 1];
      }
      //remove the bad item
      currentSize--;
      return true;  
    }
  }
  return false;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if(currentSize == 0){
      return true;
  }
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return currentSize;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  

  for(int i = 0 ; i < currentSize; i++){
      if(bagContainer[i] == item){
          return true;
      }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){
  currentSize = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  int amount = 0;
    for(int i = 0 ; i < currentSize; i++){
        if(bagContainer[i] == item){
            amount++;
        }
    }
  return amount;
};
