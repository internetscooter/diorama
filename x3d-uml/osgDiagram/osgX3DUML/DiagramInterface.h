///////////////////////////////////////////////////////////
//  DiagramInterface.h
//  Implementation of the Class DiagramInterface
//  Created on:      14-May-2009 9:28:06 PM
//  Original author: internetscooter
///////////////////////////////////////////////////////////

#if !defined(EA_93DC7B6E_420F_4409_921E_6722257627AC__INCLUDED_)
#define EA_93DC7B6E_420F_4409_921E_6722257627AC__INCLUDED_

#include <osg/Group>

namespace X3DUML
{
	class IDiagram; // forward reference 
					// Not made a member to insulate implementation from users
					// See "Insulation": Large Scale C++ Software Design - John Lakos

	class DiagramInterface
	{

	public:
		DiagramInterface();
		virtual ~DiagramInterface();
		/*
			The complete diagram is a tree structure of diagrams. The "current diagram" pointer is an internal 
			pointer to the active diagram. All "add" functions add to the "current diagram". 
			This pointer can be changed externally by either:
			* adding a new diagram which by default makes the new diagram the "current diagram"
			* setting the "current diagram" by it's fully qualified name (e.g. "Root.Top." sets "Top as the "current diagram"
		
			When the diagram is finished being created. Call "RenderDiagram" to create 3D data from the diagram data
			Note: Has only been tested for the scenario of creating diagram once may need to be updated for iterative building
		*/

		/* 
			creating the diagram. These add to the "current diagram" pointer
		*/
		std::string AddDiagram(std::string name);		// create a subdiagram of the current diagram and make it the "current diagram"
		std::string AddStateView(double Width, double Height, double X, double Y, double Z);
		std::string AddTextView(std::string text, double X, double Y, double Z);
		std::string AddPseudoStateView(double Width, double Height, double X, double Y, double Z, std::string PseudoStateType);
		std::string AddTransitionView(std::string WayPointsCSVString);

		/* 
			getting info about the diagram
		*/
		std::string CurrentDiagramName();						// returns the name of the current diagram (e..g "Top")
		std::string CurrentDiagramFullQualifiedName();			// returns the full path name (e.g. ".Root.Top")
		/* 
			setting the "current diagram" pointer
		*/
		bool SetOrCreateCurrentDiagram(std::string fullyQualifiedName);
		bool SetCurrentDiagram(std::string fullyQualifiedName);
		/*
			Linking diagram elements
		*/
		// Creates a trianle where the base is at the diagram and the point is at the element
		bool LinkElementToDiagram(std::string elementFullyQualifiedName, std::string diagramFullyQualifiedName);

		osg::ref_ptr<osg::Group> RenderDiagram();				// call this last when all diagram work is done
		osg::ref_ptr<osg::Group> RenderWorldEdges();			// call this additionally if world edges are used
		osg::ref_ptr<osg::Group> TestScreen(std::string name);	// produce something to look at for testing 
		int planeDepth;											// this controls diagram depth
	private:
		X3DUML::IDiagram* theInteractiveDiagram;	// interactive space the diagram lives in
		std::vector<std::string> diagramLinks;					// stores a list of element names to link at render time

		bool CreateEdge(std::string elementFullyQualifiedName, std::string diagramFullyQualifiedName);

	};

}
#endif // !defined(EA_93DC7B6E_420F_4409_921E_6722257627AC__INCLUDED_)
