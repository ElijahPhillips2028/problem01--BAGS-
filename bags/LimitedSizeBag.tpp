#include "LimitedSizeBag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  //set the size of the bag to zero
T bagContainer[0];
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  //check if the bag is not over 100
  if (currentSize >= maxsize){
      return false;
  }
  //add to the bag
  bagContainer[currentSize] = item;
  currentSize = currentSize + 1;
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  //go through the bag
  for (std::size_t i = 0; i < currentSize; i++) {
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
bool LimitedSizeBag<T>::isEmpty() const
{
  if(currentSize == 0){
      return true;
  }
  return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return currentSize;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  //gothrough the container and see if the item is there
  for(int i = 0 ; i < currentSize; i++){
      if(bagContainer[i] == item){
          return true;
      }
  }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  currentSize = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  int amount = 0;
    for(int i = 0 ; i < currentSize; i++){
        if(bagContainer[i] == item){
            amount++;
        }
    }
  return amount;
};
