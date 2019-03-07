#pragma once
#include "Event.h"
#include <vector>
#include "Semaphore.h"

class SafeBuffer {

private:
  std::vector<Event> theData;
  std::shared_ptr<Semaphore> theMutex;
  std::shared_ptr<Semaphore> theSemaphore;

public:
  SafeBuffer();
  int push(Event);
  Event pop();
  
};
