///////////////////////////////////////////////////////////
//  SimpleSemanticModelElement.h
//  Implementation of the Class SimpleSemanticModelElement
//  Created on:      23-Jun-2008 9:56:15 PM
///////////////////////////////////////////////////////////

#if !defined(EA_6A1F3CC5_C2A2_473b_9B69_A3CFB55D8B0C__INCLUDED_)
#define EA_6A1F3CC5_C2A2_473b_9B69_A3CFB55D8B0C__INCLUDED_

#include "SemanticModelBridge.h"
#include <string>
using namespace std;


namespace X3DUML
{
	class SimpleSemanticModelElement : public X3DUML::SemanticModelBridge
	{

	public:
		string typeInfo;

		SimpleSemanticModelElement();
		virtual ~SimpleSemanticModelElement();

	};

}
#endif // !defined(EA_6A1F3CC5_C2A2_473b_9B69_A3CFB55D8B0C__INCLUDED_)
