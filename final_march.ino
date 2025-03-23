#define  c3     130  
#define  c3s    138  
#define  d3     146  
#define  d3s    155  
#define  e3     164  
#define  f3     174  
#define  f3s    185  
#define  g3     196  
#define  g3s    207  
#define  a3     220  
#define  a3s    233  
#define  b3     247  
#define  c4     261  
#define  c4s    277  
#define  d4     293  
#define  d4s    311  
#define  e4     329  
#define  f4     349  
#define  f4s    370  
#define  g4     392  
#define  g4s    415  
#define  a4     440  
#define  a4s    466  
#define  b4     493  
#define  c5     523  
#define  c5s    554  
#define  d5     587  
#define  d5s    622  
#define  e5     659  
#define  f5     698  
#define  f5s    740  
#define  g5     784  
#define  g5s    831  
#define  a5     880  
#define  a5s    932  
#define  b5     987  
  


#include <Arduino.h>

const int outputPin = 11;
const int buzzerPin = 9; // Pin for the buzzer
const int pulseDuration = 20; // 20 ms pulse
const int cutofftime = 800;

const int data[] = {507, 572, 381, 129, 570, 521, 777, 276, 568, 526, 823, 280, 543, 536, 1062, 528, 545, 536, 535, 548, 400, 151, 792, 260, 554, 268, 243, 832, 284, 798, 262, 1653, 316, 198, 516, 520, 598, 260, 296, 769, 289, 540, 387, 118, 581, 535, 522, 516, 844, 265, 537, 381, 130, 550, 265, 268, 252, 276, 255, 268, 1386, 270, 232, 278, 1444, 209, 254, 291, 1690, 467, 516, 289, 266, 536, 509, 1094, 561, 512, 529, 395, 118, 609, 535, 1056, 558, 564, 496, 393, 172, 532, 529, 803, 267, 1656, 262, 278, 776, 279, 812, 304, 1867, 259, 237, 134, 132, 243, 269, 277, 123, 133, 584, 251, 232, 318, 265, 862, 251, 540, 535, 1093, 453, 567, 318, 257, 536, 516, 549, 534, 550, 804, 244, 276, 113, 145, 250, 298, 261, 266, 287, 271, 851, 231, 295, 237, 270, 266, 576, 236, 250, 1957, 252, 532, 522, 1085, 541, 552, 819, 263, 502, 549, 529, 554, 375, 154, 572, 291, 218, 235, 247, 283, 251, 297, 271, 536, 571, 838, 237, 546, 545, 822, 267, 498, 534, 854, 263, 538, 545, 1000};

const int frequencies[] = {
g4, c5, g4, g4, e4, c4, g4, a4, g4, g4, c5, d5, e5, f5, e5, d5, g4, c5, g4, e4, c4, c4, g4, a4, g4, g4, g4, e5, c5, d5, b4, c5, 
c5, b4, a4, a4, a4, a4, b4, c5, a4, g4, a4, g4, f4, g4, f4, f4, a4, f4, d4, 
c5, b4, a4, a4, g4, a4, b4, c5, d5, e5, e5, f5, e5, f5, e5, f5, a5, g5, 
g4, c5, c5, c5, c5, c5, a4, a4, a4, d5, d5, d5, d5, d5, b4, b4, 
g4, e4, e4, e4, e4, e4, f4, g4, a4, g4, f4, e4, c5, d5, b4, c5, 
e4, c4, c4, c4, c4, e4, g4, g4, g4, g4, e4, g4, e4, c4, g4, g4, e4, c4, a3, 
d4, e4, d4, d4, c4, e4, g4, d4, g4, e4, g4, c4, c4, b3, c4, b3, c4, d4, e4, g4, a4, 
g4, f4, e4, d4, c4, a4, b4, a4, g4, 
e4, d4, d4, g4, e4, e4, d4, d4, b4, a4, g4, f4, e4, d4, g4, 
g4, a4, g4, a4, g4, e4, c4, e4, g4, c4, d4, a4, a4, g4, a4, a4, b4, c5, g4, 
g4, a4, b4, c5

};


const int dataSize = sizeof(data) / sizeof(data[0]);

void setup() {
    pinMode(outputPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < dataSize; i++) {
        Serial.println(data[i]);
        tone(buzzerPin, frequencies[i], cutofftime); // Play tone
        
        unsigned long startTime = millis();
        while (millis() - startTime < data[i] - pulseDuration) {
            // Wait for the remaining time before pulse
        }
        
        noTone(buzzerPin); // Stop tone before pulse
        
        // Send a 20 ms pulse at the end of each delay period
        digitalWrite(outputPin, HIGH);
        delay(pulseDuration);
        digitalWrite(outputPin, LOW);
    }
    
    delay(1000); // Wait before repeating
}

