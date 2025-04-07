/*
 * last updated By HuemoneLab, May 2024
 *
 * Dependency : MD_MAX72XX by magicDesigns
 */

#ifndef HUEMONELAB_DOT_MATRIX_CPP
#define HUEMONELAB_DOT_MATRIX_CPP

#include "HuemonelabKit.h"

#define MAX_BUF 100

#define EMOJI_COUNT 70
const byte IMAGES[EMOJI_COUNT][8] = {
    {B00100100, // 1. heart 1
     B01111110,
     B11111111,
     B11111111,
     B11111111,
     B01111110,
     B00111100,
     B00011000},
    {B01100110, // 2. heart 2
     B10011001,
     B10000001,
     B10000001,
     B10000001,
     B01000010,
     B00100100,
     B00011000},
    {B00000000, // 3. smile
     B00100100,
     B00100100,
     B00100100,
     B00000000,
     B10000001,
     B01000010,
     B00111100},
    {B00000000, // 4. sad
     B00100100,
     B00100100,
     B00100100,
     B00000000,
     B00111100,
     B01000010,
     B10000001},
    {B00111100, // 5. happy face
     B01000010,
     B10100101,
     B10000001,
     B10100101,
     B10011001,
     B01000010,
     B00111100},
    {B00111100, // 6. sad face
     B01000010,
     B10100101,
     B10000001,
     B10011001,
     B10100101,
     B01000010,
     B00111100},
    {B00000000, // 7. smile 2
     B01000010,
     B10100101,
     B00000000,
     B00000000,
     B00000000,
     B00100100,
     B00011000},
    {B11111111, // 8. square smile
     B10000001,
     B10100101,
     B10000001,
     B10100101,
     B10011001,
     B10000001,
     B11111111},
    {B11111111, // 9. square sad
     B10000001,
     B10100101,
     B10000001,
     B10011001,
     B10100101,
     B10000001,
     B11111111},
    {B10000001, // 10. X
     B01000010,
     B00100100,
     B00011000,
     B00011000,
     B00100100,
     B01000010,
     B10000001},
    {B00011000, // 11. ◆
     B00111100,
     B01111110,
     B11111111,
     B11111111,
     B01111110,
     B00111100,
     B00011000},
    {B11111111, // 12. ■
     B11111111,
     B11111111,
     B11111111,
     B11111111,
     B11111111,
     B11111111,
     B11111111},
    {B00000000, // 13. small ■
     B00000000,
     B00111100,
     B00111100,
     B00111100,
     B00111100,
     B00000000,
     B00000000},
    {B00111100, // 14. ●
     B01111110,
     B11111111,
     B11111111,
     B11111111,
     B11111111,
     B01111110,
     B00111100},
    {B00000000, // 15. small ●
     B00000000,
     B00011000,
     B00111100,
     B00111100,
     B00011000,
     B00000000,
     B00000000},
    {B00000000, // 16. ▲
     B00001000,
     B00011100,
     B00111110,
     B01111111,
     B00000000,
     B00000000,
     B00000000},
    {B00000000, // 17. small ▲
     B00000000,
     B00010000,
     B00111000,
     B01111100,
     B00000000,
     B00000000,
     B00000000},
    {B00000000, // 18. ▶
     B00100000,
     B00110000,
     B00111000,
     B00111100,
     B00111000,
     B00110000,
     B00100000},
    {B00000000, // 19. ◀
     B00000100,
     B00001100,
     B00011100,
     B00111100,
     B00011100,
     B00001100,
     B00000100},
    {B01100000, // 20. >>
     B00110000,
     B00011000,
     B00001100,
     B00001100,
     B00011000,
     B00110000,
     B01100000},
    {B00000110, // 21. <<
     B00001100,
     B00011000,
     B00110000,
     B00110000,
     B00011000,
     B00001100,
     B00000110},
    {B10011001, // 22. ※
     B01011010,
     B00100100,
     B11011011,
     B11011011,
     B00100100,
     B01011010,
     B10011001},
    {B00100100, // 23. #
     B00100100,
     B11111111,
     B00100100,
     B00100100,
     B11111111,
     B00100100,
     B00100100},
    {B00011000, // 24. !
     B00011000,
     B00011000,
     B00011000,
     B00011000,
     B00000000,
     B00011000,
     B00011000},
    {B00011000, // 25. ?
     B00111100,
     B00100100,
     B00001100,
     B00011000,
     B00011000,
     B00000000,
     B00011000},
    {B00011000, // 26. +
     B00011000,
     B00011000,
     B11111111,
     B11111111,
     B00011000,
     B00011000,
     B00011000},
    {B00000000, // 27. -
     B00000000,
     B00000000,
     B11111111,
     B11111111,
     B00000000,
     B00000000,
     B00000000},
    {B00011000, // 28. /(divide)
     B00011000,
     B00000000,
     B11111111,
     B11111111,
     B00000000,
     B00011000,
     B00011000},
    {B11000011, // 29. %
     B11000111,
     B00001110,
     B00011100,
     B00111000,
     B01110000,
     B11100011,
     B11000011},
    {B11000011, // 30. *
     B11100111,
     B01111110,
     B00111100,
     B00111100,
     B01111110,
     B11100111,
     B11000011},
    {B00000000, // 31. =
     B11111111,
     B11111111,
     B00000000,
     B00000000,
     B11111111,
     B11111111,
     B00000000},
    {B00010000, // 32. $
     B00111100,
     B01010000,
     B01010000,
     B00111000,
     B00010100,
     B00010100,
     B01111000},
    {B00000000, // 33. ♠
     B00010000,
     B00111000,
     B01111100,
     B11111110,
     B01010100,
     B00010000,
     B00111000},
    {B00011000, // 34. →
     B00001100,
     B00000110,
     B11111011,
     B11111011,
     B00000110,
       B00001100,
     B00011000},
    {B00011000, // 35. ←
     B00110000,
     B01100000,
     B11011111,
     B11011111,
     B01100000,
     B00110000,
     B00011000},
    {B00011000, // 36. ↑
     B00111100,
     B01100110,
     B11011011,
     B10011001,
     B00011000,
     B00011000,
     B00011000},
    {B00011000, // 37. ↓
     B00011000,
     B00011000,
     B10011001,
     B11011011,
     B01100110,
     B00111100,
     B00011000},
    {B00000000, // 38. ↔
     B00100100,
     B01000010,
     B11111111,
     B01000010,
     B00100100,
     B00000000,
     B00000000},
    {B00011111, // 39. ↗
     B00000011,
     B00000101,
     B00001001,
     B00010001,
     B00100000,
     B01000000,
     B10000000},
    {B00000001, // 40. ↙
     B00000010,
     B00000100,
     B10001000,
     B10010000,
     B10100000,
     B11000000,
     B11111000},
    {B11111000, // 41. ↖
     B11000000,
     B10100000,
     B10010000,
     B10001000,
     B00000100,
     B00000010,
     B00000001},
    {B10000000, // 42. ↘
     B01000000,
     B00100000,
     B00010001,
     B00001001,
     B00000101,
     B00000011,
     B00011111},
    {B11111111, // 43. insta
     B10000001,
     B10011001,
     B10100101,
     B10100101,
     B10011001,
     B10000001,
     B11111111},
    {B00011100, // 44. facebook
     B00100000,
     B00100000,
     B01111000,
     B00100000,
     B00100000,
     B00100000,
     B00100000},
    {B00000000, // 45. youtube
     B00000000,
     B11111111,
     B11101111,
     B11100111,
     B11101111,
     B11111111,
     B00000000},
    {B00000000, // 46. tel
     B11100000,
     B11100000,
     B11000000,
     B01100000,
     B00110010,
     B00011110,
     B00001110},
    {B11111111, // 47. message
     B01111110,
     B10111101,
     B11011011,
     B11100111,
     B11111111,
     B11111111,
     B11111111},
    {B01110000, // 48. 돋보기
     B10001000,
     B10001000,
     B10001000,
     B01111000,
     B00000100,
     B00000010,
     B00000001},
    {B00000000, // 49. check
     B00000001,
     B00000011,
     B00000110,
     B10001100,
     B11011000,
     B01110000,
     B00100000},
    {B00111000, // 50. location
     B01000100,
     B10111010,
     B10111010,
     B10000010,
     B01000100,
     B00101000,
     B00010000},
    {B00011000, // 51. user
     B00111100,
     B00011000,
     B00000000,
     B00111100,
     B01111110,
     B01111110,
     B01111110},
    {B00011000, // 52. home
     B00111100,
     B01111110,
     B11111111,
     B11111111,
     B11100111,
     B11100111,
     B11100111},
    {B00111100, // 53. ben
     B01000110,
     B10001111,
     B10011101,
     B10111001,
     B11110001,
     B01100010,
     B00111100},
    {B10000001, // 54. sun
     B01000010,
     B00011000,
     B00111100,
     B00111100,
     B00011000,
     B01000010,
     B10000001},
    {B00000000, // 55. cloud
     B00000110,
     B01001111,
     B11111111,
     B11111111,
     B00000000,
     B00000000,
     B00000000},
    {B00000010, // 56. rain
     B01000111,
     B11111111,
     B11111111,
     B00000000,
     B01010100,
     B01010100,
     B01010100},
    {B00000010, // 57. snow
     B01000111,
     B11111111,
     B11111111,
     B00000000,
     B01000010,
     B00101000,
     B10000010},
    {B00000000, // 58. car
     B00000000,
     B00111100,
     B00101100,
     B11111111,
     B11111111,
     B00100100,
     B00000000},
    {B00000000, // 59. ♬
     B00111110,
     B00111110,
     B00100010,
     B00100010,
     B01100110,
     B01100110,
     B00000000},
    {B00000000, // 60. ♪
     B00011000,
     B00011100,
     B00010000,
     B00010000,
     B00110000,
     B01110000,
     B00100000},
    {B00011000, // 61. flag
     B00011100,
     B00011000,
     B00010000,
     B00010000,
     B01110000,
     B01110000,
     B00000000},
    {B00111100, // 62. ◎
     B01000010,
     B10011001,
     B10100101,
     B10100101,
     B10011001,
     B01000010,
     B00111100},
    {B00000000, // 63. 물방울
     B00001000,
     B00011100,
     B00111110,
     B00111110,
     B00111110,
     B00011100,
     B00000000},
    {B00010000, // 64.(
     B00100000,
     B01000000,
     B01000000,
     B01000000,
     B01000000,
     B00100000,
     B00010000},
    {B00001000, // 65. )
     B00000100,
     B00000010,
     B00000010,
     B00000010,
     B00000010,
     B00000100,
     B00001000},
    {B00001111, // 66. half 1
     B00001111,
     B00001111,
     B00001111,
     B00001111,
     B00001111,
     B00001111,
     B00001111},
    {B00000001, // 67. half 2
     B00000011,
     B00000111,
     B00001111,
     B00011111,
     B00111111,
     B01111111,
     B11111111},
    {B01010101, // 68. dot 1
     B10101010,
     B01010101,
     B10101010,
     B01010101,
     B10101010,
     B01010101,
     B10101010},
    {B11011011, // 69. dot 2
     B11011011,
     B00000000,
     B11011011,
     B11011011,
     B00000000,
     B11011011,
     B11011011},
    {B10000001, // 70. dot 3
     B11000011,
     B11100111,
     B11111111,
     B11111111,
     B11100111,
     B11000011,
     B10000001} };

