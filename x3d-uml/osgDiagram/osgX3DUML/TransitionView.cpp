///////////////////////////////////////////////////////////
//  TransitionView.cpp
//  Implementation of the Class TransitionView
//  Created on:      24-Jun-2008 9:44:32 PM
///////////////////////////////////////////////////////////

#include "TransitionView.h"

using X3DUML::TransitionView;


TransitionView::TransitionView(){
	setPosition(0,0,0);
}



TransitionView::~TransitionView(){

}


void TransitionView::drawWayPoints(){
	
	osg::Geometry* transitionLineGeom = new osg::Geometry();

	//convert UML Diagram Points to OSG Vertices
	osg::Vec3Array* vertices = new osg::Vec3Array(waypoints.size());
	if (waypoints.size() >= 2)
	{
		for (size_t i = 1; i <= waypoints.size(); i++)
		{
			(*vertices)[i-1].set(waypoints[i-1]->x, waypoints[i-1]->y, waypoints[i-1]->z);
		}
	}
	transitionLineGeom->setVertexArray(vertices);

	// set the colors a
    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,0.0f)); //black
    transitionLineGeom->setColorArray(colors);
    transitionLineGeom->setColorBinding(osg::Geometry::BIND_OVERALL);

	// set the normal in the same way color.
    osg::Vec3Array* normals = new osg::Vec3Array;
    normals->push_back(osg::Vec3(0.0f,-1.0f,0.0f));
    transitionLineGeom->setNormalArray(normals);
    transitionLineGeom->setNormalBinding(osg::Geometry::BIND_OVERALL);

    transitionLineGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP,0,waypoints.size()));
	// Standard lines are one pixel in width, we need to lines wider to be more easily seen
	// TODO: This might be better at the root node, set one line state for everything
	// and let it cascade down rather than doing it for every line.
	// See  OSGQSG.pdf 2.4 Rendering State
	osg::StateSet* lineState = transitionLineGeom->getOrCreateStateSet();
	osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
	lineState->setAttribute(lineWidth);
    
    // add the points geometry to the geode.
    geode->addDrawable(transitionLineGeom);

	// Draw the arrow head
	osg::Vec3Array* arrowHeadPoints = new osg::Vec3Array(3);
	if (waypoints.size() >= 2)
	{
		int size = waypoints.size();
		// Find the angle of the line... atan of last point minus the second to last point	
		double lineAngle = atan2(waypoints.at(waypoints.size()-1)->x - waypoints.at(waypoints.size()-2)->x,
								waypoints.at(waypoints.size()-1)->y - waypoints.at(waypoints.size()-2)->y);

		// Create arrow head points
		// last waypoint is the tip
		(*arrowHeadPoints)[0].set(waypoints[waypoints.size()-1]->x, waypoints[waypoints.size()-1]->y, waypoints[waypoints.size()-1]->z);
		// and two points at different angles from the tip
		(*arrowHeadPoints)[1].set(waypoints[waypoints.size()-1]->x - sin(lineAngle + 0.261799388) * 30, 
							waypoints[waypoints.size()-1]->y - cos(lineAngle + 0.261799388) * 30, 
							waypoints[waypoints.size()-1]->z);
		(*arrowHeadPoints)[2].set(waypoints[waypoints.size()-1]->x - sin(lineAngle - 0.261799388) * 30, 
							waypoints[waypoints.size()-1]->y - cos(lineAngle - 0.261799388) * 30, 
							waypoints[waypoints.size()-1]->z);
	}
	// Draw a triangle using the end point and the calculated arrow parts
	osg::Geometry* arrowHead = new osg::Geometry();
	arrowHead->setVertexArray(arrowHeadPoints);
	arrowHead->setColorArray(colors);
	arrowHead->setColorBinding(osg::Geometry::BIND_OVERALL);
	arrowHead->setNormalArray(normals);
	arrowHead->setNormalBinding(osg::Geometry::BIND_OVERALL);
	arrowHead->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,3));
	geode->addDrawable(arrowHead);

}