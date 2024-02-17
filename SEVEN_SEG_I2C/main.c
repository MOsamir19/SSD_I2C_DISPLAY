
/*==================******************************************================*
 *==================**   Author: Mohamed Samir Hashish      **================*
 *==================**               NTI                    **================*
 *==================******************************************================*/



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "UART_Interface.h"
#include "SSD_I2C.h"


int main()
{

	u8 data =0 ;
	u8 i =0 ;
	u8 arr[4] ={0} ;
	u8 error =0 ;
	u8 seg_coun =0 ;

	SEVEN_SEG_I2C_INIT();
	UART_VoidInit();


	SEVEN_SEG_I2C_DISPLAY(arr) ;

	while(1)
	{

/*---------------------------------------------------------*/
		/*Receive Char from UART*/
		error=UART_U8ReceiveChar(&data);

		/* error=0  Receive Char done
		 * or error=1  not Receive
		 **/

		if(error==0)
		{

			if(data>='0' &&data<='9')
			{

				if(seg_coun<4)
				{
					seg_coun++;
				}
				else if(seg_coun==4)
				{
					CLEAR_Array(arr);
					seg_coun =1 ;
				}
				/*end of if(seg_coun<4)*/

				for(i=3;i>0;i--)
				{
					arr[i]=arr[i-1];
				} /*end of ---- >  for(i=3;i>0;i--)*/

				arr[0]=(data-48) ;

			}
			else if(data=='C')/*Related to if(data>='0' &&data<='9')*/
			{
				CLEAR_Array(arr);
				seg_coun =0 ;
			}

		}/* end of ----->  if(error==0)*/

		SEVEN_SEG_I2C_DISPLAY(arr) ;


	}/* end of ----->  while(1)*/


	return 0 ;
}



