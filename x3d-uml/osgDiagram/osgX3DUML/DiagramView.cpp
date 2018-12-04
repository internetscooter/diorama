///////////////////////////////////////////////////////////
//  DiagramView.cpp
//  Implementation of the Class DiagramView
//  Created on:      24-Jun-2008 9:17:55 PM
///////////////////////////////////////////////////////////

#include "DiagramView.h"

using X3DUML::DiagramView;


DiagramView::DiagramView(){
	group->addDescription("DiagramView");
	type = "DiagramView";
}

DiagramView::DiagramView(string diagramName){
	name = diagramName;
	fullyQualifiedName = diagramName + "." ;
	group->addDescription("DiagramView");
	type = "DiagramView";
}

DiagramView::~DiagramView(){

}

X3DUML::DiagramElement* DiagramView::getSubDiagramByName(std::string subDiagramPartialName)
{
	// Expected format is "Ourname.SubDiagramName.SubdiagramName"
	// Example we are "Root." and are passed "Top." (from "Root.Top." full path)
	// First we'll split the string up into ourname and the next diagram name
	std::string thisDiagramName = subDiagramPartialName.substr(0, subDiagramPartialName.find_first_of('.'));
	std::string nextSubDiagramName = subDiagramPartialName.substr(subDiagramPartialName.find_first_of('.')+1);
	X3DUML::DiagramElement* diagramPtr;

	// If there is just one name we can determine quickly if that name is the same as ours
	if (subDiagramPartialName.compare(this->name + ".") == 0)
	{
		return this;
	}
	else // Then we separate out the bits we need e.g. "SomeName." and "SomeName.SomeName..."
	{
		// Then we check if we are in the right branch
		if (thisDiagramName.compare(this->name) != 0) // the diagram name requested doesn't match up
		{
			return NULL;
		}
		else	// we are the right branch lets look at our contents
		{
			for(size_t i=0;i < contained.size(); i++) // search recursively until we find something
				{
					diagramPtr = contained.at(i)->getSubDiagramByName(nextSubDiagramName);
					if (diagramPtr != NULL) return diagramPtr;
				}
				return NULL; // or give up
		}
	}
	return NULL; // shouldn't get here but it's nice to be safe
}