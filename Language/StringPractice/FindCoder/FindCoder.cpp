/*************************************************************************
	> File Name: FindCoder.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Tue 16 May 2017 11:25:03 PM CST
 ************************************************************************/

/*题目要求：
 请设计一个高效算法，再给定的字符串数组中，找到包含"Coder"的字符串(不区分大小写)，并将其作为一个新的数组返回。结果字符串的顺序按照"Coder"出现的次数递减排列，若两个串中"Coder"出现的次数相同，则保持他们在原数组中的位置关系。
 给定一个字符串数组A和它的大小n，请返回结果数组。保证原数组大小小于等于300,其中每个串的长度小于等于200。同时保证一定存在包含coder的字符串。
 测试样例：
 ["i am a coder","Coder Coder","Code"],3
 返回：["Coder Coder","i am a coder"]
 */
#include<iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

vector<string> findCoder(vector<string> A, int n)
{
	   vector<string> result;
        // resultInt存储对应字符串的coder数目
	    vector<int> resultInt;
        vector<string>::iterator iter = A.begin();
        for (; iter != A.end(); iter++) {
	            string s = *iter;
	            int count = 0;
	            for (int i = 0; i < s.length() && (i + 4) < s.length();) {
		                // 转换成大写方便比较
			                if (toupper(s[i]) == 'C' && toupper(s[i + 1]) == 'O' && toupper(s[i + 2]) == 'D'
					                    && toupper(s[i + 3]) == 'E' && toupper(s[i + 4]) == 'R') {
				                    count++;
				                    // 匹配到i+5
					                    i += 5;
				                }
				                else {
					                    // 未匹配i+1
						                    i += 1;
					                }
					            }
					            if (count > 0) {
						                result.push_back(*iter);
						                resultInt.push_back(count);
						            }
						        }
						        // 冒泡排序
							        bool flag = true;
						        for (int i = 0; i < result.size(); i++) {
							            if (!flag) {
								                break;
								            }
								            flag = false;
								            for (int j = 0; j < result.size() - i - 1; j++) {
									                if (resultInt[j] < resultInt[j + 1]) {
										                    int temp = resultInt[j + 1];
										                    resultInt[j + 1] = resultInt[j];
										                    resultInt[j] = temp;
										                    string tmp = result[j + 1];
										                    result[j + 1] = result[j];
										                    result[j] = tmp;
										                    flag = true;
										                }
										            }
										        }
										        return result;
										    }
										}

int main()
{

	return 0;
}
