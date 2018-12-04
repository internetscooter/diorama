///////////////////////////////////////////////////////////
//  StateView.h
//  Implementation of the Class StateView
//  Created on:      24-Jun-2008 9:18:05 PM
///////////////////////////////////////////////////////////

#if !defined(EA_83EBA1C1_724D_4693_A890_167E0FB4889F__INCLUDED_)
#define EA_83EBA1C1_724D_4693_A890_167E0FB4889F__INCLUDED_

#include "GraphNode.h"
#include <osg/Geometry>

namespace X3DUML
{
	class StateView : public X3DUML::GraphNode
	{

	public:
		StateView();
		StateView(double width, double height, double x, double y, double z, float transparency = 1.0);
		//StateView(double width, double height, double x, double y, double z, int colour);
		virtual ~StateView();

	};

}
#endif // !defined(EA_83EBA1C1_724D_4693_A890_167E0FB4889F__INCLUDED_)
