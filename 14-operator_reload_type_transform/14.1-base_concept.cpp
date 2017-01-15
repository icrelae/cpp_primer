/* 2017.01.15 13:57
 * P_493
 * !!!
 * operators can be reloaded: !!!
 *	*	-	*	/	%	^
 *	&	|	~	!	,	=
 *	<	>	<=	>=	++	--
 *	<<	>>	==	!=	&&	||
 *	+=	-=	/=	%=	^=	&=
 *	|=	*=	<<=	>>=	[]	()
 *	->	->*	new	new[]	delete	delete[]
 * operators can't be reloaded: !!!
 *	::	.*	.	? :
 * operators shouldn't be reloaded: !!!
 *	&&	||	,	&
 * member or not: !!!
 * = [] () ->: have to be member of a class
 * += -= *= /= ^= %= >>= <<=: should be member generally
 * operators change obj's state like ++ -- *ptr should be member
 * symmetrical operators like + == & shouldn't be member
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

	return 0;
}

