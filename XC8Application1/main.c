#include <avr/io.h>

int main(void)
{
	int counter=20;
	DDRA |= 0xFF;
	DDRD = 0x00; //Makes all pins of PORTD input

//	PORTC = 0xFC;
	while (1){
	
			
		
		PORTA |= (0 << PA4);   /* turn movement motors on */
		PORTA |= (1 << PA3);
		PORTA |= (0 << PA2);
		PORTA |= (1 << PA1);


		PORTA |= (1 << PA5);   /* turn on the water pump */


		PORTA |= (1 << PA6);   /* turn on the brush motor */
		
		
		if ((PINC & (1 << PC5)) ==1 ){   /* press on stop button */
			
			PORTA |= (0 << PA4);   /* turn movement motors on */
			PORTA |= (0 << PA3);
			PORTA |= (0 << PA2);
			PORTA |= (0 << PA1);


			PORTA |= (0 << PA5);   /* turn on the water pump */


			PORTA |= (0 << PA6);   /* turn on the brush motor */
			
		}
		
		if (counter < 1){  /* reach the end of the solar panels array */
			PORTA |= (0 << PA1);   /* stop all movement motors */
			PORTA |= (0 << PA2);
			PORTA |= (0 << PA3);
			PORTA |= (0 << PA4);
			
			PORTA |= (0 << PA5);   /* turn off the water pump */


			PORTA |= (0 << PA6);   /* turn off the brush motor */
			
			}else{
			
			if (PINC & (0 << PC4)){   /* press turn on button */
				
				PORTA |= (0 << PA4);   /* turn movement motors on */
				PORTA |= (1 << PA3);
				PORTA |= (0 << PA2);
				PORTA |= (1 << PA1);


				PORTA |= (1 << PA5);   /* turn on the water pump */


				PORTA |= (1 << PA6);   /* turn on the brush motor */
				
			}
		}
		if (PINC & (1 << PC7)){   /* calculate the number of the panel the robot is cleaning */
			counter --;
		}
	}
	
}


