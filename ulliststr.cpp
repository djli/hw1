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

void ULListStr::push_back(const std::string& val){
  if(tail_ == NULL){
    head_ = tail_ = new Item;
    tail_->val[tail_->last] = val;
    ++tail_->last;
    ++size_;
  }
  else{
    if(tail_->last == ARRSIZE){
      tail_->next = new Item;
      tail_->next->prev = tail_;
      tail_ = tail_->next;
      tail_->val[tail_->last] = val;
      ++tail_->last;
      ++size_;
    }
    else{
      tail_->val[tail_->last] = val;
      ++tail_->last;
    }
  }
}

void ULListStr::pop_back(){
  if(tail_ == NULL){
    return;
  }
  else{
    tail_->val[--tail_->last] = "";
    if(tail_->last == tail_->first){
      if(tail_->prev == NULL){ //Last item is now empty, delete item and set head/tail pointers to NULL
        delete tail_;
        tail_ = NULL;
        head_ = NULL;
        --size_;
      }
      else{
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = NULL;
        --size_;
      }
    }
  }
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    head_ = tail_ = new Item;
    head_->val[head_->first] = val;
    ++head_->last;
    ++size_;
  }
  else{
    if(head_->first == 0 && head_->val[0] != ""){
      head_->prev = new Item;
      head_->prev->next = head_;
      head_ = head_->prev;
      head_->first = ARRSIZE;
      head_->last = ARRSIZE;
      head_->val[--head_->first] = val;
      ++size_;
    }
    else{
      head_->val[--head_->first] = val;
    }
  }
}

void ULListStr::pop_front(){
  if(head_ == NULL){
    return;
  }
  else{
    head_->val[head_->first] = "";
    ++head_->first;
    if(head_->first == head_->last){
      if(head_->next == NULL){ //Last item is now empty, delete item and set head/tail pointers to NULL
        delete head_;
        tail_ = NULL;
        head_ = NULL;
        --size_;
      }
      else{
        head_ = head_->next;
        delete head_->prev;
        head_->prev = NULL;
        --size_;
      }
    }
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

//get loc # element in the unrolled list
//shit gets weird when start of list is not at the first position of an array
//add first to loc or some shit to get an index location thats workable
std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* getter = head_;
  size_t index = (loc + head_->first)/10;
	for(size_t i = 0; i < index; i++){
		getter = getter->next;
	}
	return &getter->val[(loc + head_->first)%10];
}

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
