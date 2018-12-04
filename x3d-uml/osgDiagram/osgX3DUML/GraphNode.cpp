///////////////////////////////////////////////////////////
//  GraphNode.cpp
//  Implementation of the Class GraphNode
//  Created on:      23-Jun-2008 9:54:22 PM
///////////////////////////////////////////////////////////

#include "GraphNode.h"

using X3DUML::GraphNode;


GraphNode::GraphNode(){

}



GraphNode::~GraphNode(){

}



void GraphNode::setSize(double width, double height){
	size.width = width;
	size.height = height;
}