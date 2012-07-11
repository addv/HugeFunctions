#include <stdio.h>

typedef unsigned short uint16_t;
typedef void (* f_t)(uint16_t);

#include "fundef1.h"
#include "fundef2.h"
#include "fundef3.h"
#include "fundef4.h"
#include "fundef5.h"
#include "fundef6.h"
#include "fundef7.h"

void mc_00_00(uint16_t w) {printf("%.4x\n", w);}
void mc_00_01(uint16_t w) {printf("00   01\n");}
//void mc_12_34(uint16_t w) {printf("12   34\n");}

static f_t fun_arr[65536] = {mc_00_00, mc_00_01};

void p(uint16_t w)
{
	fun_arr[w](w);
}

int main(int argc, char* argv[])
{
	fun_arr[0x3412] = mc_12_34;

	p(0);
	p(1);
	p(0x3412);

	printf("ok!\n");
	return 0;
}
