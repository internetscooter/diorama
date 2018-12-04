///////////////////////////////////////////////////////////
//  PseudoStateView.cpp
//  Implementation of the Class PseudoStateView
//  Created on:      24-Jun-2008 9:18:14 PM
///////////////////////////////////////////////////////////

#include "PseudoStateView.h"

using X3DUML::PseudoStateView;


PseudoStateView::PseudoStateView(){

}

PseudoStateView::PseudoStateView(double width, double height, double x, double y, double z, X3DUML::PseudoStateView::Stereotype stereotype){
	setSize(width,height);
	setPosition(x,y,z);
	if (stereotype == Junction)
	{
		osg::ShapeDrawable* junctionPoint = new osg::ShapeDrawable(new osg::Cylinder(osg::Vec3( 0.0, 0.0, 0.0 ), 10, 1));
		osg::Vec4 characterSizeModeColor(0.0f,0.0f,0.0f,1.0f);
		junctionPoint->setColor(characterSizeModeColor);
		geode->addDrawable(junctionPoint);
	}
	else if (stereotype == Initial)
	{
		osg::ShapeDrawable* initialPoint = new osg::ShapeDrawable(new osg::Cylinder(osg::Vec3( 0.0, 0.0, 0.0 ), 30, 1));
		osg::Vec4 characterSizeModeColor(0.0f,0.0f,0.0f,1.0f);
		initialPoint->setColor(characterSizeModeColor);
		geode->addDrawable(initialPoint);
	}
	else if (stereotype == History)
	{
		// For the history we need a circle...
		// Calculate rounded corners
		double diameter = 60;
		double cornerRadius = diameter / 2;
		double crnV1 = cornerRadius / 10; // values for working out edge curves on corners
		double crnV2 = cornerRadius / 2;  // values for working out edge curves on corners
		// Circle points
	    osg::Vec3 myCoords[] =
	    {
			osg::Vec3(0, -cornerRadius, 0),								// 1
			osg::Vec3(crnV2, -cornerRadius + crnV1, 0),					// 2
			osg::Vec3(cornerRadius - crnV1, -crnV2, 0),					// 3
			osg::Vec3(cornerRadius, 0, 0),								// 4
			osg::Vec3(cornerRadius - crnV1, crnV2, 0),					// 5
			osg::Vec3(crnV2, cornerRadius - crnV1, 0),					// 6
			osg::Vec3(0, cornerRadius, 0),								// 7
			osg::Vec3(-crnV2, cornerRadius - crnV1, 0),					// 8
			osg::Vec3(-cornerRadius + crnV1, crnV2, 0),					// 9
			osg::Vec3(-cornerRadius, 0, 0),								// 10
			osg::Vec3(-cornerRadius + crnV1, -crnV2, 0),				// 11
			osg::Vec3(-crnV2, -cornerRadius + crnV1, 0),				// 12
	    };
	    int numCoords = sizeof(myCoords)/sizeof(osg::Vec3);
	    osg::Vec3Array* vertices = new osg::Vec3Array(numCoords,myCoords);
		// For the outside line...
		// create Geometry object to store all the vertices and lines primitive.
		osg::Geometry* circleLinesGeom = new osg::Geometry();	
		// pass the created vertex array to the points geometry objects.
		circleLinesGeom->setVertexArray(vertices);
		// set the colors as before, plus using the above
		osg::Vec4Array* colors = new osg::Vec4Array;
		colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,0.0f)); //black
		circleLinesGeom->setColorArray(colors);
		circleLinesGeom->setColorBinding(osg::Geometry::BIND_OVERALL);

		// set the normal in the same way color.
		osg::Vec3Array* normals = new osg::Vec3Array;
		normals->push_back(osg::Vec3(0.0f,-1.0f,0.0f));
		circleLinesGeom->setNormalArray(normals);
		circleLinesGeom->setNormalBinding(osg::Geometry::BIND_OVERALL);

		// This time we simply use primitive, and hardwire the number of coords to use 
		// since we know up front,
		circleLinesGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP,0,numCoords));
		// Standard lines are one pixel in width, we need to lines wider to be more easily seen
		// TODO: This might be better at the root node, set one line state for everything
		// and let it cascade down rather than doing it for every line.
		// See  OSGQSG.pdf 2.4 Rendering State
		osg::StateSet* lineState = circleLinesGeom->getOrCreateStateSet();
		osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
		lineState->setAttribute(lineWidth);
	   
	   // add the points geometry to the geode.
	   geode->addDrawable(circleLinesGeom);
	}
}

PseudoStateView::~PseudoStateView(){

}