///////////////////////////////////////////////////////////
//  Polyline.h
//  Implementation of the Class Polyline
//  Created on:      23-Jun-2008 9:55:38 PM
///////////////////////////////////////////////////////////

#if !defined(EA_8789BF76_B289_4f84_A044_42FC631120D1__INCLUDED_)
#define EA_8789BF76_B289_4f84_A044_42FC631120D1__INCLUDED_

#include "GraphicPrimitive.h"
#include "Point.h"
#include <vector>
using namespace std;


namespace X3DUML
{
	class Polyline : public X3DUML::GraphicPrimitive
	{

	public:
		bool closed;
		vector<Point> waypoints;

		Polyline();
		virtual ~Polyline();

	};

}
#endif // !defined(EA_8789BF76_B289_4f84_A044_42FC631120D1__INCLUDED_)
