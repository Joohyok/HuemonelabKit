/*
 * last updated By HuemoneLab, 22 February 2024

 * This software is provided "AS IS" only for educational purpose using arduino kit made by Huemone Lab.
 * Unauthorized for copying, modifying, distributing of this code.

 * �� ���̺귯���� (��)�޸��� ������ �Ƶ��̳� ŰƮ�� �ǽ��� ���� ���۵Ǿ����ϴ�.
 * ���� ��� ���۱��� (��)�޸󷦿� �ֽ��ϴ�.
 * ŰƮ �ǽ��� ���� ������ �뵵�θ� ��� �� Ȱ���� �����ϸ�
 * �������� ����/����/������ϰų� �ڵ� ��ü Ȥ�� �Ϻθ� �ٸ� �뵵�� ����� �� ������ ��ġ�� ���� �� �ֽ��ϴ�.
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