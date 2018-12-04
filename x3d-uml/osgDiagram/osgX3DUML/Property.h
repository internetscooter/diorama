///////////////////////////////////////////////////////////
//  Property.h
//  Implementation of the Class Property
//  Created on:      23-Jun-2008 9:25:48 PM
///////////////////////////////////////////////////////////

#if !defined(EA_8EF1E182_B6E3_4de1_B927_53BE66833E43__INCLUDED_)
#define EA_8EF1E182_B6E3_4de1_B927_53BE66833E43__INCLUDED_

#include <string>
using namespace std;


namespace X3DUML
{
	class Property
	{

	public:
		Property();
		virtual ~Property();
		string key;
		string value;

	};

}
#endif // !defined(EA_8EF1E182_B6E3_4de1_B927_53BE66833E43__INCLUDED_)
