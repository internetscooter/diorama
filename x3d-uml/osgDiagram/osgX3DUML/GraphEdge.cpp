///////////////////////////////////////////////////////////
//  GraphEdge.cpp
//  Implementation of the Class GraphEdge
//  Created on:      23-Jun-2008 9:51:55 PM
///////////////////////////////////////////////////////////

#include "GraphEdge.h"

using X3DUML::GraphEdge;


GraphEdge::GraphEdge(){

}



GraphEdge::~GraphEdge(){

}




void GraphEdge::addWayPoint(double x, double y, double z){
	Point* waypoint = new Point(x,y,z);
	waypoints.push_back(waypoint);
}