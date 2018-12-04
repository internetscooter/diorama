///////////////////////////////////////////////////////////
//  BezierPoint.h
//  Implementation of the Class BezierPoint
//  Created on:      23-Jun-2008 9:39:36 PM
///////////////////////////////////////////////////////////

#if !defined(EA_E1CC1380_8C20_4cbd_9180_1983CDF57C24__INCLUDED_)
#define EA_E1CC1380_8C20_4cbd_9180_1983CDF57C24__INCLUDED_

#include "Point.h"
#include <vector>
using namespace std;

namespace X3DUML
{
	class BezierPoint : public X3DUML::Point
	{

	public:
		vector<Point> controls;

		BezierPoint();
		virtual ~BezierPoint();

	};

}
#endif // !defined(EA_E1CC1380_8C20_4cbd_9180_1983CDF57C24__INCLUDED_)
