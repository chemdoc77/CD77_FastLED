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




const uint8_t CD77_leds [NUM_LEDS] ={0,1,2,3,4,5,6,7,8,9,10,29,30,49,50,69,70,89,90,91,92,
                                     93,94,95,96,97,98,99,80,79,60,59,40,39,20,19,18,17,16,
                                     15,14,13,12,11,28,31,48,51,68,71,88,87,86,85,84,83,82,81,
                                     78,61,58,41,38,21,22,23,24,25,26,27,32,47,52,67,72,73,74,
                                     75,76,77,62,57,42,37,36,35,34,33,46,53,66,65,64,63,56,43,
                                     44,45,54,55};




const uint8_t radii[NUM_LEDS] = {63,63,63,63,63,42,42,42,42,42,42,63,63,42,21,21,21,
                                 21,42,63,63,42,21,0,0,21,42,63,63,42,21,0,0,21,42,
                                 63,63,42,21,21,21,21,42,63,63,42,42,42,42,42,42,63,
                                 63,63,63,63,63,63,63,63};




  
  const uint8_t conicalRadii[NUM_LEDS]={4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,4,4,3,2,
                                        2,2,2,2,2,3,4,4,3,2,1,1,1,1,2,3,4,4,3,2,1,0,0,
                                        1,2,3,4,4,3,1,2,0,0,1,2,3,4,4,3,2,1,1,1,1,2,3,
                                        4,4,3,2,2,2,2,2,2,3,4,4,3,3,3,3,3,3,3,3,4,4,4,
                                        4,4,4,4,4,4,4,4};





const uint8_t angles[NUM_LEDS] = {0,7,14,21,28,36,43,50,57,64,71,64,55,46,36,28,18,9,0,
                                  249,242,247,0,13,26,38,51,64,73,78,85,82,77,64,43,21,
                                  0,243,238,235,228,228,230,235,0,64,85,90,92,92,100,100,
                                  107,102,128,192,213,218,220,220,213,210,205,192,171,149,
                                  128,115,110,107,114,119,128,141,154,166,179,192,201,206,
                                  199,192,183,174,164,156,146,137,128,121,128,135,142,149,
                                  156,164,171,178,185,192};





const uint8_t levelCount = 5;
const uint8_t ledsPerLevel[levelCount] ={36, 28, 20,12,4};


const uint8_t levelStart[levelCount] = {0,36,64,84,96};



const uint8_t levelEnd[levelCount] = {36,64,84,96,100};
  

const uint8_t levels[NUM_LEDS] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,2,2,2,2,2,2,1,0,0,
                                  1,2,3,3,3,3,2,1,0,0,1,2,3,4,4,3,2,1,0,0,1,3,2,4,4,3,2,1,0,0,1,
                                  2,3,3,3,3,2,1,0,0,1,2,2,2,2,2,2,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,
                                  0,0,0,0,0,0,0};
                                   




const uint8_t zCoords[NUM_LEDS] = {0,0,0,0,0,0,0,0,0,0,0,64,64,64,64,64,64,64,64,0,0,
                                   64,128,128,128,128,128,128,64,0,0,64,128,191,191,191,
                                   191,128,64,0,0,64,128,191,255,255,191,128,64,0,0,64,128,191,
                                   255,255,191,128,64,0,0,64,128,191,191,191,191,128,64,0,0,64,
                                   128,128,128,128,128,128,64,0,0,64,64,64,64,64,64,64,
                                   64,0,0,0,0,0,0,0,0,0,0,0};

                                




const uint8_t xCoords[NUM_LEDS] = {128,150,171,191,209,225,238,247,253,255,253,230,227,220,207,192,172,
                                   151,128,105,84,104,128,159,188,210,225,230,227,247,238,220,225,180,
                                   173,154,128,96,83,64,46,63,67,101,128,155,173,210,207,225,209,192,154,
                                   188,128,100,82,45,48,30,17,35,30,75,82,101,128,159,172,191,171,151,128,
                                   96,67,45,30,25,28,8,2,25,28,35,48,63,83,104,128,150,128,105,84,64,46,30,
                                   17,8,2,0};





const uint8_t yCoords[NUM_LEDS] = {255,253,247,238,225,209,191,171,150,128,105,128,151,172,192,207,220,227,
                                   230,253,247,227,230,225,210,188,159,128,104,84,64,83,96,128,154,173,180,
                                   225,220,238,225,207,210,173,155,128,101,67,63,46,30,48,82,45,100,128,154,
                                   188,192,209,191,172,159,128,101,82,75,30,35,17,8,28,25,30,45,67,96,128,151,
                                   171,150,128,104,83,63,48,35,28,25,2,0,2,8,17,30,46,64,84,105,128};



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
