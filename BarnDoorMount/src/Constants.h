#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

/**
* Milimeters that the rod comes up every complete rotation (360º). In a M8 rod/bolt is usually 1.25 mm. In a M6, only 1.00mm   
*/
const float ComingUpSpeed = 1.25;
/**
* Distance from the centre of the hinge to the centre of the hole for the rod in milimiters
*/
const float Length = 180.975;
/**
 * Rotational velocity of the small gear
 */
const float Step = ((2 * 3.14159) / 1436) * Length;

/**
 * Rotational velocity of the large gear
 */
const float Rps = (Step / (60 * 0.2549)) / ComingUpSpeed;

const int ZeroSpeed = 65535;

/**
 * 200 steps motor with 1/16 microstepping
 */
const int StepsPerRevolution = 3200;
const float MaxRpm = (Rps * 60.0);

#endif // __CONSTANTS_H__