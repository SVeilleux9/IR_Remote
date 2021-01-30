#include <deque>
#include <Pin.h>


class IR_LED{
public:
    IR_LED(Pin p) : Pin(p){
    }

    void insertData(uint8_t data){
        dataQueue.push_back(data);
    }

private:
    Pin outpin;
    std::deque<uint8_t> dataQueue;


    void run(){
        // early return if nothing to do.
        if(dataQueue.empty()){
            return;
        }

        uint8_t nextData = dataQueue.front();
        dataQueue.pop_front();

        if(nextData == 1){
            for(size_t i = 0; i < 22; i++){
                outpin.toggle(); // This would def lead to a bug. 
                delay_us(26); // RTOS sleep 1/38 kHz (this is actually 38.5 kHz close enough)
            }
        }else{
            outpin.setHigh(); // Just in case for some reason you end low.
            delay_us(500); // RTOS sleep 500 us
        }    

        return;
    }

}