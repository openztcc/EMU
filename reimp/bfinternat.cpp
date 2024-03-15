#include "bfinternat.h"

void bfinternat::setMoneyText(int param_1, int param_2, char param_3) {
    _setMoneyText og_setMoneyText = (_setMoneyText)0x0040ed88;

   og_setMoneyText(param_1, param_2, param_3);
}