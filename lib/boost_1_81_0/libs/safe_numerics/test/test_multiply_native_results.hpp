#include "test_values.hpp"

constexpr const char *test_multiplication_native_result[
    boost::mp11::mp_size<test_values>::value
] = {
//      0       0       0       0
//      012345670123456701234567012345670
//      012345678901234567890123456789012
/* 0*/ ".................................",
/* 1*/ ".........xx..xx..........xxx.xxx.",
/* 2*/ ".........xx..xx.........xxxxxxxx.",
/* 3*/ "..........x...x.........xxxxxxxx.",
/* 4*/ ".................................",
/* 5*/ ".........xx..xx..........xxx.xxx.",
/* 6*/ ".........xx..xx.........xxxxxxxx.",
/* 7*/ "..........x...x.........xxxxxxxx.",

/* 8*/ ".................................",
/* 9*/ ".xx..xx..xx..xx..xxx.xxx.xxx.xxx.",
/*10*/ ".xxx.xxx.xxx.xx..xxx.xxxxxxxxxxx.",
/*11*/ "..........x...x.........xxxxxxxx.",
/*12*/ ".................................",
/*13*/ ".xx..xx..xx..xx..xxx.xxx.xxx.xxx.",
/*14*/ ".xxx.xxx.xxx.xxx.xxx.xxx.xxxxxxx.",
/*15*/ "..............x.............xxxx.",

//      0       0       0       0
//      012345670123456701234567012345670
//      012345678901234567890123456789012
/*16*/ ".................................",
/*17*/ ".........xx..xx..........xxx.xxx.",
/*18*/ ".........xx..xx..........xxx.xxx.",
/*19*/ ".........xx..xx..........xxx.xxx.",
/*20*/ ".................................",
/*21*/ ".........xx..xx..........xxx.xxx.",
/*22*/ ".........xx..xx..........xxx.xxx.",
/*23*/ ".........xx..xx........x.xxx.xxx.",

/*24*/ "..xx..xx..xx.....................",
/*25*/ ".xxx.xxx.xxx.xx..xxx.xxx.xxx.xxx.",
/*26*/ ".xxx.xxx.xxx.xx..xxx.xxx.xxx.xxx.",
/*27*/ ".xxx.xxx.xxx.xx..xxx.xxx.xxx.xxx.",
/*28*/ "..xx..xx..xx..xx.................",
/*29*/ ".xxx.xxx.xxx.xxx.xxx.xxx.xxx.xxx.",
/*30*/ ".xxx.xxx.xxx.xxx.xxx.xxx.xxx.xxx.",
/*31*/ ".xxx.xxx.xxx.xxx.xxx.xxx.xxx.xxx.",
/*31*/ "................................."
};
