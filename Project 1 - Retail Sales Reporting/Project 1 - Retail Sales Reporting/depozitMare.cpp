#include "Classes.h"

DepozitGlobal::DepozitGlobal() {


}

DepozitGlobal::DepozitGlobal(const DepozitGlobal& other) {

	for (int i = 0; i < NumarSloturi; i++) {
		sloturi[i] = other.sloturi[i];
	}
}

DepozitGlobal::~DepozitGlobal() {

	
}

Stack<Palet>*  DepozitGlobal::GetSloturi() {

	return sloturi;

}