///////////////////////////////////////////////////////////
//  TextView.cpp
//  Implementation of the Class TextView
//  Created on:      24-Jun-2008 1:23:42 PM
///////////////////////////////////////////////////////////

#include "TextView.h"

using X3DUML::TextView;

TextView::TextView(string thetext){
	text = new osgText::Text;
	text->setText(thetext);
	geode->addDrawable(text);
	//default appearance
	osg::Vec4 characterSizeModeColor(0.0f,0.0f,0.0f,1.0f);
	text->setColor(characterSizeModeColor);
	//text->setFont("fonts/cour.ttf");
	text->setFont("fonts/ARIAL.TTF");
	//text->setFontResolution(10,10);
	//text->setCharacterSize(0.2f);
	/*				junkText->setColor(characterSizeModeColor);
				junkText->setFont("fonts/cour.ttf");
				//junkText->setFontResolution(10,10);
				junkText->setCharacterSize(characterSize);
				junkText->setPosition(posTemp);
				junkText->setAxisAlignment(osgText::Text::XZ_PLANE);
				junkText->setText("Class");
				geode->addDrawable(junkText);*/
}

TextView::TextView(string thetext, double x, double y, double z) 
{
	//set text
	text = new osgText::Text;
	text->setText(thetext);
	setPosition(x,y,z);
	//default appearance
	osg::Vec4 characterSizeModeColor(0.0f,0.0f,0.0f,1.0f);
	text->setColor(characterSizeModeColor);
	//text->setFont("fonts/cour.ttf");
	text->setFont("fonts/ARIAL.TTF");
	text->setAlignment(osgText::Text::CENTER_CENTER);
	//text needs to be flipped 180 degres
	text->setRotation(osg::Quat(osg::inDegrees(180.0f),osg::Vec3(1.0f,0.0f,0.0f)));
	geode->addDrawable(text);
}
TextView::~TextView(){

}