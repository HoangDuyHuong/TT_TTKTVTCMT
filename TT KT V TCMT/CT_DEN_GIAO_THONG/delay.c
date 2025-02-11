#include "delay.h"


/*Function: delay_ms
 *input: Time need delay
 *return: No
*/
void delay_ms(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<125;j++);
}