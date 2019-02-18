/*
 *Project: CDD Lab 3
 *Author: Niamh C
 *License: GNU
 *Description: Creation of a rendevous pattern using semaphores.Two threads with a shared semaphore are both assigned a task. Each thread must wait until both have arrived at the rendezvous point before continuing execution.
 */


#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \class Signal
    \brief An Implementation of a Rendezvous using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/

/*! \fn void TaskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore> secondSem, int delay)
    \brief taskOne is carried out by thread one.
    \param firstSem Semaphore object to indicate first arrival
    \param secondSem Semaphore object to indicate second arrival
    \param delay int to be used for sleep_for() function
*/

void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has arrived! "<< std::endl;
  //THIS IS THE RENDEZVOUS POINT!
  firstSem->Signal();
  std::cout << "Task One has left!"<<std::endl;
}

/*! \fn void TaskTwo(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore> secondSem, int delay)
    \brief taskTwo is carried out by thread two
    \param firstSem Semaphore object to indicate first arrival
    \param secondSem Semaphore object to indicate second arrival
    \param delay int to be used for sleep_for() function
*/

/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task Two has arrived "<<std::endl;
  //THIS IS THE RENDEZVOUS POINT!
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "Task Two has left "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
