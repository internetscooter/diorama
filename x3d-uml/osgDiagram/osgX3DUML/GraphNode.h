///////////////////////////////////////////////////////////
//  GraphNode.h
//  Implementation of the Class GraphNode
//  Created on:      23-Jun-2008 9:54:22 PM
///////////////////////////////////////////////////////////

#if !defined(EA_3E2A059C_2106_45b1_8972_E2AB41116FF6__INCLUDED_)
#define EA_3E2A059C_2106_45b1_8972_E2AB41116FF6__INCLUDED_

#include "Dimension.h"
#include "GraphElement.h"

namespace X3DUML
{
	class GraphNode : public X3DUML::GraphElement
	{

	public:
		GraphNode();
		virtual ~GraphNode();
		void setSize(double width, double height);
		X3DUML::Dimension size;

	};

}
#endif // !defined(EA_3E2A059C_2106_45b1_8972_E2AB41116FF6__INCLUDED_)
