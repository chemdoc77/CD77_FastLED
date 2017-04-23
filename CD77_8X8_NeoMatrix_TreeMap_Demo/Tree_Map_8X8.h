/*  The Tree Mapping method by Jason Coon was adapted to a Matrix by Chemdoc77

   Jasosn amazing code and method can be found here:
   
   Tree v2: https://github.com/evilgeniuslabs/tree-v2
   Copyright (C) 2016 Jason Coon

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


const uint8_t CD77_leds [NUM_LEDS] ={0,1,2,3,4,5,6,7,15,23,31,39,47,55,63,62,61,60,59,58,
                                   57,56,48,40,32,24,16,8,9,10,11,12,13,14,22,30,38,46,
                                   54,53,52,51,50,49,41,33,25,17,18,19,20,21,29,37,45,44,
                                   43,42,34,26,27,28,36,35};


// by Chemdoc77 for 8X8 matrix:

const uint8_t radii[NUM_LEDS] = {63,63,63,63,63,42,42,42,42,42,42,63,63,42,21,21,21,
                                 21,42,63,63,42,21,0,0,21,42,63,63,42,21,0,0,21,42,
                                 63,63,42,21,21,21,21,42,63,63,42,42,42,42,42,42,63,
                                 63,63,63,63,63,63,63,63};


const uint8_t conicalRadii[NUM_LEDS]={3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,3,3,2,1,1,1,1,2,
                                      3,3,2,1,0,0,1,2,3,3,2,1,0,0,1,2,3,3,2,1,1,1,1,
                                      2,3,3,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3};

                                      
const uint8_t angles[NUM_LEDS] = {0,9,18,27,37,46,55,64,247,0,13,26,38,51,64,73,238,243,0,21,43,64,
                                          77,82,229,230,235,0,64,85,90,91,219,218,213,192,128,107,102,101,210,205,192,
                                          171,149,128,115,110,201,192,179,166,154,141,128,119,192,183,174,165,155,146,137,128};

const uint8_t levelCount = 4;
const uint8_t ledsPerLevel[levelCount] ={28, 20,12,4};


const uint8_t levelStart[levelCount] = {0,28,48,60};
  


const uint8_t levelEnd[levelCount] = {28,48,60,64};


const uint8_t levels[NUM_LEDS] = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,2,2,2,2,2,1,0,0,1,2,3,3,2,1,0,0,1,2,3,3,2,1,
                                   0,0,1,2,2,2,2,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0};


const uint8_t zCoords[NUM_LEDS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 85, 85, 85, 85, 85, 85, 0, 0, 85, 170, 170, 170, 170, 85, 0, 0, 85, 170, 255, 255, 170, 85, 0, 0, 
                                    85, 170, 255, 255, 170, 85, 0, 0, 85, 170, 170, 170, 170, 85, 0, 0, 85, 85, 85, 85, 85, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0};



const uint8_t xCoords[NUM_LEDS] = {128,156,183,207,227,242,252,255,99,128,157,184,205,219,224,252,72,98,128,160,184,193,219,242,48,
                                    71,95,128,162,184,205,227,28,50,71,93,128,160,184,207,13,36,62,71,95,128,157,183,3,31,36,50,71,
                                    98,128,156,0,3,13,28,48,72,99,128};


const uint8_t yCoords[NUM_LEDS] = {202,199,192,180,164,144,123,101,199,177,173,162,146,124,101,78,192,173,152,145,127,101,77,57,
                                   180,162,145,128,101,75,56,38,164,146,127,101,74,56,39,22,144,124,101,75,56,49,28,10,123,101,77,
                                   56,39,28,25,3,101,78,57,38,22,10,3,0};

/*
uint8_t getNearestToAngleAndLevel(uint8_t angle, uint8_t level) {
  uint8_t smallestDifference = 255;
  uint8_t nearestIndex = 0;

  for(uint8_t i = 0; i < NUM_LEDS; i++) {
    if(levels[i] != level)
      continue;

    uint8_t currentAngle = angles[i];

    uint8_t difference = abs(currentAngle - angle);

    if(difference > smallestDifference)
      continue;
    else if (difference == smallestDifference && random8() > 127)
      continue;

    smallestDifference = difference;
    nearestIndex = i;
  }

  return nearestIndex;
}
*/
