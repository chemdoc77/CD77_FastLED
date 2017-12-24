/*
                          READ ME 

This sketch contains code to allow a user to create symmetrical and unsymmetrical chase animations.  The user can chose a single color, a color from an array of colors or a series of colors from a palette for the color of the pixels in the color chase bar.  The user can chose the number of pixels in the color chase bar. 

The variables used in the various new chase functions are explained below (see chase.h tab for these functions).

The time performance function is explained below (see time_performance.h tab for this function).

Please note: In the time performance code,  FastLED.delay(value) determines the speed of the color chase bar in the animation.

//======================================

CHASE FUNCTIONS:

CD77_chase_one_color_symet(X1, Y1, Z1 )

This function creates a symmetrical color chase bar.  The user chooses the color of the color chase bar.  The user chooses the frequency of the color chase bar.

X1 is the color of the pixels in the FASTLED RGB format which is CRGB::colorname (for example: CRGB::Red).  See the following for a list of the color names used by FastLED:

https://github.com/FastLED/FastLED/wiki/Pixel-reference (look at the bottom of the page)

Y1 determines the frequency of the color chase bar.
Z1 determines the number of pixels (i.e. dots) that are in the color chase bar of the animation. 
 
//===================

CD77_chase_array_color_symet(X2, Y2, Z2)

This function creates a symmetrical color chase bar animation in which a new color is used every chosen time period from a color array.

X2 determines the frequency of the color chase bar will be created.
Y2 determines how often a new color is used from the color array.
Z2 determines the number of pixels (i.e. dots) that are in the color chase bar of the animation. 

//=============================================

void CD77_chase_one_color_unsymet(W3, X3, Y3, Z3)

This function creates an unsymmetrical color chase bar in which the user chooses the range of the random generator of the frequency of the color chase bar.   The user chooses which the color of the color chase bar.  The user determines the number of lighted pixels in the color chase bar of the animation.


W3 determines the color of the pixels in the RGB format (for example: CRGB::Red).  
X3 determines the lower limit of a random number generator that determines the frequency of the color chase bar.
Y3 determines the upper limit of a random number generator that determines the frequency of the color chase bar.
Z3 determines the number of pixels (i.e. dots) that are in the color chase bar of the animation.

//============================================

void CD77_chase_array_color_unsymet(W4, X4, Y4, Z4 )

This function creates an unsymmetrical color chase bar in which the user chooses the range of the random generator of the frequency of the color bar.  The user chooses time in which a new color is chosen from a color array.  The user determines the number of lighted pixels in the color chase bar of the animation.

W4 determines the lower limit of a random number generator that determines the frequency of the color chase bar.
X4 determines the upper limit of a random number generator that determines the frequency of the color chase bar.
Y4 determines how often a new color is used from the color array.
Z4 determines the number of pixels (i.e. dots) that are in the color chase bar of the animation.

//============================================

void CD77_chase_PAL_symet( X5, Y5, Z5 )

This function creates a symmetrical color chase bar in which a new color is chosen from a user defined palette.  The user chooses the value of the delta change in the color index. The user chooses the number of lighted pixel that is in the color chase pixel bar of the animation.

X5 determines the delta change in the color index.
Y5 determines the frequency of the color chase bar will be created.
Z5 determines the number of pixels (i.e. dots) that are in the color chase bar of the animation.

//=============================

void CD77_chase_PAL_unsymet(W6, X6, Y6, Z6)

This function creates an unsymmetrical color chase bar in which a new color is chosen from a user defined palette.  The user chooses the value of the delta change in the color index. The user chooses the range of the random generator of the frequency for the color chase bar.  The user chooses the number of lighted pixel that is in the color chase pixel bar of the animation.

W5 determines the delta change in the color index.
X6 determines the lower limit of a random number generator that determines the frequency of the color chase bar.
Y9 determines the upper limit of a random number generator that determines the frequency of the color chase bar.
Z6 determines the number of pixels (i.e. dots) that are in the color chase bar of the animation.

//==========================

Time Performance Code:

The time performance code allows you to run a function or a group of functions for a period of time or for only one time at a certain time in this sketch.

The format is:

FROM(HOURS,MINUTES,SECONDS){code}  

This will continually run and loop the code until the next time segment starts.


AT (HOURS,MINUTES,SECONDS){code}  

This will run the code once and only once and wait until the next time segment starts.

 */
