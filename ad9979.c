/*
 * ad9979.c
 *
 *  Created on: Feb 27, 2018
 *      Author: dongr
 */

#include "ad9979.h"


void ad9979Init(){
	wire3_init();
	ad9979_reset();


	//ad9979_h_pattern_groups
	write_3w(0x28, 0x1);
	//ad9979_HPAT_HBLKTOGGLE - ODD
	write_3w(0x800, 0x64000);
	write_3w(0x801, 0x3ffffff);
	write_3w(0x802, 0x3ffffff);
	//ad9979_HPAT_HBLKTOGGLE - EVEN
	write_3w(0x803, 0x64000);
	write_3w(0x804, 0x3ffffff);
	write_3w(0x805, 0x3ffffff);

	//HBLK Repeat Area Start Position AB, C
	write_3w(0x806, 0x0);
	write_3w(0x807, 0x0);

	//HBLK Patterns order
	write_3w(0x808, 0x0);
	//HBLK length in HBLK alteration modes.
	write_3w(0x809, 0x0);
	// HBLK start|end position used in pixel mixing modes.
	write_3w(0x80a, 0x0);
	// TEST_REG need 0
	write_3w(0x80b, 0x0);
	// Toggle Positions:
	//						CLPOB0_1/2;
	//						CLPOB1_1/2;
	//						PBLK0_1/2;
	//						PBLK1_1/2;
	write_3w(0x80c, 0xdc05a);
	write_3w(0x80d, 0x3ffffff);
	write_3w(0x80e, 0x3ffffff);
	write_3w(0x80f, 0x3ffffff);
	// .Toggle Positions

	//FIELD0: SCP0, SCP1;
	//		  SCP2, SCP3;
	//		  SCP4, SCP5;
	//		  SCP6, SCP7;
	//		  SCP8;
	write_3w(0x810, 0x1000000);
	write_3w(0x811, 0x1000800);
	write_3w(0x812, 0x1000800);
	write_3w(0x813, 0x1000800);
	write_3w(0x814, 0x800);
	//.FIELD0

	//Select HPAT0 for all regions:
	write_3w(0x815, 0x0);
	write_3w(0x816, 0x0);
	//.Select HPAT0 for all regions

	// TEST_REG need 0
	write_3w(0x817, 0x0);

	//CLPOB start polarity = HIGH
	write_3w(0x818, 0x1);
		//CLPOB masking set to highest SCP value (no mask):
	write_3w(0x819, 0x1000800);
	write_3w(0x81a, 0x1000800);
	write_3w(0x81b, 0x1000800);
	//.CLPOB masking set to highest SCP value (no mask)

	//PBLK start polarity = HIGH
	write_3w(0x81c, 0x1);
	//PBLK masking set to highest SCP value (no mask):
	write_3w(0x81d, 0x1000800);
	write_3w(0x81e, 0x0);
	write_3w(0x81f, 0x0);
	//.PBLK masking set to highest SCP value (no mask)

	//total number of Fields = 1
	write_3w(0x2a, 0x1);
	write_3w(0x2b, 0x0);//field select = FIELD0
	write_3w(0x2c, 0x0);//field select = FIELD0

	//AFE settings:
	int afe_set =
			(0 << 0)|//STANDBY 0..3
			(1 << 2)|//REFBUF_PWRDN
			(1 << 3)|//CLAMPENABLE
			(0 << 4)|//TESTMODE 0b00
			(0 << 6)|//PBLK_LVL
			(0 << 7)|//DCBYP
			(0 << 8);//CDSMODE 0..2
	write_3w(0x0, afe_set);

	//reset TGCORE
	write_3w(0x14, 0x1);

	//enable outputs
	write_3w(0x11, 0x1);
}

void ad9979_reset(){
	write_3w(0x10, 0x1);
}
