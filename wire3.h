/*
 * wire3.h
 *
 *  Created on: Feb 27, 2018
 *      Author: dongr
 */

#ifndef WIRE3_H_
#define WIRE3_H_

#define PINsdata 21
#define PINsck 20
#define PINsl 16

#define SL0 digitalWrite(PINsl,0)
#define SL1 digitalWrite(PINsl,1)
#define SCK0 digitalWrite(PINsck,0)
#define SCK1 digitalWrite(PINsck,1)
#define D(x) (digitalWrite(PINsdata,x))

int write_3w(int addr12b, int data28b);
void wire3_init();


#endif /* WIRE3_H_ */
