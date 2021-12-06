/*
 *  Simple sample code
 *  For the ESP_ANSI_Art github repo -> https://github.com/N0NameN0/ESP_ANSI_Art
 *  Author : NoNameNo AKA Antoine Santo 2021
 */

#include <TFT_eSPI.h>
#include "font.h"



TFT_eSPI tft = TFT_eSPI();


uint bgcol=ANSI_0;
uint ftcol=ANSI_F;
uint POSX=1;
uint POSY=1;




void setup() {
  tft.init();
  tft.fillScreen(ANSI_0);
  ANSIPOS(2,2);
  PRINT("Hello World");
  delay(1000);
  
  ANSIPOS(5,4);
  PRINT("@X4AHello World");  // Will output Bright Green on Red
  delay(1000);

  ANSIPOS(7,8);
  PRINT("@X1EHello World");  // Will output Bright Yellow on Bleu
  delay(1000);

  ANSIPOS(1,9);
  PRINTLN("@X0A███▀      ███       @X28██▓@X08▀▀▀@X28▓█@X08▄");
  PRINTLN("@X0A███▀▀▀██▄ ███▀▀     @X28██▒@X0F █ @X2F▒█▓");
  PRINTLN("@X28▓▒@X0A█ @X0F█ @X0A█@X2A▒░@X08 @X28▓▒@X0A█ @X0F█ @X0A▄▄▄ @X28█▓░@X0F █ @X2F░▓▒");
  PRINTLN("@X28█▓░@X0F █ @X2F░▓▒@X08 @X28█▓░@X0F █ @X2F░▓▒@X08 @X28▓▒@X0A█ @X0F█ @X0A▄▄▄");
  PRINTLN("@X28██▒@X0F █ @X2F▒█▓@X08 @X28██▒@X0F █ @X2F▒█▓@X08 @X0A███ @X0F█ @X0A███");
  PRINTLN("@X28██▓@X08▄▄▄@X28▓█@X08▀ @X28██▓@X08▄▄▄@X28▓█@X08▀ @X0A▀██▄▄▄██▀");

}



void loop() {
  delay(500);
}



/*==========================================================================================
*
* ESP_ANSI_Art functions under this line ;) ;)
* 
==========================================================================================*/


void PRINTLN(char* s){
  PRINT(s);
  POSX=1;
  POSY++;
}

void ANSIPOS( int x, int y){
  POSX=x;
  POSY=y;
}


