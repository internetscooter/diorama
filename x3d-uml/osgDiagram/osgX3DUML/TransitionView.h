///////////////////////////////////////////////////////////
//  TransitionView.h
//  Implementation of the Class TransitionView
//  Created on:      24-Jun-2008 9:44:32 PM
///////////////////////////////////////////////////////////

#if !defined(EA_8231083F_698C_46c0_9E13_135640FAB88F__INCLUDED_)
#define EA_8231083F_698C_46c0_9E13_135640FAB88F__INCLUDED_

#include "GraphEdge.h"
#include <osg/Geometry>
#include <osg/LineWidth>
#include <osg/ShapeDrawable>

namespace X3DUML
{
	class TransitionView : public X3DUML::GraphEdge
	{

	public:
		TransitionView();
		virtual ~TransitionView();
		void drawWayPoints();

	};

}
#endif // !defined(EA_8231083F_698C_46c0_9E13_135640FAB88F__INCLUDED_)
