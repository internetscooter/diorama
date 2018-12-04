///////////////////////////////////////////////////////////
//  Image.h
//  Implementation of the Class Image
//  Created on:      23-Jun-2008 9:54:42 PM
///////////////////////////////////////////////////////////

#if !defined(EA_2232CF20_FE21_4f47_BE65_7F313FB90E23__INCLUDED_)
#define EA_2232CF20_FE21_4f47_BE65_7F313FB90E23__INCLUDED_

#include "LeafElement.h"
#include <string>
using namespace std;

namespace X3DUML
{
	class Image : public X3DUML::LeafElement
	{

	public:
		string mimeType;
		string uri;

		Image();
		virtual ~Image();

	};


}
#endif // !defined(EA_2232CF20_FE21_4f47_BE65_7F313FB90E23__INCLUDED_)
