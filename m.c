#include <stdio.h>

typedef unsigned short uint16_t;
typedef void (* f_t)(uint16_t);

#include "fundec1.h"
#include "fundec2.h"
#include "fundec3.h"
#include "fundec4.h"
#include "fundec5.h"
#include "fundec6.h"
#include "fundec7.h"

void mc_00_00(uint16_t w) {printf("%.4x\n", w);}
void mc_00_01(uint16_t w) {printf("00   01\n");}
//void mc_12_34(uint16_t w) {printf("12   34\n");}

static f_t fun_arr[65536] = {mc_00_00, mc_00_01, mc_00_02, mc_00_03};

void p(uint16_t w)
{
	fun_arr[w](w);
}

int main(int argc, char* argv[])
{
	fun_arr[0x3412] = mc_12_34;

	p(0);
	p(1);
	p(3);
	p(0x3412);

	printf("ok!\n");
	return 0;
}
