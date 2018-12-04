///////////////////////////////////////////////////////////
//  DiagramElement.h
//  Implementation of the Class DiagramElement
//  Created on:      23-Jun-2008 9:22:39 PM
///////////////////////////////////////////////////////////

#if !defined(EA_E1345A41_00D8_43d6_809C_AE80238CF495__INCLUDED_)
#define EA_E1345A41_00D8_43d6_809C_AE80238CF495__INCLUDED_

#include "Property.h"
#include <osg/MatrixTransform>
#include <osgManipulator/Selection>
#include <osgManipulator/Translate2DDragger>
#include <osgManipulator/CommandManager>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osgDB/ReadFile>
#include <osgText/Font>
#include <osgText/Text>
#include <vector>

namespace X3DUML
{
	class DiagramElement
	{
private:


	public:
		DiagramElement();
		virtual ~DiagramElement();
		virtual void updateOSGGroup();
		osg::ref_ptr<osg::MatrixTransform> customDraggerxform;
		void makeDraggable(osgManipulator::CommandManager* cmdMgr, float xPos, float yPos, float zPos,float height, float width, float depth);
		bool isVisible;
		Property *property;
        // Optional properties (Section 8.5 of Diagram Interchange spec)    
        // Note that not all these are used (e.g. linethickness should be used from here but has
        // currently been hardcoded at 2.0
                                            // Example             Description
        string FontFamily;           // Times’, ‘Courier’   font name
        double FontSize;             // 11.0                font size in pixel
        string LineStyle;            // ‘solid’, ‘dotted’   line style
        double LineThickness;        // 2.0                 line thickness in pixel
        int FontColor;               // FF00FF for magenta  24-bit color value in RGB format
        int ForegroundColor;         // FF00FF for magenta  24-bit color value in RGB format
        int BackgroundColor;         // FF00FF for magenta  24-bit color value in RGB format
        bool Translucent;            // true/false
		/**
		 * visualisation geode for OSG drawables
		 */
		osg::ref_ptr<osg::Geode> geode;
		osg::ref_ptr<osgManipulator::Translate2DDragger> dragger;
		osg::ref_ptr<osgManipulator::Selection> draggerSelection;
		/**
		 * visualisation group for OSG geodes
		 */
		osg::ref_ptr<osg::MatrixTransform> group;
		/**
		 * Extension to allow things to be transparent when required
		 */
		float x3dumlTransparency;
		/**
		 * Extension to allow things to be dragged about a scene when required
		 */
		bool x3dumlDraggable;
		/**
		 * Extension to allow things to allow us to get things by name
		 */	
		// these should be made private later
		string fullyQualifiedName; //name of element plus the hierarachy seperated by "." (e.g. Top.S1.)
		string name;
		string type;	// name of the element type so we can have different types of elements with the same name
		bool isfullyQualifiedName(std::string theName);
		/*
		*  return a pointer to a subdiagram using appropriate sections of the fullyqualified name to recurse the structure
		*  e.g. Root.L1.L2 calls getSubDiagramByName("L1.L2") on it's contained and Root.L1 calls getSubDiagramByName("L2")
		*/
		virtual DiagramElement* getSubDiagramByName(std::string subDiagramPartialName); 
		//virtual DiagramElement* getSubDiagramElementByName(std::string subDiagramPartialName); 
		DiagramElement* parent;
	};

}
#endif // !defined(EA_E1345A41_00D8_43d6_809C_AE80238CF495__INCLUDED_)
