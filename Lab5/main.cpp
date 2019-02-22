#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;

/** @brief An example of using a resusable barrier.
 *
 * displays a message that is split in to 2 sections to show how a rendezvous works
 * @return a message of a letter (A/B) appended to a number
 * @param i The number to be appended to A/B
 */

void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    theBarrier->wait();
    std::cout << "A"<< i;
    //Barrier
    theBarrier->wait();
//    Do second half of task
    std::cout<< "B" << i;
  }
  

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << std::endl ;
  return 0;
}
