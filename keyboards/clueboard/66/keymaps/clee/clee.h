#pragma once

#define kNO KC_NO

#define CLEEOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k50, k51, k52, k53, k54, k55, k56, k57, \
    k10, k11, k12, k13, k14, k15, k16, k17, k60, k61, k62, k63, k64, k65,      k67, \
    k20, k21, k22, k23, k24, k25, k26, k27, k70, k71, k72, k73,      k75, \
    k30,      k32, k33, k34, k35, k36, k37, k80, k81, k82, k83,      k85, k86, \
    k40,      k42, k43,      k45, k46,      k90,      k92,      k94, k95, k96, k97 \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, k17 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, kNO, k32, k33, k34, k35, k36, k37 }, \
    { k40, kNO, k42, k43, kNO, k45, k46, kNO }, \
    { k50, k51, k52, k53, k54, k55, k56, k57 }, \
    { k60, k61, k62, k63, k64, k65, kNO, k67 }, \
    { k70, k71, k72, k73, kNO, k75, kNO, kNO }, \
    { k80, k81, k82, k83, kNO, k85, k86, kNO }, \
    { k90, kNO, k92, kNO, k94, k95, k96, k97 }  \
}
