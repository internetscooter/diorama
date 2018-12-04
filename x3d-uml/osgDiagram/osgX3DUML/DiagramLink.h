///////////////////////////////////////////////////////////
//  DiagramLink.h
//  Implementation of the Class DiagramLink
//  Created on:      23-Jun-2008 9:46:05 PM
///////////////////////////////////////////////////////////

#if !defined(EA_1A12AB5C_4CDA_474b_9888_1B2F5E53005B__INCLUDED_)
#define EA_1A12AB5C_4CDA_474b_9888_1B2F5E53005B__INCLUDED_

#include "Diagram.h"


namespace X3DUML
{
	class DiagramLink
	{

	public:
		Diagram* diagram;
		X3DUML::Point viewport;
		double zoom;
		DiagramLink();
		virtual ~DiagramLink();

	};

}
#endif // !defined(EA_1A12AB5C_4CDA_474b_9888_1B2F5E53005B__INCLUDED_)
