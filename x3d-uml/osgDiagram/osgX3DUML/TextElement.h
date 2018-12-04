///////////////////////////////////////////////////////////
//  TextElement.h
//  Implementation of the Class TextElement
//  Created on:      23-Jun-2008 9:56:25 PM
///////////////////////////////////////////////////////////

#if !defined(EA_21F52CDC_8CB3_472d_83B6_6AD84A4BCB59__INCLUDED_)
#define EA_21F52CDC_8CB3_472d_83B6_6AD84A4BCB59__INCLUDED_

#include "LeafElement.h"
#include <string>
using namespace std;


namespace X3DUML
{
	class TextElement : public X3DUML::LeafElement
	{

	public:
		string text;

		TextElement();
		virtual ~TextElement();

	};

}
#endif // !defined(EA_21F52CDC_8CB3_472d_83B6_6AD84A4BCB59__INCLUDED_)
