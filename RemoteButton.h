#include "Pin.h"

class RemoteButton
{
public:
    RemoteButton(Pin p, uint8_t txCode) : m_pin(p),  m_txCode(txCode)
    {
        //do stuff? Maybe nothing to do
    };

    // If button is pressed return true
    bool read(){
        return m_pin.read() == 1; 
    }

    uint8_t getTxCode(){
        return m_txCode;
    }

private:
    Pin m_pin;
    uint8_t m_txCode;
    size_t m_holdTimer;
}