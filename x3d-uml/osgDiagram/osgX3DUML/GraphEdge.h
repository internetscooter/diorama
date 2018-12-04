///////////////////////////////////////////////////////////
//  GraphEdge.h
//  Implementation of the Class GraphEdge
//  Created on:      23-Jun-2008 9:51:54 PM
///////////////////////////////////////////////////////////

#if !defined(EA_9E8E6C25_510C_4b89_B013_1419EB833621__INCLUDED_)
#define EA_9E8E6C25_510C_4b89_B013_1419EB833621__INCLUDED_

#include "GraphConnector.h"
#include "GraphElement.h"
#include <vector>
using namespace std;

namespace X3DUML
{
	class GraphEdge : public X3DUML::GraphElement
	{

	public:
		GraphConnector* anchor;
		vector<Point *> waypoints;

		GraphEdge();
		virtual ~GraphEdge();
		void addWayPoint(double x, double y, double z);

	};

}
#endif // !defined(EA_9E8E6C25_510C_4b89_B013_1419EB833621__INCLUDED_)
