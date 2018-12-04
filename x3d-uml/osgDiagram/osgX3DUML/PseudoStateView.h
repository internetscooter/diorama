///////////////////////////////////////////////////////////
//  PseudoStateView.h
//  Implementation of the Class PseudoStateView
//  Created on:      24-Jun-2008 9:18:13 PM
///////////////////////////////////////////////////////////

#if !defined(EA_91F911E3_E8AF_446d_A076_74CD220E4C9A__INCLUDED_)
#define EA_91F911E3_E8AF_446d_A076_74CD220E4C9A__INCLUDED_

#include "GraphNode.h"
#include <osg/ShapeDrawable>
#include <osg/Geometry>
#include <osg/LineWidth>

namespace X3DUML
{
	class PseudoStateView : public X3DUML::GraphNode
	{

	public:
		enum Stereotype { Initial, EntryPoint, ExitPoint, Choice, Junction, History, Terminate, Final, Fork, Join };
		PseudoStateView();
		PseudoStateView(double width, double height, double x, double y, double z, X3DUML::PseudoStateView::Stereotype stereotype);
		virtual ~PseudoStateView();
	};

}
#endif // !defined(EA_91F911E3_E8AF_446d_A076_74CD220E4C9A__INCLUDED_)
