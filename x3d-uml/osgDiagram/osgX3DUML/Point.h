///////////////////////////////////////////////////////////
//  Point.h
//  Implementation of the Class Point
//  Created on:      23-Jun-2008 9:14:55 PM
///////////////////////////////////////////////////////////

#if !defined(EA_CB9CB8AD_586D_4fc4_AF07_5AAA28A04BB0__INCLUDED_)
#define EA_CB9CB8AD_586D_4fc4_AF07_5AAA28A04BB0__INCLUDED_


namespace X3DUML
{
	class Point
	{

	public:		
		double x;
		double y;
		double z; //3D extension
		Point();
		virtual ~Point();
		Point(double initialX, double initialY, double initialZ);

	};

}
#endif // !defined(EA_CB9CB8AD_586D_4fc4_AF07_5AAA28A04BB0__INCLUDED_)
