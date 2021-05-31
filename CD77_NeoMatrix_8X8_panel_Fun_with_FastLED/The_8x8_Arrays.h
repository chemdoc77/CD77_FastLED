#ifndef The_8x8_Arrays_h
#define The_8x8_Arrays_h


// arrays for forward spiral
      uint8_t x;  // number of elements in an array
      uint8_t boxarray1[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 23, 31, 39, 47, 55, 63, 62, 61, 60, 59, 58, 57, 56, 48, 40, 32, 24, 16, 8};
      uint8_t boxarray2[] = {9, 10, 11, 12, 13, 14, 22, 30, 38, 46, 54, 53, 52, 51, 50, 49, 41, 33, 25, 17};
      uint8_t boxarray3[] = {18, 19, 20, 21, 29, 37, 45, 44, 43, 42, 34, 26};
      uint8_t boxarray4[] = {27, 28, 36, 35};
   
// size of forward spiral arrays                     

             uint8_t boxarray1_Size = ARRAY_SIZE(boxarray1); 
             uint8_t boxarray2_Size = ARRAY_SIZE(boxarray2); 
             uint8_t boxarray3_Size = ARRAY_SIZE(boxarray3); 
             uint8_t boxarray4_Size = ARRAY_SIZE(boxarray4); 
   
      uint8_t boxtotalarray[] = {boxarray1_Size, boxarray2_Size, boxarray3_Size, boxarray4_Size}; 
   // array of the above arrays 
      const unsigned char * bigboxarray[] ={boxarray1, boxarray2, boxarray3, boxarray4}; 
      
// size of boxtotalarray forward spiral array of arrays                     

             uint8_t bigboxarray_Size = ARRAY_SIZE(bigboxarray);
 
  // arrays for split box
     uint8_t splitboxarray1[] = {24, 16, 8, 0, 1, 2, 3, 4, 5, 6, 7, 15, 23, 31};
     uint8_t splitboxarray2[] = {32, 40, 48, 56, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39};
     uint8_t splitboxarray3[] = {25, 17, 9, 10, 11, 12, 13, 14, 22, 30};
     uint8_t splitboxarray4[] = {33, 41, 49, 50, 51, 52, 53, 54, 46, 38};
     uint8_t splitboxarray5[] = {26, 18, 19, 20, 21, 29};
     uint8_t splitboxarray6[] = {34, 42, 43, 44, 45, 37};
     uint8_t splitboxarray7[] = {27, 28};
     uint8_t splitboxarray8[] = {35, 36};  


     // size of forward spiral arrays                     

             uint8_t splitboxarray1_Size = ARRAY_SIZE(splitboxarray1); 
             uint8_t splitboxarray2_Size = ARRAY_SIZE(splitboxarray2); 
             uint8_t splitboxarray3_Size = ARRAY_SIZE(splitboxarray3); 
             uint8_t splitboxarray4_Size = ARRAY_SIZE(splitboxarray4); 
             uint8_t splitboxarray5_Size = ARRAY_SIZE(splitboxarray5); 
             uint8_t splitboxarray6_Size = ARRAY_SIZE(splitboxarray6); 
             uint8_t splitboxarray7_Size = ARRAY_SIZE(splitboxarray7); 
             uint8_t splitboxarray8_Size = ARRAY_SIZE(splitboxarray8); 
   
      uint8_t splitboxtotalarray[] = {splitboxarray1_Size, splitboxarray2_Size, splitboxarray3_Size, splitboxarray4_Size, splitboxarray5_Size, splitboxarray6_Size, splitboxarray7_Size, splitboxarray8_Size}; 
   // array of the above arrays 
      const unsigned char * splitbigboxarray[] ={splitboxarray1, splitboxarray2, splitboxarray3, splitboxarray4,splitboxarray5, splitboxarray6, splitboxarray7, splitboxarray8}; 
      
// size of boxtotalarray forward spiral array of arrays                     

             uint8_t splitbigboxarray_Size = ARRAY_SIZE(splitbigboxarray);
 
  // 4X4 boxes arrays 
     uint8_t fourarray1[]= {0, 1, 2, 3, 11, 19, 27, 26, 25, 24, 16, 8, 9, 10, 18, 17};
     uint8_t fourarray2[]= {4, 5, 6, 7, 15, 23, 31, 30, 29, 28, 20, 12, 13, 14, 22, 21};
     uint8_t fourarray3[]= {36, 37, 38, 39, 47, 55, 63, 62, 61, 60, 52, 44, 45, 46, 54, 53};
     uint8_t fourarray4[]= {32, 33, 34, 35, 43, 51, 59, 58, 57, 56, 48, 40, 41, 42, 50, 49};
  // array of the above arrays
     const unsigned char * bigfourarray[]={fourarray1, fourarray2, fourarray3, fourarray4};
   
// size of forward spiral arrays                     

             uint8_t fourarray1_Size = ARRAY_SIZE(fourarray1); 
             uint8_t fourarray2_Size = ARRAY_SIZE(fourarray2); 
             uint8_t fourarray3_Size = ARRAY_SIZE(fourarray3); 
             uint8_t fourarray4_Size = ARRAY_SIZE(fourarray4); 
   
     
   // array of the above arrays 
      uint8_t bigfourarray_size[] ={fourarray1_Size, fourarray2_Size, fourarray3_Size, fourarray4_Size}; 
      
// size of boxtotalarray forward spiral array of arrays                     

             uint8_t bigfourarray_Size = ARRAY_SIZE(bigfourarray_size);    


#endif
