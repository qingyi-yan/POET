#include <atomic>
#include <iostream>
#include "TATAS.h"

   void TATAS::lock() {
    while(true){
        while(state.load()){} //atomic read
        if(!atomic_exchange(&state, true))
            return;
       }
   }

   void TATAS::unlock() {
      state.store(false);
   }

   TATAS::TATAS(){
       state.store(false);
   }
