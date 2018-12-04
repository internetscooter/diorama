///////////////////////////////////////////////////////////
//  Reference.h
//  Implementation of the Class Reference
//  Created on:      23-Jun-2008 9:55:58 PM
///////////////////////////////////////////////////////////

#if !defined(EA_2B1551A7_04E2_4b80_922A_1ED3E1A7D221__INCLUDED_)
#define EA_2B1551A7_04E2_4b80_922A_1ED3E1A7D221__INCLUDED_

#include "DiagramElement.h"


namespace X3DUML
{
	class Reference : public X3DUML::DiagramElement
	{

	public:
		bool isIndividualRepresentation;
		DiagramElement* referenced;

		Reference();
		virtual ~Reference();

	};

}
#endif // !defined(EA_2B1551A7_04E2_4b80_922A_1ED3E1A7D221__INCLUDED_)
