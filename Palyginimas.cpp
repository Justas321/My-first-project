#include "mylib.h"
#include "struc.h"
#include "func.h"

bool Palyginimas(duom pirmas, duom antras)
{
    if (pirmas.vardas != antras.vardas)
        return pirmas.vardas > antras.vardas;
    if (pirmas.pavarde != antras.pavarde)
        return pirmas.pavarde > antras.pavarde;
    return pirmas.galutinis > antras.galutinis;
}
