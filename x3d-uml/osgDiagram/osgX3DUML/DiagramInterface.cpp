///////////////////////////////////////////////////////////
//  DiagramInterface.cpp
//  Implementation of the Class DiagramInterface
//  Created on:      14-May-2009 9:28:06 PM
//  Original author: internetscooter
///////////////////////////////////////////////////////////

#include "DiagramInterface.h"
#include <osgText/Font>
#include <osgText/Text>
#include <osg/Geode>
#include <osg/EdgeTriangle>
#include "TextView.h"
#include "DiagramView.h"
#include "StateView.h"
#include "PseudoStateView.h"
#include "TransitionView.h"
#include "IDiagram.h"

using X3DUML::DiagramInterface;

DiagramInterface::DiagramInterface(){
	theInteractiveDiagram = new X3DUML::IDiagram();
	planeDepth = 600;
}

DiagramInterface::~DiagramInterface(){

}

osg::ref_ptr<osg::Group> DiagramInterface::TestScreen(std::string name){
	//splash screen for test purposes (nothing flash)
	osg::ref_ptr<osg::Group> splashScreenGroup = new osg::Group;
	osg::ref_ptr<osg::Geode> textGeode  = new osg::Geode;
	osg::ref_ptr<osgText::Text> text = new osgText::Text;
    text->setAxisAlignment(osgText::Text::SCREEN);
	text->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
	text->setText(name);
	textGeode->addDrawable(text.get());
    //text4->setCharacterSize(characterSize);
    //text->setPosition(osg::Vec3(xPos,yPos,zPos));
	splashScreenGroup->addChild(textGeode.get());
	return  splashScreenGroup;
}

std::string DiagramInterface::AddDiagram(std::string name)
{
	X3DUML::DiagramView *newDiagram = new X3DUML::DiagramView(name);
	if (theInteractiveDiagram->theCurrentDiagram->fullyQualifiedName.compare("Root.") != 0) // if adding to root level diagram don't add depth
	{
		//newDiagram->position.z = theInteractiveDiagram->theCurrentDiagram->position.z + planeDepth;
		newDiagram->setPosition(0,0,planeDepth);

	}
	theInteractiveDiagram->theCurrentDiagram->addGraphElement(newDiagram);
	theInteractiveDiagram->theCurrentDiagram = newDiagram;
	newDiagram->makeDraggable(theInteractiveDiagram->cmdMgr,0,0,0,200,200,4);
	return newDiagram->fullyQualifiedName;
}

std::string DiagramInterface::AddStateView(double Width, double Height, double X, double Y, double Z)
{
	if (theInteractiveDiagram->theCurrentDiagram != NULL)
		if (theInteractiveDiagram->theCurrentDiagram->contained.size() > 1)
		{
			return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::StateView(Width,Height,X,Y,Z,0.01));
		}
		else
		{
			return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::StateView(Width,Height,X,Y,Z,0.3));
		}
	return "ERROR: Current Diagram is NULL";
}

std::string DiagramInterface::AddTextView(std::string text, double X, double Y, double Z)
{
	if (theInteractiveDiagram->theCurrentDiagram != NULL)
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::TextView(text, X, Y, Z));
	return "ERROR: Current Diagram is NULL";
}

std::string DiagramInterface::AddPseudoStateView(double Width, double Height, double X, double Y, double Z, std::string PseudoStateType)
{
	if (PseudoStateType.compare("Junction") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::Junction));
	}
	else if (PseudoStateType.compare("History") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::History));
	}
	else if (PseudoStateType.compare("Choice") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::Choice));
	}
	else if (PseudoStateType.compare("EntryPoint") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::EntryPoint));
	}
	else if (PseudoStateType.compare("ExitPoint") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::ExitPoint));
	}
	else if (PseudoStateType.compare("Final") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::Final));
	}
	else if (PseudoStateType.compare("Fork") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::Fork));
	}
	else if (PseudoStateType.compare("Initial") == 0)
	{
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::PseudoStateView(Width,Height,X,Y,Z,X3DUML::PseudoStateView::Initial));
	}
	else
	{
		// haven't created a view yet, so just use text as indication
		return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(new X3DUML::TextView(PseudoStateType, X, Y, Z));	
	}
}

std::string DiagramInterface::AddTransitionView(std::string WayPointsCSVString)
{
	X3DUML::TransitionView* transition = new X3DUML::TransitionView();

	//this is dangerous!!! we are expecting sets of x,y,z,x,y,z, and nothing else, no error checking yet...
	double x,y,z = 0;
	std::string currentVariable;
	std::string unparsed = WayPointsCSVString;
	while ((unparsed.size() > 0))
	{
		// x
		currentVariable = unparsed.substr(0, unparsed.find_first_of(','));
		unparsed = unparsed.substr(unparsed.find_first_of(',')+1);
		x = atoi(currentVariable.c_str());
		// y
		currentVariable = unparsed.substr(0, unparsed.find_first_of(','));
		unparsed = unparsed.substr(unparsed.find_first_of(',')+1);
		y = atoi(currentVariable.c_str());
		// z
		currentVariable = unparsed.substr(0, unparsed.find_first_of(','));
		unparsed = unparsed.substr(unparsed.find_first_of(',')+1);
		z = atoi(currentVariable.c_str());

		//theFullDiagram->addDiagramElement(new X3DUML::TextView("start", x, y, z));
		//theFullDiagram->addDiagramElement(new X3DUML::TextView(unparsed, 0, 60, 0));
		//theFullDiagram->addDiagramElement(new X3DUML::TextView(stdString, 0, 90, 0));

		transition->addWayPoint(x,y,z);
	}

	transition->drawWayPoints();
	return theInteractiveDiagram->theCurrentDiagram->addDiagramElement(transition);
}

