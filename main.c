#include<stdint.h>

//Cumulative moving average
int32_t cmavg(int32_t newDato, int32_t *lastAverage, int32_t *countAverage) {
    #define AVG_WINDOW 3 //SAMPLES TO AVERAGE
    int32_t average;
    //Ventana, en countAverage=0, lastAverage se cancela, dejan de influir datos anteriores.
    average = *lastAverage + (newDato - *lastAverage) / (*countAverage + 1); 
    *lastAverage = average;
    *countAverage = (*countAverage + 1) % AVG_WINDOW;

    return average;
}

static int32_t lastAverage=0, countAverage=0;  

main(){	
    	    
    //Example 3 number average        
    //(1200+2000+3000)/3 = 2000    
	int32_t average;	
	int32_t newDato;
			
	newDato = 1000;
	average=cmavg( newDato,
			&lastAverage, 
			&countAverage );
	
	printf("\navg:%ld", average);
	
	newDato = 2000;
	average=cmavg( newDato,
			&lastAverage, 
			&countAverage );				 
	
	printf("\navg:%ld", average);
	
	newDato = 3000;
	average=cmavg( newDato,
			&lastAverage, 
			&countAverage );
					 			
	printf("\navg:%ld", average);
				
}
