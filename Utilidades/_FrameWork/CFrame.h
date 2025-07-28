#pragma once
#include <iostream>

namespace utils {

	enum colour { RED, BLUE, YELLOW, GREEN }; // Same as assining names to ints	

	class CFrame {
	private: // defaults to private
		int    m_a, m_b;
		bool   m_bool;
		double m_double;
	protected:
	public:
		// Construtor padrão:
		CFrame() :m_a(0), m_b(1), m_double(0.0) { std::cout << "Frame()...\n"; /*utils::require()*/ }
		CFrame(const int &_a, const int &_b) : m_a(_a), m_b(_b) { }//DS_("Frame(const int, const int)...") /*utils::require()*/ } 
		~CFrame() { std::cout << "~Frame()...\n"; }
		// Operações:
		// (...)
		// Streamming de sa�da:
		friend std::ostream& operator<<(std::ostream& _os, const CFrame &_f) {
			_os << _f.m_a << "/" << _f.m_b;
			return _os;
		}
	};
	// **************<<_USAGE_>>****************
	static void _frameUsage() {
		CFrame f;
	}

} // utils