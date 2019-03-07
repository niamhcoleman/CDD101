#include "SafeBuffer.h"

//dont need to include vector etc again bc it is already included in safebuffer.h

SafeBuffer::SafeBuffer(){
  theMutex = std::make_shared<Semaphore>(1);
  theSemaphore=std::make_shared<Semaphore>(0);
}

int SafeBuffer::push(Event newEric){
  theMutex->Wait();
  theData.push_back(newEric);
  int size = theData.size();
  theSemaphore->Signal();
  theMutex->Signal();
  return size;
}

Event SafeBuffer::pop(){
  theSemaphore->Wait();
  theMutex->Wait();
  Event e = theData.back();
  theData.pop_back();
  theMutex->Signal();
  return e;
}
