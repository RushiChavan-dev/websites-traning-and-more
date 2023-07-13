#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include"Date.h"
#include"Streamable.h"
#include"Lib.h"
namespace sdds
{
	class Publication:public Streamable
	{
		char* m_title{};
		char m_shelfld[SDDS_SHELF_ID_LEN+1];
		int m_membership{};
		int m_libRef = -1;
		Date m_date;
	public:
		void set();
		Publication();
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.

		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;
		

		// Rule of the three
		Publication(const Publication& pub);
		Publication& operator=(const Publication&);
		~Publication();
		void init(const Publication& scr);
	};
	
}
#endif // !SDDS_PUBLICATION_H