///////////////////////////////////////////////////////////
//  IDiagram.h
//  Implementation of the Class IDiagram
//  Created on:      13-Aug-2008 12:59:55 PM
///////////////////////////////////////////////////////////

#if !defined(EA_4D047BA9_1B4C_46a0_9096_39E86C337772__INCLUDED_)
#define EA_4D047BA9_1B4C_46a0_9096_39E86C337772__INCLUDED_

#include "DiagramView.h"
#include <osgManipulator/CommandManager>

namespace X3DUML
{
	/**
	 * This is an Interactive Diagram. this contains a diagram and enables interaction
	 * techniques manipulating the view to the diagram.
	 */
	class IDiagram
	{

	public:
		IDiagram();
		virtual ~IDiagram();
		DiagramView *theRootLevelDiagram;				// root diagram
		DiagramView *theCurrentDiagram;					// current subdiagram pointer
		osgManipulator::CommandManager* cmdMgr;			// osg command manager for pass events to draggers
		osg::ref_ptr<osg::MatrixTransform> edgeGroup;	// edges are dynamic and use world coordinates
														// so edges are saved in seperate osg tree so they
														// don't get rotated
		void enableManualLayout();						// not used (yet)
	};

}
#endif // !defined(EA_4D047BA9_1B4C_46a0_9096_39E86C337772__INCLUDED_)
