///////////////////////////////////////////////////////////
//  DiagramElement.cpp
//  Implementation of the Class DiagramElement
//  Created on:      23-Jun-2008 9:22:39 PM
///////////////////////////////////////////////////////////

#include "DiagramElement.h"

using X3DUML::DiagramElement;


DiagramElement::DiagramElement(){
	x3dumlTransparency = 0.3;				// this will be the default "look", will eventually be user defined through config file
	x3dumlDraggable = false;				// this means that by default diagram elements won't have draggers associated with them
	fullyQualifiedName = "DiagramElement."; // This is so we can reference each element by a name e.g. Root.D1.E1
	name = "DiagramElement";
	type = "DiagramElement";
	parent = NULL;
	group = new osg::MatrixTransform;
	geode = new osg::Geode;
	group->addChild(geode.get());
}


DiagramElement::~DiagramElement(){

}


void DiagramElement::updateOSGGroup(){

}



void DiagramElement::makeDraggable(osgManipulator::CommandManager* cmdMgr, float xPos, float yPos, float zPos, float height, float width, float depth){

	/*
		TODO: This needs a tidy up! Most of the code is redundant as we replace the dragger geometry in updateOSGGroup()
		with a shape derived from the diagram perimeter.
	*/
	// Create the type of dragger that we need osg::Plane(0.0,1.0,0.0,0.0)
	dragger = new osgManipulator::Translate2DDragger(osg::Plane(0.0,0.0,1.0,0.0));

	// however instead of calling dragger->setupDefaultGeometry(); which creates ugly arrows
	// create our own geometry to suit your task (refer to setupDefaultGeometry() for hints).
	// osg::ref_ptr<osg::MatrixTransform> 
		customDraggerxform = new osg::MatrixTransform;
	osg::ref_ptr<osg::Geode> customDraggerGeode = new osg::Geode;
 	osg::ref_ptr<osg::Box> draggerbox = new osg::Box (osg::Vec3(0.0f,0.0f,0.0f), width , height, 4 ); // xyz is not used as expected due to matrix being rotated
//  	osg::ref_ptr<osg::Box> draggerbox = new osg::Box (osg::Vec3(0.0f,0.0f,0.0f), width , 4, height); // xyz is not used as expected due to matrix being rotated
    osg::ref_ptr<osg::Drawable> drawable = new osg::ShapeDrawable(draggerbox.get());
//	osgManipulator::setDrawableToAlwaysCull(*drawable); // you can make things invisible too
	customDraggerGeode->addDrawable(drawable.get());
	customDraggerxform->addChild(customDraggerGeode.get());

	// once you have your geometry, pass it to the dragger to use as the pick geometry
	// This is a bit tricky, in 2.6.0 I extended the dragger to allow custom
	// geometries however it didn't get into the build. So instead I'll bypass
	// the standard geometry and used the addChild method (this might break in future
	// versions but will work on OSG 2.8 without having to modifiy osg code).
	// dragger->setupCustomGeometry(customDraggerxform.get());
	dragger->addChild(customDraggerxform.get());

	//by default the Translate2DDragger is along XZ plane, we want it on XY plane
	//dragger->setMatrix(osg::Matrix::rotate(osg::inDegrees(-90.0f),1.0f,0.0f,0.0f) * osg::Matrix::translate(xPos + width/2, yPos + height/2, 0.0f));
	
	draggerSelection = new osgManipulator::Selection();	
	//float scale = geode->getBound().radius() * 1.6;
	//dragger->setMatrix(osg::Matrix::translate(osg::Vec3(0.0f,0.0f,0.0f)));
 //   dragger->setMatrix(osg::Matrix::scale(scale, scale, scale) *
 //                      osg::Matrix::translate(geode->getBound().center()));
	//dragger->setMatrix(osg::Matrix::scale(1000, 1000, 1000));
	draggerSelection->addChild(geode.get()); 

	group->removeChild(geode.get());
	group->addChild(draggerSelection.get());
	group->addChild(dragger.get());
	cmdMgr->connect(*dragger,*draggerSelection);
	x3dumlDraggable = true;//insert a draggable group inbetween the top group and the geode
}

bool DiagramElement::isfullyQualifiedName(string theName)
{
	return (fullyQualifiedName.compare(theName)== 0);
}

DiagramElement* DiagramElement::getSubDiagramByName(std::string subDiagramPartialName)
{
	// we aren't a diagram so we return nothing (everything is handled in the DiagramView class)
	return NULL;
}

//DiagramElement* DiagramElement::getSubDiagramElementByName(std::string subDiagramElementPartialName)
//{
//	// This is the same as getSubDiagramByName except we are looking for elements in a diagram
//	// Expected format is "Ourname.SubDiagramName.1_DiagramElementName"
//	// Example we are "Root." and are passed "Top." (from "Root.Top." full path)
//	// First we'll split the string up into ourname and the next diagram name
//	std::string thisDiagramName = subDiagramElementPartialName.substr(0, subDiagramElementPartialName.find_first_of('.'));
//	std::string nextSubDiagramName = subDiagramElementPartialName.substr(subDiagramElementPartialName.find_first_of('.')+1);
//	X3DUML::DiagramElement* diagramPtr;
//
//	// If there is just one name we can determine quickly if that name is the same as ours
//	//if (subDiagramPartialName.compare(this->name + ".") == 0)
//	//{
//	//	return this;
//	//}
//	//else // Then we separate out the bits we need e.g. "SomeName." and "SomeName.SomeName..."
//	//{
//	//	// Then we check if we are in the right branch
//	//	if (thisDiagramName.compare(this->name) != 0) // the diagram name requested doesn't match up
//	//	{
//	//		return NULL;
//	//	}
//	//	else	// we are the right branch lets look at our contents
//	//	{
//	//		for(size_t i=0;i < contained.size(); i++) // search recursively until we find something
//	//			{
//	//				diagramPtr = contained.at(i)->getSubDiagramByName(nextSubDiagramName);
//	//				if (diagramPtr != NULL) return diagramPtr;
//	//			}
//	//			return NULL; // or give up
//	//	}
//	//}
//	return NULL; // shouldn't get here but it's nice to be safe
//}
