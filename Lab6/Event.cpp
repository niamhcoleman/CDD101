#include "Event.h"
#include <iostream>
#include <stdlib.h>

//iostream doesnt need .h bc its a cpp library
//event and stdlib does as they are c libs

//producing..
Event::Event(){
  eric = 'a'+rand()%26;
  std::cout<<eric<<std::endl;
}

bool Event::consume(){
  char betterEric=eric-32;
  std::cout<<betterEric;
}
