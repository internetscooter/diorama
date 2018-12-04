///////////////////////////////////////////////////////////
//  StateView.cpp
//  Implementation of the Class StateView
//  Created on:      24-Jun-2008 9:18:05 PM
///////////////////////////////////////////////////////////

#include "StateView.h"
#include <osg/TriangleFunctor>
#include <osg/LineWidth>
#include <osg/Material>
#include <osg/BlendFunc>

using X3DUML::StateView;

StateView::StateView(){
	group->addDescription("StateView");
	name = "StateView";
	type = "StateView";
}

StateView::StateView(double width, double height, double x, double y, double z, float transparency){
	group->addDescription("StateView");
	name = "StateView";
	type = "StateView";
	setSize(width,height);
	setPosition(x,y,z);
	x3dumlTransparency = transparency;
    // For the state we need a shape...
	// Calculate rounded corners
	double cornerRadius = width / 10;
    double crnV1 = cornerRadius / 10; // values for working out edge curves on corners
    double crnV2 = cornerRadius / 2;  // values for working out edge curves on corners
	// May be needed for really small states
    //if (stateView.size.width < cornerRadius * 2) stateView.size.width = cornerRadius * 2;
    //if (stateView.size.height < cornerRadius * 2) stateView.size.height = cornerRadius * 2;

    // this time we'll a C arrays to initialize the vertices.     

    osg::Vec3 myCoords[] =
    {
		osg::Vec3(0, cornerRadius, 0),								// 1
		osg::Vec3(crnV1, cornerRadius - crnV2, 0),					// 2
		osg::Vec3(cornerRadius - crnV2, crnV1, 0),					// 3
		osg::Vec3(cornerRadius, 0, 0),								// 4
		osg::Vec3(width - cornerRadius, 0, 0),						// 5
		osg::Vec3(width - cornerRadius + crnV2, crnV1, 0),			// 6
		osg::Vec3(width - crnV1, crnV2, 0),							// 7
		osg::Vec3(width, cornerRadius, 0),							// 8
		osg::Vec3(width, height - cornerRadius, 0),					// 9
		osg::Vec3(width - crnV1, height - cornerRadius + crnV2, 0), // 10
		osg::Vec3(width - cornerRadius + crnV2, height - crnV1, 0), // 11
		osg::Vec3(width - cornerRadius, height, 0),					// 12
		osg::Vec3(cornerRadius, height, 0),							// 13
		osg::Vec3(cornerRadius - crnV2, height - crnV1, 0),			// 14
		osg::Vec3(crnV1, height - cornerRadius + crnV2, 0),			// 14
		osg::Vec3(0, height - cornerRadius, 0)						// 15
    };
    int numCoords = sizeof(myCoords)/sizeof(osg::Vec3);
    osg::Vec3Array* vertices = new osg::Vec3Array(numCoords,myCoords);
	
	/* For the outside line...
		create Geometry object to store all the vertices and lines primitive.
	*/
    osg::Geometry* stateBorderLinesGeom = new osg::Geometry();

    // pass the created vertex array to the points geometry objects.
    stateBorderLinesGeom->setVertexArray(vertices);

    // set the colors as before, plus using the above
    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,0.0f)); //black
    stateBorderLinesGeom->setColorArray(colors);
    stateBorderLinesGeom->setColorBinding(osg::Geometry::BIND_OVERALL);
    
    // set the normal in the same way color.
    osg::Vec3Array* normals = new osg::Vec3Array;
    normals->push_back(osg::Vec3(0.0f,-1.0f,0.0f));
    stateBorderLinesGeom->setNormalArray(normals);
    stateBorderLinesGeom->setNormalBinding(osg::Geometry::BIND_OVERALL);
    
    // This time we simply use primitive, and hardwire the number of coords to use 
    // since we know up front,
    stateBorderLinesGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP,0,numCoords));
	// Standard lines are one pixel in width, we need to lines wider to be more easily seen
	// TODO: This might be better at the root node, set one line state for everything
	// and let it cascade down rather than doing it for every line.
	// See  OSGQSG.pdf 2.4 Rendering State
	osg::StateSet* lineState = stateBorderLinesGeom->getOrCreateStateSet();
	osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
	lineState->setAttribute(lineWidth);
    
    // add the points geometry to the geode.
    geode->addDrawable(stateBorderLinesGeom);

	/* For the filling...
		create Geometry object to store all the vertices and lines primitive.
	*/

	osg::Geometry* stateFillingPolyGeom = new osg::Geometry();

	// pass the created vertex array to the points geometry objects.
	stateFillingPolyGeom->setVertexArray(vertices);
   
	// use the shared color array.
	osg::ref_ptr<osg::Vec4Array> shared_colors = new osg::Vec4Array;
	shared_colors->push_back(osg::Vec4(1.0f,1.0f,0.0f,x3dumlTransparency));

	stateFillingPolyGeom->setColorArray(shared_colors.get());
	stateFillingPolyGeom->setColorBinding(osg::Geometry::BIND_OVERALL);
    
	// same trick for shared normal.
	osg::ref_ptr<osg::Vec3Array> shared_normals = new osg::Vec3Array;
	shared_normals->push_back(osg::Vec3(0.0f,0.0f,-1.0f));

	// use the shared normal array.
	stateFillingPolyGeom->setNormalArray(shared_normals.get());
	stateFillingPolyGeom->setNormalBinding(osg::Geometry::BIND_OVERALL);
	// Create an array for the single normal.
	//osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array;
	//stateFillingPolyGeom->setNormalArray( n.get() );
	//stateFillingPolyGeom->setNormalBinding( osg::Geometry::BIND_OVERALL );
	//n->push_back( osg::Vec3( 0.f, 1.f, 0.f ) );

	// This time we simply use primitive, and hardwire the number of coords to use 
	// since we know up front,
	stateFillingPolyGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,numCoords));

	// Make the state transparent if needed
	if (x3dumlTransparency > 0)
	{
		osg::StateSet* stateFillingStateSet = stateFillingPolyGeom->getOrCreateStateSet();
	
		//osg::Material* material = dynamic_cast<osg::Material*>(stateFillingStateSet->getAttribute(osg::StateAttribute::MATERIAL)); 
		//if (material) 
		//{ 
		//	material->setAlpha(osg::Material::FRONT_AND_BACK,x3dumlTransparency); 
		//} 

		//stateFillingStateSet->setMode(GL_BLEND,osg::StateAttribute::ON|osg::StateAttribute::OVERRIDE);
		//osg::Material* mat = new osg::Material;
		//mat->setAlpha(osg::Material::FRONT_AND_BACK,x3dumlTransparency);
		//mat->setColorMode(osg::Material::AMBIENT_AND_DIFFUSE);
		//stateFillingStateSet->setAttributeAndModes(mat,osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

		osg::BlendFunc* bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
		stateFillingStateSet->setAttributeAndModes(bf);
		stateFillingStateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

		//stateFillingStateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
		//stateFillingStateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		//stateFillingPolyGeom->setStateSet(stateFillingStateSet);

	}

	//osg::TriangleFunctor<NormalPrint> tf;
	//stateFillingPolyGeom->accept(tf);
	//printTriangles("Polygon",*stateFillingPolyGeom);
    
	// add the points geometry to the geode.
	if (x3dumlTransparency > 0.1) // but only if we want it visible
	{
		geode->addDrawable(stateFillingPolyGeom);
	}
}

//StateView::StateView(double width, double height, double x, double y, double z, int colour){
//	group->addDescription("StateView");
//	name = "StateView";
//	type = "StateView";
//	setSize(width,height);
//	setPosition(x,y,z);
//	//colour
//}


StateView::~StateView(){

}