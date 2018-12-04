///////////////////////////////////////////////////////////
//  GraphElement.h
//  Implementation of the Class GraphElement
//  Created on:      23-Jun-2008 9:33:50 PM
///////////////////////////////////////////////////////////

#if !defined(EA_68EB56E4_5219_4a89_B0DA_46E506196807__INCLUDED_)
#define EA_68EB56E4_5219_4a89_B0DA_46E506196807__INCLUDED_

#include "GraphConnector.h"
#include "SemanticModelBridge.h"
//#include "DiagramLink.h"
#include "DiagramElement.h"
//#include <string>

namespace X3DUML
{
	class GraphElement : public X3DUML::DiagramElement
	{

	public:
		GraphElement();
		virtual ~GraphElement();
		std::string addDiagramElement(DiagramElement* element);
		std::string addGraphElement(GraphElement* element);
		bool containsDiagramElement(std::string type, std::string name);
		void updateOSGGroup();
		void setPosition(double x, double y, double z);
		// position should be private eventually!!! When we update x, y or z
		// we need to do it via setPostion because we need to update the osg matrix
		// at the same time.
		X3DUML::Point position;  
		GraphConnector *anchorage;
		SemanticModelBridge *semanticModel;
		/**
		 * vector<DiagramElement> contained;
		 */
		vector<DiagramElement *> contained;
//todo		DiagramLink *link;
	};

}
#endif // !defined(EA_68EB56E4_5219_4a89_B0DA_46E506196807__INCLUDED_)
