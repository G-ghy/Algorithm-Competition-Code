/**
 * 如果本题仅要求一个最少操作次数，那做法就不好说了
 * 但是它要求把操作路径求出来，大概率是搜索
 * 
 * 暴力做法很简单，选择要操作的前缀长度无非及时从1->n，搜索每一个状态同时记录当前状态的上一个状态通过bfs很容易找到最短路径
 * 暴力做法存在以下几个问题：
 * 1. 无法保证复杂度满足要求，题目中虽然给定n的范围最大是1e5，但是又给到n的和不超过1e5。之前的某些题目看似复杂度不行的，但是复杂度最终转化到n的和上实际上是可行的，但是本题我没有找到方法
 * 2. 这样模拟，字符串的invert和reverse难以实现
 * 
 * 暴力搜索的想法是搜索所有状态，还有一种想法是
 * 对于目标串，可以考虑从后向前逐一满足，因为选择前缀进行操作不会影响后面的值
 * 每次reverse都是将第一个字符放到当前位置，仅需要满足第一个字符能够invert为目标串待满足目标字符即可，
 * 即满足目标串的一个位置对于原串的最多操作次数为2，即最多2n次即可将原串转化为目标串
 * 
 * 虽然这样的想法不同于搜索，但是模拟实现字符串的invert和reverse的操作还是无法解决
 * 这里需要考虑到对于原串而言，只有第一个和最后一个位置的数值是当前需要的，这里利用的是懒惰求值的思想，即不用时不改，用到时再更新获取
 * reverse并不会真的对一段区间进行模拟reverse，而是通过交换首尾指针实现逻辑上的reverse，物理上不改变
 * invert也不会立刻对一段区间进行invert，而是通过记录invert的次数，当用到区间中的某值时再计算多次invert后的结果
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n;
char a[N], b[N];
char fc; // 原串首字符
int l, r, now; // l，r：原串首指针，尾指针 now：目标串待处理位置指针
int change, offset; // change：invert次数，懒惰求值使用 offset：r指针的偏移量
int res[N << 1], cnt; // 答案序列及答案计数器

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		l = 1, r = now = n;
		change = cnt = 0;
		offset = 1;

		while (now)
		{
			// if (change & 1) a[l] = !(a[l] - '0') + '0';
			// fc = a[l];
			/**
			 * 这里可以这么想，当a[l]为1，change为奇数时
			 * 假设while中只有这两句话，按理说不管执行多少次，a[l]的实际值应当总是0，即invert一次
			 * 但是如果改成上面的写法，每一次循环a[l]的值都会改变一次，这显然是错误的
			 * change仅起到一个标识作用，当其为奇数时表明a[l]的真实值应当在实际值的基础上进行一次invert
			 * 并不应当真的去修改它
			 * 而下面当fc==b[now]时，而是真的应当去修改a[l]
			 * 这里只要弄清change起到的只是标识作用会相对好理解一些
			 */
			if (change & 1) fc = !(a[l] - '0') + '0';
			else fc = a[l];
			
			/**
			 * 这里的细节比较难想到
			 * 当fc == b[now]时，我们之所以选择将原串首位invert，是为了将首位先转换为与目标串相同以便对一段区间进行invert然后reverse将原串首位放到目标串的now处
			 * 之所以需要先invert是因为后续需要一次reverse，而这次reverse会带一次invert，所以需要先进行一次invert抵消一下
			 * 但是如果不需要这次reverse，那么就不要进行invert
			 * 即当目标串仅剩余最后一位时，如果和原串第一位相同，那么显然是不要invert的
			 */
			if (fc == b[now])
			{
				if (now != 1)
				{
					a[l] = !(a[l] - '0') + '0';
					res[cnt++] = 1;
				}
				else break;
			}
			else 
			{
				res[cnt++] = now--;
				swap(l, r); r += offset; // 相当于对(l,r)区间进行了reverse
				++change; // 相当于对(l,r)区间进行了invert，但是采用的是懒惰求值的方式
				offset *= -1; // 当l和r处于正序时(l < r)，r的偏移量应当是-1；当处于逆序时(l>r)，r的偏移量应当为1
			}
		}

		cout << cnt;
		for (int i = 0; i < cnt; ++i) cout << ' ' << res[i];
		cout << endl;
	}
}
// 参考:https://blog.csdn.net/mrcrack/article/details/107541883