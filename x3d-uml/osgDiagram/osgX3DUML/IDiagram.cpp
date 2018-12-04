///////////////////////////////////////////////////////////
//  IDiagram.cpp
//  Implementation of the Class IDiagram
//  Created on:      13-Aug-2008 12:59:55 PM
///////////////////////////////////////////////////////////

#include "IDiagram.h"
#include <osgManipulator/Translate2DDragger>

using X3DUML::IDiagram;

IDiagram::IDiagram(){
	theRootLevelDiagram = new DiagramView("Root");
	theCurrentDiagram = theRootLevelDiagram;
	cmdMgr = new osgManipulator::CommandManager;
	edgeGroup = new osg::MatrixTransform();
}



IDiagram::~IDiagram(){
}

void IDiagram::enableManualLayout(){
	if(theRootLevelDiagram != NULL)
	{
		//diagram->group->getOrCreateStateSet()->setMode(GL_NORMALIZE, osg::StateAttribute::ON);
		//osgManipulator::Selection* selection = new osgManipulator::Selection;
		//selection->addChild(diagram->group);
		//osgManipulator::Translate2DDragger* dragger = new osgManipulator::Translate2DDragger();
  //      dragger->setupDefaultGeometry();
		//diagram->group->addChild(selection);
		//diagram->group->addChild(dragger);
		//float scale = diagram->group->getBound().radius() * 1.6;
		//dragger->setMatrix(osg::Matrix::scale(scale, scale, scale) *
  //                     osg::Matrix::translate(diagram->group->getBound().center()));
		//cmdMgr->connect(*dragger,*selection);
	}
}