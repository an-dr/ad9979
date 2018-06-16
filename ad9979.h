/*
 * ad9979.h
 *
 *  Created on: Feb 27, 2018
 *      Author: dongr
 */

#ifndef AD9979_H_
#define AD9979_H_

#include "wire3.h"

void ad9979Init();
void ad9979_reset();
void ad9979_h_pattern_groups(int num);
void ad9979_HPAT_HBLKTOGO5();

#endif /* AD9979_H_ */
