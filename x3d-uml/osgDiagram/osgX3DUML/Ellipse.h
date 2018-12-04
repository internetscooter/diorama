///////////////////////////////////////////////////////////
//  Ellipse.h
//  Implementation of the Class Ellipse
//  Created on:      23-Jun-2008 9:50:45 PM
///////////////////////////////////////////////////////////

#if !defined(EA_18DA316D_CC83_4eef_90A9_9AEFB95F2FB6__INCLUDED_)
#define EA_18DA316D_CC83_4eef_90A9_9AEFB95F2FB6__INCLUDED_

#include "GraphicPrimitive.h"
#include "Point.h"

namespace X3DUML
{
	class Ellipse : public X3DUML::GraphicPrimitive
	{

	public:
		X3DUML::Point center;
		double endAngle;
		double radiusX;
		double radiusY;
		double rotation;
		double startAngle;

		Ellipse();
		virtual ~Ellipse();

	};

}
#endif // !defined(EA_18DA316D_CC83_4eef_90A9_9AEFB95F2FB6__INCLUDED_)
