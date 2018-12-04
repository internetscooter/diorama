///////////////////////////////////////////////////////////
//  TextView.h
//  Implementation of the Class TextView
//  Created on:      24-Jun-2008 1:23:41 PM
///////////////////////////////////////////////////////////

#if !defined(EA_A798DAD6_85C3_42e6_AE00_12C5DBB9380C__INCLUDED_)
#define EA_A798DAD6_85C3_42e6_AE00_12C5DBB9380C__INCLUDED_

#include "GraphNode.h"
#include <osgText/Font>
#include <osgText/Text>
#include <string>
using namespace std;

namespace X3DUML
{
	class TextView : public X3DUML::GraphNode
	{

	public:
		TextView(string thetext);
		TextView(string thetext, double x, double y, double z);
		virtual ~TextView();
		osgText::Text* text;
	};

}
#endif // !defined(EA_A798DAD6_85C3_42e6_AE00_12C5DBB9380C__INCLUDED_)
