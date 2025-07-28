//#include "vld.h" // No memory leaks DETECTED!
#include "windowsWrapper.h"
#include "mat.h"
#include "utils.h"
//#include "_dicShow.h"
using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Portuguese");

	//utils::Console cmd;//(80, 30, "<<_MATH LIBRARY_>>");
	//cmd.setColour(FGI);

	//math::_absUsage();
	//math::_divByUsage();
	//math::_divisoresUsage();
	//countVectorUsage();
//math::_fatoresPrimosUsage();
	//math::_fatorialUsage();
	//math::_mdcUsage();
	//math::_mmcUsage();
	//math::_multiplosUsage();
	//math::_powerUsage();
	//std::cout << utils::_chronometer(&math::_primeUsage) << std::endl;
	math::_primeUsage();
	//math::_raizDigitalUsage();
	//math::_rootUsage();

	//system("pause");
	return(0);
}