void DotMatrix::print(char val) {
    uint8_t buf[8] = { 0, };
    uint8_t len_val = _mx.getChar(val, 8, buf);
    uint8_t space = (8 - len_val) / 2;
    _mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
    for (uint8_t i = 0; i < 8; i++) _mx.setColumn(i, 0);
    for (uint8_t i = 0; i < 8; i++) _mx.setColumn(7 - space - i, buf[i]);
    _mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
}

void DotMatrix::printScroll(const char* pText, textEffect dir = left) {
    uint8_t buf[MAX_BUF] = { 0, };
    char* textptr = (char*)pText;
    uint8_t buf_cur = 1;
    while (*textptr != '\0') {
        uint8_t len_val = _mx.getChar(*textptr, 8, &buf[buf_cur]);
        buf_cur += (len_val + 1);
        textptr++;
    }
    uint32_t prevTimeAnim = millis();
    uint8_t frame = 0;
    while (frame < buf_cur) {
        if (millis() - prevTimeAnim > 75) {
            _mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
            for (uint8_t i = 0; i < 8; i++) _mx.setColumn(i, 0);
            if (dir) for (uint8_t i = 0; i < 8; i++) _mx.setColumn(7 - i, buf[i + frame]);
            else for (uint8_t i = 0; i < 8; i++) _mx.setColumn(7 - i, buf[buf_cur - frame + i - 1]);
            _mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
            frame++;
            prevTimeAnim = millis();
        }
    }
}

void DotMatrix::print(const char* pText) {
    if (pText[1] == '\0') print(*pText);
    else printScroll(pText, 1);
}

void DotMatrix::printImage(const byte images[8]) {
    _mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
    for (uint8_t i = 0; i < 8; i++) _mx.setColumn(i, 0);
    for (uint8_t i = 0; i < 8; i++) _mx.setRow(7 - i, images[7 - i]);
    _mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
}

void DotMatrix::printEmoji(int num) {
    if (num > EMOJI_COUNT || num <= 0)
        return;

    // 이모티콘을 가져온 후 회전
    byte rotatedImage[8];
    const byte* originalImage = IMAGES[num - 1];
    
    // 180도 회전
    for (int i = 0; i < 8; i++) {
        rotatedImage[i] = originalImage[7 - i]; // 각 행을 반전
    }

    printImage(rotatedImage); // 회전된 이미지를 출력
}

#endif