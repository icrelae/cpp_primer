/* 2016.10.04 22:44
 * P_187
 */
unsigned int Fact(unsigned x)
{
	if (x <= 1)
		return 1;
	return (x * Fact(x-1));
}
