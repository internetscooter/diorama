///////////////////////////////////////////////////////////
//  Point.cpp
//  Implementation of the Class Point
//  Created on:      23-Jun-2008 9:14:55 PM
///////////////////////////////////////////////////////////

#include "Point.h"

using X3DUML::Point;


Point::Point(){
	x = 0;
	y = 0;
	z = 0;
}



Point::~Point(){

}



Point::Point(double initialX, double initialY, double initialZ){
	x = initialX;
	y = initialY;
	z = initialZ;
}