osg::ref_ptr<osg::Group> DiagramInterface::RenderDiagram(){
	theInteractiveDiagram->theRootLevelDiagram->updateOSGGroup();
	return theInteractiveDiagram->theRootLevelDiagram->group.get();
}

osg::ref_ptr<osg::Group> DiagramInterface::RenderWorldEdges(){
	// returns the edges created
	for(size_t i=0;i < this->diagramLinks.size(); i+=2) 
	{
		CreateEdge(diagramLinks[i],diagramLinks[i+1]);
	}

	return theInteractiveDiagram->edgeGroup.get();
}
std::string DiagramInterface::CurrentDiagramName(){
	return theInteractiveDiagram->theCurrentDiagram->name;
}

std::string DiagramInterface::CurrentDiagramFullQualifiedName(){
	return theInteractiveDiagram->theCurrentDiagram->fullyQualifiedName;
}
bool DiagramInterface::SetOrCreateCurrentDiagram(std::string fullyQualifiedName){

	// Keep the existing pointer in case we need to revert
	X3DUML::DiagramView* initialCurrentDiagram = theInteractiveDiagram->theCurrentDiagram;

	if (SetCurrentDiagram(fullyQualifiedName)) //see if we have the diagram already
	{
		return true; // diagram set OK
	}
	else	// reset create a new one if we can
	{
		// set the current diagram ptr to the parent of the diagram we want to create
		// chop off last "." to make searching easier
		fullyQualifiedName = fullyQualifiedName.substr(0,fullyQualifiedName.size()-1);
		// get the name
		std::string parentDiagram = fullyQualifiedName.substr(0,fullyQualifiedName.find_last_of(".")+1);
		std::string newDiagram = fullyQualifiedName.substr(fullyQualifiedName.find_last_of(".")+1);
		if (SetCurrentDiagram(parentDiagram))
		{
			this->AddDiagram(newDiagram);
		}
		else
		{	// there is no such diagram return to previous state and return false
			theInteractiveDiagram->theCurrentDiagram = initialCurrentDiagram;
			return false;
		}

		return true;
	}

	return false;

}
bool DiagramInterface::SetCurrentDiagram(std::string fullyQualifiedName){
	// We first need to hunt for a DiagramView using a fullyQualifiedName like Root.DiagramName.DiagramName...
	// returns false if we fail to set 
	X3DUML::DiagramView *diagramResult;

	if (theInteractiveDiagram->theCurrentDiagram->fullyQualifiedName.compare(fullyQualifiedName) == 0)
	{	// we are already set
		return true;
	}
	else
	{	// have a look if there is a subdiagram
		diagramResult = (X3DUML::DiagramView*)theInteractiveDiagram->theRootLevelDiagram->getSubDiagramByName(fullyQualifiedName);
		if (diagramResult != NULL)
		{
			theInteractiveDiagram->theCurrentDiagram = diagramResult;
			return true;
		}
	}
	return false; // current diagram not changed
}

bool DiagramInterface::LinkElementToDiagram(std::string elementFullyQualifiedName, std::string diagramFullyQualifiedName)
{

	diagramLinks.push_back(elementFullyQualifiedName);
	diagramLinks.push_back(diagramFullyQualifiedName);

	return true;
}

bool DiagramInterface::CreateEdge(std::string elementFullyQualifiedName, std::string diagramFullyQualifiedName)
{
	// Here we get a pointer to each element then create an triangle edge between them
	X3DUML::DiagramView*	diagramResult; 
	X3DUML::DiagramView* 	elementDiagramResult;
	X3DUML::DiagramElement* diagramElement;

	// Get Diagram
	diagramResult = (X3DUML::DiagramView*)theInteractiveDiagram->theRootLevelDiagram->getSubDiagramByName(diagramFullyQualifiedName);

	// Parse Element's Diagram name
	//  First calculate break point
	std::string withoutEndDot = elementFullyQualifiedName.substr(0,elementFullyQualifiedName.size()-1);
	int breakPoint = withoutEndDot.find_last_of(".")+1;
	//  Then split the info around that point
	std::string theElementDiagramName = elementFullyQualifiedName.substr(0,breakPoint);
	//std::string theElementName = elementFullyQualifiedName.substr(breakPoint);

	// Get Element's Diagram
	elementDiagramResult = (X3DUML::DiagramView*)theInteractiveDiagram->theRootLevelDiagram->getSubDiagramByName(theElementDiagramName);

	// Sanity check
	if (diagramResult == NULL || elementDiagramResult == NULL) return false; // no point in proceeding

	// Find Element within Diagram
	for(size_t i=0;i < elementDiagramResult->contained.size(); i++) // search recursively until we find something
	{
		if (elementDiagramResult->contained.at(i)->fullyQualifiedName.compare(elementFullyQualifiedName) == 0)
		{
			diagramElement = elementDiagramResult->contained.at(i); 
			break;
		}
	}

	// Another sanity check
	if (diagramElement == NULL) return false;

	// Create edge 
	osg::ref_ptr<osg::EdgeTriangle> edge = new osg::EdgeTriangle(diagramElement->geode.get(),diagramResult->contained[0]->geode.get());
	//osg::ref_ptr<osg::EdgeTriangle> edge = new osg::EdgeTriangle(theInteractiveDiagram->theCurrentDiagram->parent->geode.get(),
	//theInteractiveDiagram->theCurrentDiagram->contained[0]->geode.get());
	theInteractiveDiagram->edgeGroup->addChild(edge);

	return false; // current diagram not changed
}