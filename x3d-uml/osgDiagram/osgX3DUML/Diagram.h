///////////////////////////////////////////////////////////
//  Diagram.h
//  Implementation of the Class Diagram
//  Created on:      23-Jun-2008 9:40:20 PM
///////////////////////////////////////////////////////////

#if !defined(EA_BC39E369_C952_4792_A02F_C08EBB5BF450__INCLUDED_)
#define EA_BC39E369_C952_4792_A02F_C08EBB5BF450__INCLUDED_

#include "SemanticModelBridge.h"
#include "GraphNode.h"
#include "Point.h"

namespace X3DUML
{
	class Diagram : public X3DUML::GraphNode
	{

	public:
		//string name;
		SemanticModelBridge* owner;
		X3DUML::Point viewport;
		double zoom;

		Diagram();
		virtual ~Diagram();

	};

}
#endif // !defined(EA_BC39E369_C952_4792_A02F_C08EBB5BF450__INCLUDED_)

