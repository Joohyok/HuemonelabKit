/*
 * last updated By HuemoneLab, 22 February 2024
 */


#ifndef HUEMONELAB_FAN_CPP
#define HUEMONELAB_FAN_CPP

#include "HuemonelabKit.h"

/*
 * 5V FAN ����
 * - pinMode ����
 */
FAN::FAN(uint8_t pin) {
	_pin = pin;
	pinMode(pin, OUTPUT);
}

/*
 * FAN �ѱ�
 * LOW ���� �־���� ������ ����
 */
void FAN::on() {
	digitalWrite(_pin, LOW);
}

/*
 * FAN ����
 * HIGH ���� �־���� ������ ����
 */
void FAN::off() {
	digitalWrite(_pin, HIGH);
}

#endif