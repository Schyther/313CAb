#include "Classes.h"

DepozitGlobal::DepozitGlobal() {


}

DepozitGlobal::DepozitGlobal(const DepozitGlobal& other) {

	paleti = other.paleti;
}

DepozitGlobal::~DepozitGlobal() {

	
}

ResizableArray<Stack<Palet>>& DepozitGlobal::GetPaleti() {

	return paleti;

}