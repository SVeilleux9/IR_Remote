#include "IR_LED.h"
#include "Pin.h"


int main(){


    // Let STMCubeIDE do its thing here. 

    // my code
    IR_LED myIR_LED(GPIOx, GPIO_PIN_x);
    Pin button;

    while(1){

        if(button.read()){
            myIR_LED.insertData(0xC3); // This button means to tell the TV to shutoff
        }

        myIR_LED.run();

        //Could put uc to sleep here to save battery and wake on button press. 
    }


}