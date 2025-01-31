#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string const & ULListStr::back() const{

  return tail_->val[tail_->last-1];

}

std::string const & ULListStr::front() const{

  return head_->val[head_->first];


}

std::string* ULListStr::getValAtLoc(size_t loc) const{

  if(loc >= size_ || !head_){
    return NULL;
  }

 
return getValAtLocHelper(loc, head_, 0);

  
}

// helper recursive function

std::string* ULListStr::getValAtLocHelper(size_t loc, Item *currentNode, size_t index) const{


//empty case
  if(!currentNode){
    return NULL;
  }



  int totalElements = currentNode->last - currentNode->first;

//bounds checking
  if(loc < index+totalElements){
    return &currentNode->val[currentNode->first + (loc - index)];
  }

  return getValAtLocHelper(loc, currentNode->next, totalElements+index);




}





void ULListStr::push_front(const std::string& val){

// if array is full, create new node
  if (head_ == NULL || head_->first == 0){
    Item *pushItem = new Item();
    pushItem->next = head_;
    pushItem->prev = NULL;
    pushItem->first = ARRSIZE -1;
    pushItem->last = ARRSIZE;

    if(head_){
    head_->prev = pushItem;
    }
    else{
      tail_ = pushItem;
    }

    head_ = pushItem;


  }

  else{

    head_->first--;

  }

  head_->val[head_->first] = val;
  size_++;

}

void ULListStr::push_back(const std::string& val){

  // new node

  if (tail_ == NULL || tail_->last == ARRSIZE){
    Item *pushItem = new Item();
    pushItem->first = 0;
    pushItem->last = 0;
    pushItem->prev = tail_;
    pushItem->next = NULL;


    if(tail_){
        tail_->next = pushItem;
        }
        else{
          head_ = pushItem;
        }

      tail_ = pushItem;
 

  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;

}


void ULListStr::pop_back(){

  if(size_ == 0){
    return;
  }

  if (tail_ == NULL){
    return;
  }

size_--;
tail_->last--;


//deleting node

if(tail_->first == tail_->last){
  Item *temp = tail_;
  tail_ = tail_->prev;

  if(tail_ != NULL){
    tail_->next = NULL;
  }

  else{
    head_ = NULL;
  }

  delete temp;

}


}


void ULListStr::pop_front(){

    if(size_ == 0){
    return;
  }
  size_--;

  head_->first++;


//deleting node
if(head_->first == head_->last){
  Item *temp = head_;
  head_ = head_->next;

  if(head_ != NULL){
    head_->prev = NULL;
  }

  else{
    tail_ = NULL;
  }

  delete temp;

}


}

