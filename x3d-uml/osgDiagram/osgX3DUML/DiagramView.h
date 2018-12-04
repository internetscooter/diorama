///////////////////////////////////////////////////////////
//  DiagramView.h
//  Implementation of the Class DiagramView
//  Created on:      24-Jun-2008 9:17:55 PM
///////////////////////////////////////////////////////////

#if !defined(EA_244AB7EF_C634_488b_B778_18D5440D8C99__INCLUDED_)
#define EA_244AB7EF_C634_488b_B778_18D5440D8C99__INCLUDED_

#include "DiagramElement.h"
#include "Diagram.h"


namespace X3DUML
{
	class DiagramView : public X3DUML::Diagram
	{
	public:
		DiagramView();
		DiagramView(string diagramName);
		virtual ~DiagramView();

		//extra bits for keeping a track of relationships (due to not relying on UML Model via SemanticModelBridge)
		Diagram* parentDiagram; //pointer to the diagram this is contained by
		DiagramElement* getSubDiagramByName(std::string subDiagramPartialName);
	};

}
#endif // !defined(EA_244AB7EF_C634_488b_B778_18D5440D8C99__INCLUDED_)
