/*
 * @Author: chenq
 * @Date: 2020-11-01 10:20:17
 * @LastEditTime: 2020-11-01 10:34:17
 * @Descripttion: 利用bitset熟悉正负数的原码补码反码
 */
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	bitset<4> bitset1;
	cout << bitset1 << endl;	//0000
	
	bitset<8> bitset2(12);
	cout << bitset2 << endl;	//00001100
	
	string s = "100101";
	bitset<10> bitset3(s);
	cout << bitset3 << endl;	//0000100101
	
	char s2[] = "10101";
	bitset<10> bitset4(s2);
	cout << bitset4 << endl;	//0000010101
	
	//正数的原码、反码、补码都是它本身
	//负数在计算机中都是以补码的形式存在
	//负数的反码是由其原码的符号位不变，其余位按位取反
	//负数的补码是由其原码的符号位不变，其余位按位取反，再再最低位+1
	int a = -6;
	bitset<16> bitset5(a);
	cout<<bitset5<<endl;	//1111111111111010 输出补码。然后我们计算其原码，看看是不是-6
							//1111111111111001 减一
							//1000000000000110 符号位不变，取反，获得原码
}
