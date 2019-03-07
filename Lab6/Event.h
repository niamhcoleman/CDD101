#pragma once
//no matter how many time it is included, it will only compile it once. To avoid errors.

class Event{
 private:
  char eric;
 public:
  Event();
  bool consume(); //true if consumes, false if something goes wrong  
};