void PRINT(char* s){
  char curchar;

  for(int i=0;i<strlen(s);i++){
    if(s[i] == '@' && s[i+1]== 'X'){
      switch(s[i+2]){
        case 0x30 : bgcol = ANSI_0; break;
        case 0x31 : bgcol = ANSI_1; break;
        case 0x32 : bgcol = ANSI_2; break;
        case 0x33 : bgcol = ANSI_3; break;
        case 0x34 : bgcol = ANSI_4; break;
        case 0x35 : bgcol = ANSI_5; break;
        case 0x36 : bgcol = ANSI_6; break;
        case 0x37 : bgcol = ANSI_7; break;
      }
      switch(s[i+3]){
        case 0x30 : ftcol = ANSI_0; i+=3; break;
        case 0x31 : ftcol = ANSI_1; i+=3; break;
        case 0x32 : ftcol = ANSI_2; i+=3; break;
        case 0x33 : ftcol = ANSI_3; i+=3; break;
        case 0x34 : ftcol = ANSI_4; i+=3; break;
        case 0x35 : ftcol = ANSI_5; i+=3; break;
        case 0x36 : ftcol = ANSI_6; i+=3; break;
        case 0x37 : ftcol = ANSI_7; i+=3; break;
        case 0x38 : ftcol = ANSI_8; i+=3; break;
        case 0x39 : ftcol = ANSI_9; i+=3; break;
        case 0x41 : ftcol = ANSI_A; i+=3; break;
        case 0x42 : ftcol = ANSI_B; i+=3; break;
        case 0x43 : ftcol = ANSI_C; i+=3; break;
        case 0x44 : ftcol = ANSI_D; i+=3; break;
        case 0x45 : ftcol = ANSI_E; i+=3; break;
        case 0x46 : ftcol = ANSI_F; i+=3; break;
      }
    }
    else{
      switch(s[i]){
        case 0xC2:
          switch(s[i+1]){
            case 0xA1: curchar = 173; i++; break; // ¡
            case 0xA2: curchar = 155; i++; break; // ¢
            case 0xA3: curchar = 156; i++; break; // £
            case 0xA5: curchar = 157; i++; break; // ¥
            case 0xAA: curchar = 166; i++; break; // ª
            case 0xAB: curchar = 174; i++; break; // «
            case 0xAC: curchar = 170; i++; break; // ¬
            case 0xB0: curchar = 248; i++; break; // °
            case 0xB1: curchar = 241; i++; break; // ±
            case 0xB2: curchar = 253; i++; break; // ²
            case 0xB5: curchar = 230; i++; break; // µ
            case 0xB7: curchar = 250; i++; break; // ·
            case 0xBA: curchar = 167; i++; break; // º
            case 0xBB: curchar = 175; i++; break; // »
            case 0xBC: curchar = 172; i++; break; // ¼
            case 0xBD: curchar = 171; i++; break; // ½
            case 0xBF: curchar = 168; i++; break; // ¿
          }
          break;
        case 0xC3:
          switch(s[i+1]){
            case 0x84: curchar = 142; i++; break; // Ä
            case 0x85: curchar = 143; i++; break; // Å
            case 0x86: curchar = 146; i++; break; // Æ
            case 0x87: curchar = 128; i++; break; // Ç
            case 0x89: curchar = 144; i++; break; // É
            case 0x91: curchar = 165; i++; break; // Ñ
            case 0x96: curchar = 153; i++; break; // Ö
            case 0x9C: curchar = 154; i++; break; // Ü
            case 0x9F: curchar = 225; i++; break; // ß
            case 0xA0: curchar = 133; i++; break; // à
            case 0xA1: curchar = 160; i++; break; // á
            case 0xA2: curchar = 131; i++; break; // â
            case 0xA4: curchar = 132; i++; break; // ä
            case 0xA5: curchar = 134; i++; break; // å
            case 0xA6: curchar = 145; i++; break; // æ
            case 0xA7: curchar = 135; i++; break; // ç
            case 0xA8: curchar = 138; i++; break; // è
            case 0xA9: curchar = 130; i++; break; // é
            case 0xAA: curchar = 136; i++; break; // ê
            case 0xAB: curchar = 137; i++; break; // ë
            case 0xAC: curchar = 141; i++; break; // ì
            case 0xAD: curchar = 161; i++; break; // í
            case 0xAE: curchar = 140; i++; break; // î
            case 0xAF: curchar = 139; i++; break; // ï
            case 0xB1: curchar = 164; i++; break; // ñ
            case 0xB2: curchar = 149; i++; break; // ò
            case 0xB3: curchar = 162; i++; break; // ó
            case 0xB4: curchar = 147; i++; break; // ô
            case 0xB6: curchar = 148; i++; break; // ö
            case 0xB7: curchar = 246; i++; break; // ÷
            case 0xB9: curchar = 151; i++; break; // ù
            case 0xBA: curchar = 163; i++; break; // ú
            case 0xBB: curchar = 150; i++; break; // û
            case 0xBC: curchar = 129; i++; break; // ü
            case 0xBF: curchar = 152; i++; break; // ÿ
          }
          break;
        case 0xC6:
          switch(s[i+1]){
            case 0x92: curchar = 159; i++; break; // ƒ
          }
          break;
        case 0xCE:
          switch(s[i+1]){
            case 0x93: curchar = 226; i++; break; // Γ
            case 0x98: curchar = 233; i++; break; // Θ
            case 0xA3: curchar = 228; i++; break; // Σ
            case 0xA6: curchar = 232; i++; break; // Φ
            case 0xA9: curchar = 234; i++; break; // Ω
            case 0xB1: curchar = 224; i++; break; // α
            case 0xB4: curchar = 235; i++; break; // δ
            case 0xB5: curchar = 238; i++; break; // ε
          }
          break;
        case 0xCF:
          switch(s[i+1]){
            case 0x80: curchar = 227; i++; break; // π
            case 0x83: curchar = 229; i++; break; // σ
            case 0x84: curchar = 231; i++; break; // τ
            case 0x86: curchar = 237; i++; break; // φ
          }
          break;
        case 0xE2:
          switch(s[i+1]){
            case 0x81:
              switch(s[i+2]){
                case 0xBF: curchar = 252; i+=2; break; // ⁿ
              }
              break;
            case 0x82:
              switch(s[i+2]){
                case 0xA7: curchar = 158; i+=2; break; // ₧
              }
              break;
            case 0x88:
              switch(s[i+2]){
                case 0x99: curchar = 249; i+=2;break; // ∙
                case 0x9A: curchar = 251; i+=2;break; // √
                case 0x9E: curchar = 236; i+=2;break; // ∞
                case 0xA9: curchar = 239; i+=2;break; // ∩
              }
              break;
            case 0x89:
              switch(s[i+2]){
                case 0x88: curchar = 247; i+=2;break; // ≈
                case 0xA1: curchar = 240; i+=2;break; // ≡
                case 0xA4: curchar = 243; i+=2;break; // ≤
                case 0xA5: curchar = 242; i+=2;break; // ≥
              }
              break;
            case 0x8C:
              switch(s[i+2]){
                case 0x90: curchar = 169; i+=2;break; // ⌐
                case 0xA0: curchar = 244; i+=2;break; // ⌠
                case 0xA1: curchar = 245; i+=2;break; // ⌡
              }
              break;
            case 0x94:
              switch(s[i+2]){
                case 0x80: curchar = 196; i+=2;break; // ─
                case 0x82: curchar = 179; i+=2;break; // │
                case 0x8C: curchar = 218; i+=2;break; // ┌
                case 0x90: curchar = 191; i+=2;break; // ┐
                case 0x94: curchar = 192; i+=2;break; // └
                case 0x98: curchar = 217; i+=2;break; // ┘
                case 0x9C: curchar = 195; i+=2;break; // ├
                case 0xA4: curchar = 180; i+=2;break; // ┤
                case 0xAC: curchar = 194; i+=2;break; // ┬
                case 0xB4: curchar = 193; i+=2;break; // ┴
                case 0xBC: curchar = 197; i+=2;break; // ┼
              }
              break;
            case 0x95:
              switch(s[i+2]){
                case 0x90: curchar = 205; i+=2;break; // ═
                case 0x91: curchar = 186; i+=2;break; // ║
                case 0x92: curchar = 213; i+=2;break; // ╒
                case 0x93: curchar = 214; i+=2;break; // ╓
                case 0x94: curchar = 201; i+=2;break; // ╔
                case 0x95: curchar = 184; i+=2;break; // ╕
                case 0x96: curchar = 183; i+=2;break; // ╖
                case 0x97: curchar = 187; i+=2;break; // ╗
                case 0x98: curchar = 212; i+=2;break; // ╘
                case 0x99: curchar = 211; i+=2;break; // ╙
                case 0x9A: curchar = 200; i+=2;break; // ╚
                case 0x9B: curchar = 190; i+=2;break; // ╛
                case 0x9C: curchar = 189; i+=2;break; // ╜
                case 0x9D: curchar = 188; i+=2;break; // ╝
                case 0x9E: curchar = 198; i+=2;break; // ╞
                case 0x9F: curchar = 199; i+=2;break; // ╟
                case 0xA0: curchar = 204; i+=2;break; // ╠
                case 0xA1: curchar = 181; i+=2;break; // ╡
                case 0xA2: curchar = 182; i+=2;break; // ╢
                case 0xA3: curchar = 185; i+=2;break; // ╣
                case 0xA4: curchar = 209; i+=2;break; // ╤
                case 0xA5: curchar = 210; i+=2;break; // ╥
                case 0xA6: curchar = 203; i+=2;break; // ╦
                case 0xA7: curchar = 207; i+=2;break; // ╧
                case 0xA8: curchar = 208; i+=2;break; // ╨
                case 0xA9: curchar = 202; i+=2;break; // ╩
                case 0xAA: curchar = 216; i+=2;break; // ╪
                case 0xAB: curchar = 215; i+=2;break; // ╫
                case 0xAC: curchar = 206; i+=2;break; // ╬
              }
              break; 
            case 0x96:
              switch(s[i+2]){
                case 0x80: curchar = 223; i+=2;break; // ▀
                case 0x84: curchar = 220; i+=2;break; // ▄
                case 0x88: curchar = 219; i+=2;break; // █
                case 0x8C: curchar = 221; i+=2;break; // ▌
                case 0x90: curchar = 222; i+=2;break; // ▐
                case 0x91: curchar = 176; i+=2;break; // ░
                case 0x92: curchar = 177; i+=2;break; // ▒
                case 0x93: curchar = 178; i+=2;break; // ▓
                case 0xA0: curchar = 254; i+=2;break; // ■
              }
              break;
          }
          break;
        default: curchar=s[i]; break;
      }
      PRINTCHAR(curchar);
    }
  }
}

void PRINTCHAR(char c){
  int idx=0;
    tft.fillRect((POSX-1)*8, (POSY-1)*16, 8, 16, bgcol);
    idx = 8*16*c;
    for (int y = 0; y <16; y++){
      for (int x = 0; x <8; x++){
       if(myFont[idx]==1)
        tft.drawPixel(x+(POSX-1)*8, y+(POSY-1)*16,ftcol);
        idx++;
      }
    }
    POSX++;
    if(POSX>30){
      POSX=1;
      POSY++;
    }
}
