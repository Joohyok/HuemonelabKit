/*
 * last updated By HuemoneLab, March 2024
 */

#ifndef HUEMONELAB_SERVO_360_CPP
#define HUEMONELAB_SERVO_360_CPP

#include "HuemonelabKit.h"

 /*
  * �������� ����
  * - Servo.h ��ü ����
  */
Servo360::Servo360() {
    _sv = new Servo();
    _angle = 90;
}

/*
 * �������� ����
 * - �� ����
 */
uint8_t Servo360::attach(uint8_t pin) {
    return _sv->attach(pin);
}

/*
 * �������� �۵� �ڵ�
 *   [����] �������� ������ �������� ���ϴ� �������� �����̸� �� �Ҹ��� �� �� ����
 */
void Servo360::write(int angle, int time = 0) {
    _sv->write(90);
    int val = angle < _angle ? 80 : (angle > _angle ? 100 : 90);
    _sv->write(val);
    delay(time);
    if (time != 0) _sv->write(90);
    _angle = angle;
}

/*
 * �������͸� ������Ű�� �ڵ�
 */
void Servo360::stop() {
    _sv->write(90);
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
    return _sv->readMicroseconds();
}

bool Servo360::attached() {
    return _sv->attached();
}

void Servo360::writeMicroseconds(int angular_speed) {
    _sv->writeMicroseconds(angular_speed);
}


void Servo360::detach() {
    _sv->detach();
}

#endif