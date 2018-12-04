///////////////////////////////////////////////////////////
//  GraphElement.cpp
//  Implementation of the Class GraphElement
//  Created on:      23-Jun-2008 9:33:51 PM
///////////////////////////////////////////////////////////

#include "GraphElement.h"
#include <sstream>

using X3DUML::GraphElement;


GraphElement::GraphElement(){
}


GraphElement::~GraphElement(){

}


std::string GraphElement::addDiagramElement(DiagramElement* element){
	// remember your elders
	element->parent = this;
	// and have that accessible via a string
	if(element->type.compare("DiagramView") == 0) // Diagrams are unique and are called by name only
	{
		element->fullyQualifiedName = this->fullyQualifiedName + element->name + ".";
	}
	else // elements are not unique and we need to refer to them by number and name
	{
		std::stringstream elementNumber;
		elementNumber << contained.size();
		//s = elementNumber.str();

		//int x = contained.size();
		element->fullyQualifiedName = this->fullyQualifiedName + elementNumber.str() + "_" + element->name + ".";
	}

	contained.push_back(element);
	return element->fullyQualifiedName;
}

std::string GraphElement::addGraphElement(GraphElement* element){
	// and keep everything with positions on the diagram at the same plane (for now)
	//element->position.z += this->position.z;
	return this->addDiagramElement(element);
}

void GraphElement::updateOSGGroup(){
	// recurse the structure to create geometry visualisation with osg geodes based on UML parameters
	for(size_t i=0;i < contained.size(); i++)
	{
		contained.at(i)->updateOSGGroup(); // update everyone below first

		if (x3dumlDraggable)
		{ //insert dragger node if required
			draggerSelection->addChild(contained.at(i)->group.get());

			// here we will match the object used for dragging bits around with the first object
			// in the diagram contained objects. This will work for now for state machines because the first
			// object added is the biggest stateview. Later we'll need to update this so the code finds
			// the biggest object in all the contained elements and use that as the item that gets selected
			// to move things around with.

			osg::ref_ptr<osg::Drawable> diagramDrawable = osg::clone(contained.at(0)->geode->getDrawable(1),osg::CopyOp::DEEP_COPY_DRAWABLES);
			osgManipulator::setDrawableToAlwaysCull(*diagramDrawable); // this line makes the dragger invisible

			osg::ref_ptr<osg::Geode> customDraggerGeode = new osg::Geode();
			customDraggerGeode->addDrawable(diagramDrawable.get());

			customDraggerxform->removeChildren(0,1);					// remove the default dragger geometry
			customDraggerxform->addChild(customDraggerGeode.get());		// replace it with the one we just created
			// move the dragger into position just above diagram object
			X3DUML::GraphElement* graphElement = (X3DUML::GraphElement*)contained.at(0);
			dragger->setMatrix(osg::Matrix::translate(graphElement->position.x, graphElement->position.y, -2.0f));
		}
		else 
		{
			group->addChild(contained.at(i)->group.get());
		}
	}
}


void GraphElement::setPosition(double x, double y, double z){
	//set position
	position.x = x;
	position.y = y;
	position.z = z;
	//set OSG position
	osg::Matrix m;
	m.setTrans(x,y,z);
	group->setMatrix(m);
}

bool GraphElement::containsDiagramElement(std::string type, std::string name){
	for(size_t i=0;i < contained.size(); i++)
	{
		if (contained.at(i)->type.compare(type) == 0 && contained.at(i)->name.compare(name))
			return true;
	}
	return false;
}