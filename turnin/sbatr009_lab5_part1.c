#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;

        unsigned char fuellevel;
        unsigned char sensor;

        sensor = 0x00;
        fuellevel = 0x00;

    /* Insert your solution below */
    while (1) {

            fuellevel = ~PINA & 0xFF;

           if(fuellevel == 0x00)  // For input: 0
           {
                sensor = 0x40;
           }
           if((fuellevel == 0x01) || (fuellevel == 0x02))  // For inputs: 1 and 2
           {
                sensor = 0x60;
           }
           if((fuellevel == 0x03) || (fuellevel == 0x04))  // For inputs: 3 and 4
           {
                sensor = 0x70;
           }
           if((fuellevel == 0x05) || (fuellevel == 0x06)) // For inputs: 5 and 6
           {
                sensor = 0x38;
           }
           if((fuellevel == 0x07) || (fuellevel == 0x08) || (fuellevel == 0x09)) // For inputs: 7 and 8 and 9
           {
                sensor = 0x3C;
           }
           if((fuellevel == 0x0A) || (fuellevel == 0x0B) || (fuellevel == 0x0C)) // For inputs: 10 and 11 and 12
           {
                sensor == 0x3E;
           }
           if((fuellevel == 0x0D) || (fuellevel == 0x0E) || (fuellevel == 0x0F)) // For inputs: 13 and 14 and 15
           {
                sensor = 0x3F;
           }

            PORTC = sensor;
    }

}

