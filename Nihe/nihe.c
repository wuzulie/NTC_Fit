#include "nihe.h"
#include "math.h"

void nihe(double vol , double* tem )
{
	*tem = 0;
	*tem +=  FACTOR_1  * pow(vol, 30);
	*tem +=  FACTOR_2  * pow(vol, 29);
	*tem +=  FACTOR_3  * pow(vol, 28);
	*tem +=  FACTOR_4  * pow(vol, 27);
	*tem +=  FACTOR_5  * pow(vol, 26);
	*tem +=  FACTOR_6  * pow(vol, 25);
	*tem +=  FACTOR_7  * pow(vol, 24);
	*tem +=  FACTOR_8  * pow(vol, 23);
	*tem +=  FACTOR_9  * pow(vol, 22);
	*tem +=  FACTOR_10  * pow(vol, 21);
	*tem +=  FACTOR_11  * pow(vol, 20);
	*tem +=  FACTOR_12  * pow(vol, 19);
	*tem +=  FACTOR_13  * pow(vol, 18);
	*tem +=  FACTOR_14  * pow(vol, 17);
	*tem +=  FACTOR_15  * pow(vol, 16);
	*tem +=  FACTOR_16  * pow(vol, 15);
	*tem +=  FACTOR_17  * pow(vol, 14);
	*tem +=  FACTOR_18  * pow(vol, 13);
	*tem +=  FACTOR_19  * pow(vol, 12);
	*tem +=  FACTOR_20  * pow(vol, 11);
	*tem +=  FACTOR_21  * pow(vol, 10);
	*tem +=  FACTOR_22  * pow(vol, 9);
	*tem +=  FACTOR_23  * pow(vol, 8);
	*tem +=  FACTOR_24  * pow(vol, 7);
	*tem +=  FACTOR_25  * pow(vol, 6);
	*tem +=  FACTOR_26  * pow(vol, 5);
	*tem +=  FACTOR_27  * pow(vol, 4);
	*tem +=  FACTOR_28  * pow(vol, 3);
	*tem +=  FACTOR_29  * pow(vol, 2);
	*tem +=  FACTOR_30 * vol;
	*tem +=  FACTOR_31;

}
