/* 
 * last updated By HuemoneLab, May 2023

 * This software is provided "AS IS" only for educational purpose using arduino kit made by Huemone Lab.
 * Unauthorized for copying, modifying, distributing of this code.

 * 본 라이브러리는 (주)휴몬랩이 제작한 아두이노 키트의 실습을 위해 제작되었습니다.
 * 따라서 모든 저작권은 (주)휴몬랩에 있습니다.
 * 키트 실습과 같은 교육적 용도로만 사용 및 활용이 가능하며
 * 무단으로 복사/수정/재배포하거나 코드 전체 혹은 일부를 다른 용도로 사용할 시 법적인 조치를 취할 수 있습니다.
 */

#ifndef HUEMONELAB_LIGHT_SENSOR_CPP
#define HUEMONELAB_LIGHT_SENSOR_CPP

#include "HuemonelabKit.h"

/*
 * Light sensor 세팅
 * - pinMode 설정
 */
LightSensor::LightSensor(uint8_t pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

/* 
 * Updated 12, December 2019
 * - Add parameter from and to value and return mapped value
 * Light sensor 값 읽기 (analog) 
 */
int LightSensor::read(int from = 0, int to = 1023)
{
  return map(analogRead(_pin), 0, 1023, from, to);
}

/* 
 * Light sensor 값 읽기 (digital) 
 */
int LightSensor::readDigital()
{
  return digitalRead(_pin);
}

#endif