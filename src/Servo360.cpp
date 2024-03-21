/*
 * last updated By HuemoneLab, March 2024

 * This software is provided "AS IS" only for educational purpose using arduino kit made by Huemone Lab.
 * Unauthorized for copying, modifying, distributing of this code.

 * �� ���̺귯���� (��)�޸��� ������ �Ƶ��̳� ŰƮ�� �ǽ��� ���� ���۵Ǿ����ϴ�.
 * ���� ��� ���۱��� (��)�޸󷦿� �ֽ��ϴ�.
 * ŰƮ �ǽ��� ���� ������ �뵵�θ� ��� �� Ȱ���� �����ϸ�
 * �������� ����/����/������ϰų� �ڵ� ��ü Ȥ�� �Ϻθ� �ٸ� �뵵�� ����� �� ������ ��ġ�� ���� �� �ֽ��ϴ�.
 */

#ifndef HUEMONELAB_SERVO_360_CPP
#define HUEMONELAB_SERVO_360_CPP

#include "HuemonelabKit.h"

 /*
  * �������� ����
  * - Servo.h ��ü ����
  */
Servo360::Servo360() : Servo() {
    _angle = 90;
}

/*
 * �������� ����
 * - �� ����
 */
uint8_t Servo360::attach(uint8_t pin) {
    return Servo::attach(pin);
}

/*
 * �������� �۵� �ڵ�
 *   [����] �������� ������ �������� ���ϴ� �������� �����̸� �� �Ҹ��� �� �� ����
 */
void Servo360::write(int angle, int time = 0) {
    Servo::write(90);
    int val = angle < _angle ? 80 : (angle > _angle ? 100 : 90);
    Serial.println("   ");
    Serial.println(val);
    Servo::write(val);
    delay(time);
    //Servo::write(90);
    _angle = angle;
}

/*
 * �������͸� ������Ű�� �ڵ�
 */
void Servo360::stop() {
    Servo::write(90);
    _angle = 90;
}

/*
 * ���������� ���� ��(��Ȯ���� ������ �Է� ��)�� �о���� �ڵ�
 */

int Servo360::read() {
    return _angle;
}

/*
 * Servo.h �⺻ �Լ�
 * - ����: [Servo Library](https://www.arduino.cc/en/reference/servo)
 */
int Servo360::readMicroseconds() {
    return Servo::readMicroseconds();
}

bool Servo360::attached() {
    return Servo::attached();
}

void Servo360::writeMicroseconds(int angular_speed) {
    Servo::writeMicroseconds(angular_speed);
}


void Servo360::detach() {
    Servo::detach();
}

#endif