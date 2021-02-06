#include <array>

#include "IR_LED.h"
#include "RemoteButton.h"

int main(){

    // Setup IO
    IR_LED myIR_LED(GPIOx, GPIO_PIN_x);

    // Use an array for range based for loops, not vectors because we know the number of 
    // buttons at compile time. 
    std::array<RemoteButton, 2> buttonList = { RemoteButton(Pin(GPIOx, GPIO_PIN_x), 0xAA), 
                                               RemoteButton(Pin(GPIOx, GPIO_PIN_x), 0xBB) };

    while(1){

        // Read each pin and push out the tx code if pressed.
        // Might not want to use const? If we want to keep track of press and hold. 
        for(auto const &button : buttonList){
            if(button.read){
                myIR_LED.insertData(button.getTxCode()); // This button means to tell the TV to shutoff
            }
        }
        
        myIR_LED.run();

        //Could put uc to sleep here to save battery and wake on button press. 
    }


}