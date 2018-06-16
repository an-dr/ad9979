/*
 * wire3.c
 *
 *  Created on: Feb 27, 2018
 *      Author: dongr
 */
#include <stdio.h>
#include <stdlib.h>
#include "wiringPi.h"
#include "wire3.h"


void wire3_init() {
	pinMode(PINsdata, OUTPUT);
	pinMode(PINsck, OUTPUT);
	pinMode(PINsl, OUTPUT);
	SCK1;
	SL1;
}


int write_3w(int addr12b, int data28b) {
	int d_bit;
	addr12b = addr12b & 0xfff;
	data28b = data28b & 0xfffffff;
	SL0;
	SCK0;
	D(0);
	long data = (data28b << 12) | addr12b;
	int i = 0;
	for (i = 0; i < 40; i += 1) {
		SCK0;
		d_bit = (data >> i) & 1;
		D(d_bit);
		SCK1;
//		D(d_bit);
	}
	SL1;
	return data28b;

	DataIn data_in;
	int r = read_in(&data_in);
	printf("%u\n", r);
}
