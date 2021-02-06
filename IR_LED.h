#include <deque>
#include <Pin.h>


class IR_LED{
public:
    IR_LED(Pin p) : Pin(p){
    }

    void insertData(uint8_t data){
        dataQueue.push_back(data);
    }

    void run(){
        
        while(!dataQueue.empty()){
            uint8_t nextData = dataQueue.front();
            dataQueue.pop_front(); // FIFO

            transmit(nextData);
        }
    
        return;
    }

private:
    Pin outpin;
    std::deque<uint8_t> dataQueue;

    void transmit(uint8_t data){
        txStart();
        // Loop through each bit and TX a 1 or 0
        for(auto i = 0; i < 8; i++){
            (data >> i) & 1 ? txOne() : txZero();
        }
    }

    void txOne(){
        for(size_t i = 0; i < 22; i++){
            outpin.toggle(); // This would def lead to a bug. 
            delay_us(26); // RTOS sleep 1/38 kHz (this is actually 38.5 kHz close enough)
        }
        outpin.setHigh(); // just to double check :)
    }

    void txZero(){
        outpin.setHigh(); // Just in case for some reason you end low.
        delay_us(500); // RTOS sleep 500 us
    }

    void txStart(){
        // I actually dont know the start bit for the IR remote. This needs to be updated. 
        outpin.setLow();
        delay_us(150);
        outpin.setHigh();
        delay_us(150);
    }
}