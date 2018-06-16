/*
 * pins.h
 *
 *  Created on: Feb 25, 2018
 *      Author: dongr
 */

#ifndef PINS_H_
#define PINS_H_

// pins
#define D0	2
#define D1	3
#define D2	4
#define D3	17
#define D4	27
#define D5	22
#define D6	10
#define D7	9
#define D8	11
#define D9	5
#define D10	6
#define D11	13
#define D12	19
#define D13	26
// sync pins CLI, HD, VD
#define S0	14
#define S1	15
#define S2	18


// data with struct
typedef struct {
	unsigned none :18;
	unsigned d13 :1;
	unsigned d12 :1;
	unsigned d11 :1;
	unsigned d10 :1;
	unsigned d9 :1;
	unsigned d8 :1;
	unsigned d7 :1;
	unsigned d6 :1;
	unsigned d5 :1;
	unsigned d4 :1;
	unsigned d3 :1;
	unsigned d2 :1;
	unsigned d1 :1;
	unsigned d0 :1;
} DataInBitType;

// for reading as int
typedef union {
	unsigned value;
	DataInBitType bits;
} DataIn;

#endif /* PINS_H_ */
