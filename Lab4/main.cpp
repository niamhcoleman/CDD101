/*
 *Project: CDD Lab 4
 *Author: Niamh C
 *License: GNU
 *Description: Example of mutual exclusion using a semaphore
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/** @brief An implementation of mutual exclusion using semaphores
 *
 * Uses semaphores to implement mutual exclusion on a shared variable
 * i.e no shared/simultaneous access to the shared variable is allowed. 
 * 
 * @return updates the value of shared variable 
 * @param firstSem Semaphore object
 * @param numUpdates the number of times the sharedVariable is to the updated.
 */


/*! \mainpage Lab 4
 *
 * \section Mutual Exclusion
 *
 * This lab demonstrates mutual exclusion by implementing it on a shared variable i.e shared/simultaneous access is not allowed to the variable.
 */



void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){

 
  for(int i=0;i<numUpdates;i++){
    //UPDATE SHARED VARIABLE HERE!
    firstSem->Wait();
    sharedVariable++; 
    firstSem->Signal();
  }

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore);
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
