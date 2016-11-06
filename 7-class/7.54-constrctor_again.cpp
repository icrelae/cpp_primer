/* 2016.11.03 21:33
 * P_268
 * !!!
 * void set_io(bool b) { io = b;} should not be constexpr,
 * condition for constexpr function: !!!
 * 1) there should be only "return xx;" expression in function body
 * 2) variable type of parameters and returned value should be literal.
 */
