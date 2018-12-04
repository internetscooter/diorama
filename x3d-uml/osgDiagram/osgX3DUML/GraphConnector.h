///////////////////////////////////////////////////////////
//  GraphConnector.h
//  Implementation of the Class GraphConnector
//  Created on:      23-Jun-2008 9:51:40 PM
///////////////////////////////////////////////////////////

#if !defined(EA_42E004EA_4EE7_47f4_88DB_A1427366B935__INCLUDED_)
#define EA_42E004EA_4EE7_47f4_88DB_A1427366B935__INCLUDED_

#include "Point.h"

namespace X3DUML
{
	class GraphConnector
	{

	public:
		X3DUML::Point position;

		GraphConnector();
		virtual ~GraphConnector();

	};

}
#endif // !defined(EA_42E004EA_4EE7_47f4_88DB_A1427366B935__INCLUDED_)
